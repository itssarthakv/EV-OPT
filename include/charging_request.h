#include <string>

class ChargingRequest {
private:
    int requestId;
    int evId;
    int userId;
    int stationId;

    double currentSOC;
    double targetSOC;

    int    urgency;       
    int    waitingTime;    
    double allocatedPower;  
    int    assignedChargerId; 

    std::string status;    

    static int nextId;

public:
    ChargingRequest(int uid, int eid, int sid,
                    double soc, double target, int urg);

    
    int         getRequestId()      const;
    int         getEvId()           const;
    int         getUserId()         const;
    int         getStationId()      const;
    double      getCurrentSOC()     const;
    double      getTargetSOC()      const;
    int         getUrgency()        const;
    int         getWaitingTime()    const;
    double      getAllocatedPower()  const;
    int         getAssignedChargerId() const;
    std::string getStatus()         const;


    double getPriority() const;

  
    void setWaitingTime(int t);
    void incrementWaitingTime();
    void setAllocatedPower(double p);
    void setAssignedChargerId(int cid);
    void setStatus(const std::string& s);
};
