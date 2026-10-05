#include "../include/User.h"

User::User(int id, string n, string e)
{
    userId = id;
    name = n;
    email = e;
}

int User::getUserId()
{
    return userId;
}

string User::getName()
{
    return name;
}

string User::getEmail()
{
    return email;
}
