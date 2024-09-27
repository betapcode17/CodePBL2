#pragma once
#include <iostream>
using namespace std;
class Users {
private:
    int role;
public:
    wstring getName();
    wstring getPassword();
    int getRole() const {
        return role;
    }
    void forgot_password();
    bool login();
};