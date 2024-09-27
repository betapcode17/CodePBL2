#pragma once
#include<iostream>
#include "book.h"
#include "customer.h"
using namespace std;
class BookNode {
public:
    Book data;
    BookNode* next;
    BookNode() : next(NULL) {} 
};

class CustomerNode {
public:
    Customer data;
    CustomerNode* next;
    CustomerNode() : next(NULL) {}
};

class LinkedList {
private:
    BookNode* bookHead;
    CustomerNode* customerHead;
public:
    LinkedList(); 
    ~LinkedList();
    void readBook(const string& fileName);
    void displayBooks(int);
    void readCustomer(const string& fileName);
    void displayCustomer();
    int length_Of_List();
    void output(int,int,const Book&);
    int find_Node(int);
    void search_Book();
    BookNode* read(string,int);
};