#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
using namespace std;
class Book {
private:
    string  ten_sach, the_loai, tac_gia;
    int ma_sach,so_luong, gia_ban,nam_xuat_ban;
public:
    Book();
    ~Book();
    int getMa_sach()const;
    string getTen_sach()const;
    string getThe_loai()const;
    string getTac_gia()const;
    int getNam_xuat_ban()const;
    int getSo_luong()const;
    int getGia_ban()const;
    void SetTen_sach(string);
    void SetThe_Loai(string);
    void SetTac_Gia(string);
    void SetNXB(int);
    void SetSo_Luong(int);
    void SetGia_Ban(int);
    // Friend class can access private members
    friend class LinkedList;
};