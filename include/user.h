#ifndef USER_H
#define USER_H

#include<string>
using namespace std;
class User
{
private:
    int userId;
    string name;
    string email;

public:
    User(int id, string n, string e);

    int getUserId();
    string getName();
    string getEmail();
};

#endif
