#pragma once
#include <string>

class Charger {
private:
    int    chargerId;
    double power;           
    double costPerKWh;      
    std::string status;     

public:
    Charger(int id, double p, double cost);

    int         getChargerId()  const;
    double      getPower()      const;
    double      getCostPerKWh() const;
    std::string getStatus()     const;

    void setStatus(const std::string& s);
};
