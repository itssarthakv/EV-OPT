#include "../include/charging_request.h"

ChargingRequest::ChargingRequest(int rid, int eid, int sid,
                                 double soc, double target,
                                 int urgent)
{
    requestId = rid;
    evId = eid;
    stationId = sid;

    currentSOC = soc;
    targetSOC = target;

    urgency = urgent;
    waitingTime = 0;
}

int ChargingRequest::getRequestId()
{
    return requestId;
}

int ChargingRequest::getEvId()
{
    return evId;
}

int ChargingRequest::getStationId()
{
    return stationId;
}

double ChargingRequest::getCurrentSOC()
{
    return currentSOC;
}

double ChargingRequest::getTargetSOC()
{
    return targetSOC;
}

int ChargingRequest::getUrgency()
{
    return urgency;
}

int ChargingRequest::getWaitingTime()
{
    return waitingTime;
}

void ChargingRequest::setWaitingTime(int time)
{
    waitingTime = time;
}
