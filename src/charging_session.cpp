#include "../include/charging_session.h"

ChargingSession::ChargingSession(int sid, int eid, int stid, int cid,
                                 double start, double target)
{
    sessionId = sid;
    evId = eid;
    stationId = stid;
    chargerId = cid;

    startSOC = start;
    targetSOC = target;

    energyDelivered = 0.0;

    status = "NOT_STARTED";
}

int ChargingSession::getSessionId()
{
    return sessionId;
}

int ChargingSession::getEvId()
{
    return evId;
}

int ChargingSession::getStationId()
{
    return stationId;
}

int ChargingSession::getChargerId()
{
    return chargerId;
}

double ChargingSession::getStartSOC()
{
    return startSOC;
}

double ChargingSession::getTargetSOC()
{
    return targetSOC;
}

double ChargingSession::getEnergyDelivered()
{
    return energyDelivered;
}

string ChargingSession::getStatus()
{
    return status;
}

void ChargingSession::setEnergyDelivered(double energy)
{
    energyDelivered = energy;
}

void ChargingSession::setStatus(string newStatus)
{
    status = newStatus;
}
