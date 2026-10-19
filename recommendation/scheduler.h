#pragma once

#include <vector>
#include "charging_request.h"
#include "station.h"

class Scheduler {
private:
    std::vector<ChargingRequest*> queue;  
    void sortQueue();

public:
   
    void addRequest(ChargingRequest* req);

    bool removeRequest(int requestId);

    ChargingRequest* processNext(Station& station);

    void tickWaitingTimes();

    void displayQueue() const;

    int getQueueSize() const;

    void clearQueue();

    std::vector<ChargingRequest*> getRequestsForStation(int stationId) const;
};
