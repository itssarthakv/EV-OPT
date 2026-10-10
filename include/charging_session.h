#ifndef CHARGING_SESSION_H
#define CHARGING_SESSION_H

#include <string>

using namespace std;

class ChargingSession
{
private:
    int sessionId;
    int evId;
    int stationId;
    int chargerId;

    double startSOC;
    double targetSOC;
    double energyDelivered;

    string status;

public:
    ChargingSession(int sid, int eid, int stid, int cid,
                    double start, double target);

    int getSessionId();
    int getEvId();
    int getStationId();
    int getChargerId();

    double getStartSOC();
    double getTargetSOC();
    double getEnergyDelivered();

    string getStatus();

    void setEnergyDelivered(double energy);
    void setStatus(string newStatus);
};

#endif
