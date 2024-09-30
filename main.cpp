#include "linkedlist.h"
#include "Book.h"
#include "Users.h"
#include "HeThong.h"
#include "menu.h"
LinkedList listBook;
LinkedList listCustomer;
Users users;
using namespace std;
void Start()
{
    listBook.readBook("books.txt");
    //listBook.displayBooks(5);
    listCustomer.readCustomer("customers.txt");
}
/*void Process(){
	int login = users.login();
	system("cls");
	cout<<login<<endl;
	cout<<users.getRole();
}*/
int main() {
	//Start();
	//Process();
	//ShowMenu()
	ShowMenu();
}
