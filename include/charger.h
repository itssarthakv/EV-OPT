#ifndef CHARGER_H
#define CHARGER_H

#include <string>
using namespace std;

class Charger
{
private:
    int chargerId;
    double power;
    string status;

public:
    Charger(int id, double p);

    int getChargerId();
    double getPower();
    string getStatus();

    void setStatus(string s);
};

#endif
