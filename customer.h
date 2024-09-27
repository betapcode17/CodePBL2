#pragma once
#include <iostream>
using namespace std;
class Customer {
private:
    string ho_ten, Ma_KH, sdt_KH;
public:
    Customer();
    ~Customer();
    string getHoTen();
    string getMaKH();
    string getSdtKH();
    void setHoTen(string);
    void setMaKH(string);
    void setSdtKH(string);
    // Friend class can access private members
    friend class LinkedList;
};