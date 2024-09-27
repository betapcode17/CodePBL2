#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>
#include "list.h"
#include "customer.h"
using namespace std;
void LinkedList::readCustomer(const string& fileName) {
    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "Could not open the file " << fileName << endl;
        return;
    }

    int n;  // Số lượng khách hàng
    infile >> n;
    infile.ignore();  // Bỏ qua ký tự xuống dòng sau số lượng khách hàng

    CustomerNode* temp = nullptr;

    for (int i = 0; i < n; ++i) {
        CustomerNode* newNode = new CustomerNode();

        // Đọc dữ liệu của khách hàng từ file
        getline(infile, newNode->data.Ma_KH, '|');
        getline(infile, newNode->data.ho_ten, '|');
        getline(infile, newNode->data.sdt_KH, '|');
        infile.ignore();  
        newNode->next = NULL;

        if (customerHead == NULL) {
            customerHead = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;  
    }

    infile.close();  
}

void LinkedList::displayCustomer() {
    CustomerNode* temp = customerHead;


    if (temp == NULL) {
        cout << "DANH SACH" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data.getMaKH() <<"\t"
             << temp->data.getHoTen() <<"\t"
             << temp->data.getSdtKH() <<"   OK  " << endl;


        temp = temp->next;  
    }
}
int main(){
    LinkedList List;
   List.readCustomer("customer.txt");
   List.displayCustomer();
}