#include "../include/charger.h"

Charger::Charger(int id, double p)
{
    chargerId = id;
    power = p;
    status = "AVAILABLE";
}

int Charger::getChargerId()
{
    return chargerId;
}

double Charger::getPower()
{
    return power;
}

string Charger::getStatus()
{
    return status;
}

void Charger::setStatus(string s)
{
    status = s;
}
