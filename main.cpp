#include <iostream>
#include "list.h"
#include "Book.h"
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>
LinkedList listBook;
using namespace std;
void Start()
{
    listBook.readBook("books.txt");
    listBook.displayBooks();
}
int main() {
     system("cls");
    Start();
}
