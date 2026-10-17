#include <string>

class ChargingSession {
private:
    int sessionId;
    int evId;
    int userId;
    int stationId;
    int chargerId;
    int reservationId;
    int requestId;

    double startSOC;
    double currentSOC;
    double targetSOC;
    double batteryCapacity; 
    double allocatedPower;  
    double energyDelivered; 

    int    chargingSteps;   
    std::string status;    
    bool   powerReleased;   

    static int nextId;

public:
    ChargingSession(int uid, int eid, int sid, int cid,
                    int resId, int reqId,
                    double startSoc, double targetSoc,
                    double batteryCap, double power);

  
    int         getSessionId()       const;
    int         getEvId()            const;
    int         getUserId()          const;
    int         getStationId()       const;
    int         getChargerId()       const;
    int         getReservationId()   const;
    int         getRequestId()       const;
    double      getStartSOC()        const;
    double      getCurrentSOC()      const;
    double      getTargetSOC()       const;
    double      getBatteryCapacity() const;
    double      getAllocatedPower()   const;
    double      getEnergyDelivered() const;
    int         getChargingSteps()   const;
    std::string getStatus()          const;
    bool        isPowerReleased()    const;

  
    void setStatus(const std::string& s);
    void setAllocatedPower(double p);
    void markPowerReleased();

    bool simulateStep();

    bool isComplete() const;
};
