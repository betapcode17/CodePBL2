#include "Book.h"
Book::Book()
{
}

Book::~Book()
{
}

int Book::getMa_sach() const
{
    return this->ma_sach;
}

string Book::getTen_sach() const
{
    return this->ten_sach;
}

string Book::getThe_loai() const
{
    return this->the_loai;
}

string Book::getTac_gia() const
{
    return this->tac_gia;
}

int Book::getNam_xuat_ban() const
{
    return this->nam_xuat_ban;
}

int Book::getSo_luong() const
{
    return this->so_luong;
}

int Book::getGia_ban() const
{
    return this->gia_ban;
}
void Book::SetTen_sach(string newTen_sach)
{
    this->ten_sach = newTen_sach;
}

void Book::SetThe_Loai(string newThe_loai)
{
    this->the_loai = newThe_loai;
}

void Book::SetTac_Gia(string newTac_gia)
{
    this->tac_gia = newTac_gia;
}

void Book::SetNXB(int newNXB)
{
    this->nam_xuat_ban = newNXB;
}

void Book::SetSo_Luong(int newSo_Luong)
{
    this->so_luong = newSo_Luong;
}

void Book::SetGia_Ban(int newGia_Ban)
{
    this->gia_ban = newGia_Ban;
}
