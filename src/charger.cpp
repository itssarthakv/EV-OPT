
#include "../include/charger.h"

Charger::Charger(int id, double p, double cost)
    : chargerId(id), power(p), costPerKWh(cost), status("AVAILABLE") {}

int         Charger::getChargerId()  const { return chargerId; }
double      Charger::getPower()      const { return power; }
double      Charger::getCostPerKWh() const { return costPerKWh; }
std::string Charger::getStatus()     const { return status; }

void Charger::setStatus(const std::string& s) { status = s; }
