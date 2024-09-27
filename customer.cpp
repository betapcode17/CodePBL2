
#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer()
{
}
Customer::~Customer()
{
}
string Customer::getHoTen()
{
    return this->ho_ten;
}
string Customer::getMaKH()
{
    return this->Ma_KH;
}
string Customer::getSdtKH()
{
    return this->sdt_KH;
}

void Customer::setHoTen(string newHoTen)
{
    this->ho_ten=newHoTen;
}

void Customer::setMaKH(string newMaKH)
{
    this->Ma_KH = newMaKH;
}

void Customer::setSdtKH(string newSDTKH)
{
    this->sdt_KH = newSDTKH;
}
