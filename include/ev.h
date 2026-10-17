#ifndef EV_H
#define EV_H

#include <string>
using namespace std;

class EV
{
private:
    int evId;
    int userId;

    string currentLocation;
    string destination;

    double batteryCapacity;
    double currentSOC;
    double targetSOC;

public:
    EV(int id, int uid, string location, string dest,
       double capacity, double soc, double target);

    int getEvId();
    int getUserId();

    string getCurrentLocation();
    string getDestination();

    double getBatteryCapacity();
    double getCurrentSOC();
    double getTargetSOC();
};

#endif
