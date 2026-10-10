#ifndef CHARGING_REQUEST_H
#define CHARGING_REQUEST_H

class ChargingRequest
{
private:
    int requestId;
    int evId;
    int stationId;

    double currentSOC;
    double targetSOC;

    int urgency;
    int waitingTime;

public:
    ChargingRequest(int rid, int eid, int sid,
                    double soc, double target,
                    int urgent);

    int getRequestId();
    int getEvId();
    int getStationId();

    double getCurrentSOC();
    double getTargetSOC();

    int getUrgency();
    int getWaitingTime();

    void setWaitingTime(int time);
};

#endif
