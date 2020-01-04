#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserMenager{
    int IDLoggedUser;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    int getIdNewUser();
    bool ifExistLogin(string login);

public:
    UserMenager(string usersFileName) : usersFile(usersFileName){
        IDLoggedUser = 0;
        users = usersFile.loadUsersFromFile();
    };
    void userRegistration();
    void writeAllUsers();
    void userLogin();
    void userLogout();
};

#endif

/*
+ passwordChangeOfLoggedUser() : void
+ ifUserIsLogged() : Bool
+ getIdLoggedUser() : Integer
*/
