#pragma once


#include <string>
#include <vector>
#include "charger.h"

class Station {
private:
    int    stationId;
    std::string name;
    std::string location;       
    double powerCapacity;      
    double allocatedPower;      

    std::vector<Charger> chargers;

    static int nextId;

public:
    Station(int id, const std::string& n, const std::string& loc,
            double capacity);

   
    int         getStationId()        const;
    std::string getName()             const;
    std::string getLocation()         const;
    double      getPowerCapacity()    const;
    double      getAllocatedPower()    const;
    double      getAvailablePower()   const;  
    int         getChargerCount()     const;
    int         getAvailableChargerCount() const;

   
    void     addCharger(const Charger& c);
    std::vector<Charger>&       getChargers();
    const std::vector<Charger>& getChargers() const;
    Charger* findAvailableCharger();         
    Charger* findChargerById(int id);


    bool allocatePower(double amount);         
    void releasePower(double amount);
    void setPowerCapacity(double capacity);
    void resetPowerAllocation();


    void displayChargers() const;
    void displayInfo()     const;
};
