#include "../include/charging_session.h"

int ChargingSession::nextId = 1;

ChargingSession::ChargingSession(int uid, int eid, int sid, int cid,
                                 int resId, int reqId,
                                 double startSoc, double targetSoc,
                                 double batteryCap, double power)
    : sessionId(nextId++), userId(uid), evId(eid), stationId(sid),
      chargerId(cid), reservationId(resId), requestId(reqId),
      startSOC(startSoc), currentSOC(startSoc), targetSOC(targetSoc),
      batteryCapacity(batteryCap), allocatedPower(power),
      energyDelivered(0.0), chargingSteps(0), status("WAITING"),
      powerReleased(false) {}

int         ChargingSession::getSessionId()       const { return sessionId; }
int         ChargingSession::getEvId()            const { return evId; }
int         ChargingSession::getUserId()          const { return userId; }
int         ChargingSession::getStationId()       const { return stationId; }
int         ChargingSession::getChargerId()       const { return chargerId; }
int         ChargingSession::getReservationId()   const { return reservationId; }
int         ChargingSession::getRequestId()       const { return requestId; }
double      ChargingSession::getStartSOC()        const { return startSOC; }
double      ChargingSession::getCurrentSOC()      const { return currentSOC; }
double      ChargingSession::getTargetSOC()       const { return targetSOC; }
double      ChargingSession::getBatteryCapacity() const { return batteryCapacity; }
double      ChargingSession::getAllocatedPower()   const { return allocatedPower; }
double      ChargingSession::getEnergyDelivered() const { return energyDelivered; }
int         ChargingSession::getChargingSteps()   const { return chargingSteps; }
std::string ChargingSession::getStatus()          const { return status; }
bool        ChargingSession::isPowerReleased()    const { return powerReleased; }

void ChargingSession::setStatus(const std::string& s)  { status = s; }
void ChargingSession::setAllocatedPower(double p)       { allocatedPower = p; }
void ChargingSession::markPowerReleased()              { powerReleased = true; }

bool ChargingSession::simulateStep() {
    if (status == "COMPLETED" || status == "CANCELLED")
        return false;

    status = "CHARGING";
    ++chargingSteps;

    double socIncrease = (allocatedPower / batteryCapacity) * 10.0;
    currentSOC += socIncrease;
    energyDelivered += allocatedPower * 0.1;

    if (currentSOC >= targetSOC) {
        currentSOC = targetSOC;
        status = "COMPLETED";
        return false;   
    }
    return true;
}

bool ChargingSession::isComplete() const {
    return status == "COMPLETED";
}
