
#include "../include/user.h"

int User::nextId = 1;
User::User(const std::string& n, const std::string& e,
           const std::string& loc, const std::string& dest)
    : userId(nextId++), name(n), email(e),
      currentLocation(loc), destination(dest) {}


User::User(int id, const std::string& n, const std::string& e,
           const std::string& loc, const std::string& dest)
    : userId(id), name(n), email(e),
      currentLocation(loc), destination(dest) {
    if (id >= nextId) nextId = id + 1;  
}

int         User::getUserId()          const { return userId; }
std::string User::getName()            const { return name; }
std::string User::getEmail()           const { return email; }
std::string User::getCurrentLocation() const { return currentLocation; }
std::string User::getDestination()     const { return destination; }

void User::setCurrentLocation(const std::string& loc) { currentLocation = loc; }
void User::setDestination(const std::string& dest)     { destination = dest; }

                                          */
bool User::isValidEmail(const std::string& email) {
    if (email.empty()) return false;
    auto at = email.find('@');
    if (at == std::string::npos || at == 0) return false;
    auto dot = email.find('.', at + 2);
    if (dot == std::string::npos) return false;
    if (email.find(' ') != std::string::npos) return false;
    return true;
}

int User::getNextId() { return nextId; }
