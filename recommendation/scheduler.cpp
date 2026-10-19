
#include "scheduler.h"
#include <algorithm>
#include <iostream>

void Scheduler::sortQueue() {
    std::stable_sort(queue.begin(), queue.end(),
        [](ChargingRequest* a, ChargingRequest* b) {
            if (a == nullptr) return false;
            if (b == nullptr) return true;

            return a->getPriority() > b->getPriority();
        });
}

void Scheduler::addRequest(ChargingRequest* req) {
    if (req == nullptr) {
        return;
    }

    queue.push_back(req);
    sortQueue();
}

bool Scheduler::removeRequest(int requestId) {
    auto it = std::find_if(
        queue.begin(), queue.end(),
        [requestId](ChargingRequest* req) {
            return req != nullptr &&
                   req->getRequestId() == requestId;
        });

    if (it == queue.end()) {
        return false;
    }

    queue.erase(it);
    return true;
}

ChargingRequest* Scheduler::processNext(Station* station) {
    if (station == nullptr || queue.empty()) {
        return nullptr;
    }

    sortQueue();

    for (auto it = queue.begin(); it != queue.end(); ++it) {
        ChargingRequest* req = *it;

        if (req == nullptr) {
            continue;
        }

        if (req->getStationId() != station->getStationId()) {
            continue;
        }

        Charger* charger = station->findAvailableCharger();

        if (charger == nullptr) {
            continue;
        }

        double chargerPower = charger->getPower();
        double availablePower = station->getAvailablePower();

        if (chargerPower <= 0 || availablePower <= 0) {
            continue;
        }

        double allocatedPower =
            std::min(chargerPower, availablePower);

        if (!station->allocatePower(allocatedPower)) {
            continue;
        }

        charger->setStatus("IN_USE");

        req->setAllocatedPower(allocatedPower);
        req->setAssignedChargerId(charger->getChargerId());
        req->setStatus("PROCESSING");

        queue.erase(it);

        return req;
    }

    return nullptr;
}

void Scheduler::tickWaitingTimes() {
    for (ChargingRequest* req : queue) {
        if (req != nullptr) {
            req->incrementWaitingTime();
        }
    }

    sortQueue();
}

void Scheduler::displayQueue() const {
    if (queue.empty()) {
        std::cout << "Charging queue is empty.\n";
        return;
    }

    std::cout << "\n===== Smart Charging Queue =====\n";

    for (const ChargingRequest* req : queue) {
        if (req != nullptr) {
            std::cout << "Request ID: "
                      << req->getRequestId()
                      << " | Station ID: "
                      << req->getStationId()
                      << " | Priority: "
                      << req->getPriority()
                      << " | Waiting Time: "
                      << req->getWaitingTime()
                      << " | Status: "
                      << req->getStatus()
                      << '\n';
        }
    }
}

int Scheduler::getQueueSize() const {
    return static_cast<int>(queue.size());
}

void Scheduler::clearQueue() {
    queue.clear();
}

std::vector<ChargingRequest*>
Scheduler::getRequestsForStation(int stationId) const {
    std::vector<ChargingRequest*> result;

    for (ChargingRequest* req : queue) {
        if (req != nullptr &&
            req->getStationId() == stationId) {
            result.push_back(req);
        }
    }

    return result;
}

