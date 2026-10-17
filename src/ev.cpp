#include "../include/ev.h"

EV::EV(int id, int uid, string location, string dest,
       double capacity, double soc, double target)
{
    evId = id;
    userId = uid;

    currentLocation = location;
    destination = dest;

    batteryCapacity = capacity;
    currentSOC = soc;
    targetSOC = target;
}

int EV::getEvId()
{
    return evId;
}

int EV::getUserId()
{
    return userId;
}

string EV::getCurrentLocation()
{
    return currentLocation;
}

string EV::getDestination()
{
    return destination;
}

double EV::getBatteryCapacity()
{
    return batteryCapacity;
}

double EV::getCurrentSOC()
{
    return currentSOC;
}

double EV::getTargetSOC()
{
    return targetSOC;
}
