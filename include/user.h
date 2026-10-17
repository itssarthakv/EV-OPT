#pragma once


#include <string>

class User {
private:
    int userId;
    std::string name;
    std::string email;
    std::string currentLocation;
    std::string destination;

    static int nextId;      

public:
    
    User(const std::string& n, const std::string& e,
         const std::string& loc = "", const std::string& dest = "");

   
    User(int id, const std::string& n, const std::string& e,
         const std::string& loc = "", const std::string& dest = "");

   
    int         getUserId()          const;
    std::string getName()            const;
    std::string getEmail()           const;
    std::string getCurrentLocation() const;
    std::string getDestination()     const;

    void setCurrentLocation(const std::string& loc);
    void setDestination(const std::string& dest);

   
    static bool isValidEmail(const std::string& email);
    static int  getNextId();
};
