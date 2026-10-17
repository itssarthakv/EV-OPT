#include "../include/ev.h"

int EV::nextId = 1;

EV::EV(int uid, double capacity, double soc, double target, int urg)
    : evId(nextId++), userId(uid), batteryCapacity(capacity),
      currentSOC(soc), targetSOC(target), urgency(urg) {}

EV::EV(int id, int uid, double capacity, double soc, double target, int urg)
    : evId(id), userId(uid), batteryCapacity(capacity),
      currentSOC(soc), targetSOC(target), urgency(urg) {
    if (id >= nextId) nextId = id + 1;
}

int    EV::getEvId()            const { return evId; }
int    EV::getUserId()          const { return userId; }
double EV::getBatteryCapacity() const { return batteryCapacity; }
double EV::getCurrentSOC()      const { return currentSOC; }
double EV::getTargetSOC()       const { return targetSOC; }
int    EV::getUrgency()         const { return urgency; }

void EV::setCurrentSOC(double soc)  { currentSOC = soc; }
void EV::setTargetSOC(double soc)   { targetSOC = soc; }
