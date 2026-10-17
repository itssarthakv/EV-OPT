#pragma once


#include <string>

class EV {
private:
    int evId;
    int userId;             

    double batteryCapacity; 
    double currentSOC;      
    double targetSOC;      
    int    urgency;        

    static int nextId;

public:
    
    EV(int uid, double capacity, double soc, double target, int urg);

    
    EV(int id, int uid, double capacity, double soc, double target, int urg);

 
    int    getEvId()           const;
    int    getUserId()         const;
    double getBatteryCapacity()const;
    double getCurrentSOC()     const;
    double getTargetSOC()      const;
    int    getUrgency()        const;

 
    void setCurrentSOC(double soc);
    void setTargetSOC(double soc);
};
