#include "../include/charging_request.h"

int ChargingRequest::nextId = 1;

ChargingRequest::ChargingRequest(int uid, int eid, int sid,
                                 double soc, double target, int urg)
    : requestId(nextId++), userId(uid), evId(eid), stationId(sid),
      currentSOC(soc), targetSOC(target), urgency(urg),
      waitingTime(0), allocatedPower(0.0), assignedChargerId(-1),
      status("QUEUED") {}

int         ChargingRequest::getRequestId()     const { return requestId; }
int         ChargingRequest::getEvId()          const { return evId; }
int         ChargingRequest::getUserId()        const { return userId; }
int         ChargingRequest::getStationId()     const { return stationId; }
double      ChargingRequest::getCurrentSOC()    const { return currentSOC; }
double      ChargingRequest::getTargetSOC()     const { return targetSOC; }
int         ChargingRequest::getUrgency()       const { return urgency; }
int         ChargingRequest::getWaitingTime()   const { return waitingTime; }
double      ChargingRequest::getAllocatedPower() const { return allocatedPower; }
int         ChargingRequest::getAssignedChargerId() const { return assignedChargerId; }
std::string ChargingRequest::getStatus()        const { return status; }

double ChargingRequest::getPriority() const {
    return urgency * 10.0 + waitingTime;
}

void ChargingRequest::setWaitingTime(int t)          { waitingTime = t; }
void ChargingRequest::incrementWaitingTime()          { ++waitingTime; }
void ChargingRequest::setAllocatedPower(double p)     { allocatedPower = p; }
void ChargingRequest::setAssignedChargerId(int cid)   { assignedChargerId = cid; }
void ChargingRequest::setStatus(const std::string& s) { status = s; }
