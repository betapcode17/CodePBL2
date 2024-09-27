#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <string.h>
#include "HeThong.h"
#include "linkedlist.h"

using namespace std;
   LinkedList :: LinkedList(){
     bookHead=NULL;
    customerHead=NULL;
   }
    LinkedList :: ~LinkedList() {
        // Clean up Book list
        BookNode* bookCurrent = bookHead;
        while (bookCurrent != NULL) {
            BookNode* bookNext = bookCurrent->next;
            delete bookCurrent;
            bookCurrent = bookNext;
        }
        
        // Clean up Customer list
        CustomerNode* customerCurrent = customerHead;
        while (customerCurrent != NULL) {
            CustomerNode* customerNext = customerCurrent->next;
            delete customerCurrent;
            customerCurrent = customerNext;
        }
    }
    int LinkedList::length_Of_List()
{
	int lenght = 0;
	BookNode* temp = this->bookHead;
	for (temp; temp != NULL; temp = temp->next)
	{
		++lenght;
	}
	return lenght;
}
void LinkedList::output(int x, int y, const Book& book)
{
    gotoXY(x+3, y+1);
    cout << book.getMa_sach();
    gotoXY(x+15, y+1);
    cout << book.getTen_sach();
    gotoXY(x+35, y+1);
    cout << book.getThe_loai();
    gotoXY(x+55, y+1);
    cout << book.getTac_gia();
    gotoXY(x+76, y+1);
    cout << book.getNam_xuat_ban();
    gotoXY(x+95, y+1);
    cout <<book.getSo_luong();
      gotoXY(x + 102, y+1);
    cout <<book.getGia_ban();
}

// Định nghĩa hàm đọc sách từ file
void LinkedList::readBook(const string& fileName) {
    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "Could not open the file " << fileName << endl;
        return;
    }

    int n;  // Số lượng sách
    infile >> n;
    infile.ignore();  // Bỏ qua ký tự xuống dòng sau số lượng sách

    BookNode* temp = nullptr;

    for (int i = 0; i < n; ++i) {
        BookNode* newNode = new BookNode();
        infile >> newNode->data.ma_sach;
        infile.ignore(1, '|');
        getline(infile, newNode->data.ten_sach, '|');
        getline(infile, newNode->data.the_loai, '|');
        getline(infile, newNode->data.tac_gia, '|');
        infile >> newNode->data.so_luong;
        infile.ignore(1, '|');  // Skip the '|' after so_luong
        infile >> newNode->data.gia_ban;
        infile.ignore(1, '|');  // Skip the '|' after gia_ban
        infile >> newNode->data.nam_xuat_ban;  // Read the year of publication
        infile.ignore();  // Skip the newline character at the end of the line
        newNode->next = NULL;

        if (bookHead == NULL) {
            // Nếu danh sách rỗng, node mới trở thành đầu danh sách
            bookHead = newNode;
        } else {
            // Liên kết node mới vào cuối danh sách
            temp->next = newNode;
        }

        temp = newNode;  // Cập nhật temp để trỏ đến node cuối
    }

    infile.close();  // Đóng file
}
int length(BookNode* book) {
    int length = 0;
    int sum;
    while (book != nullptr) {
        ++length;
        book = book->next;
    }
    if (length % 10 == 0) {
        sum = length / 10;
    } else {
        sum = length / 10 + 1;
    }
    return sum;
}
   void LinkedList::displayBooks(int x) {
    int sum;
    BookNode* temp = nullptr;
    const wchar_t* name = L"[ THÔNG TIN SÁCH ]";

    if (x == 2) name = L"[ THÔNG TIN SÁCH TÌM KIẾM THEO TÊN SÁCH ]";
    else if (x == 3) name = L"[ THÔNG TIN SÁCH TÌM KIẾM THEO THỂ LOẠI ]";
    else if (x == 4) name = L"[ THÔNG TIN SÁCH TÌM KIẾM THEO TÁC GIẢ ]";

    if (x == 2) { 
        temp = this->read("B", 1); 
        sum = length(temp); 
    } 
    else if (x == 3) { 
        temp = this->read("B", 2); 
        sum = length(temp); 
    } 
    else if (x == 4) { 
        temp = this->read("B", 3); 
        sum = length(temp); 
    } 
    else {
        temp = bookHead;
        if (this->length_Of_List() % 10 == 0) {
            sum = this->length_Of_List() / 10;
        } else {
            sum = this->length_Of_List() / 10 + 1;
        }
    }

    BookNode** first = new BookNode*[sum]; // Lưu node đầu trang
    int a = 0, page = 1, tam = 0;

    system("cls");  // Xóa màn hình trước khi hiển thị
    writeString(2, 2, name); 
    menuDisplay(2, 4, 23, page, sum);  // In tiêu đề trang sách
while (tam == 0) {
		while (temp != NULL) {
			for (int i = 1; i <= 10; i++) {
				if (temp != NULL) {
					a = a + 2;
					output(2, a + 4, temp->data);
					if (a == 2) { first[page] = temp; }
					temp = temp->next;
				}
			}
			if (setKeyBoard() == 4 && temp != NULL) //ấn qua phải
			{
				system("cls");
				writeString(2, 2, name);
				page++;
				menuDisplay(2, 4, 23, page, sum);
				a = 0;
			}
			else if (setKeyBoard() == 3 && temp != NULL && page - 1 > 0)//ấn qua trái
			{
				system("cls");
				writeString(2, 2, name);
				page--;
				menuDisplay(2, 4, 23, page, sum);
				temp = first[page];
				a = 0;
			}
			else if (setKeyBoard() == 4 && temp == NULL) { break; } //ấn qua phải ở trang cuối
			else if (setKeyBoard() == 3 && page - 1 <= 0) { break; } //ấn qua trái ở trang đầu
			else if (setKeyBoard() == 5) { system("cls"); tam = 1; break; }//thoát
			else if (setKeyBoard() == 1 || setKeyBoard() == 2) {
				a = 0;
				system("cls");
				writeString(2, 2, name);
				menuDisplay(2, 4, 23, page, sum);
				temp = first[page];
			}
		}
		if (tam == 0) {
			int thu = 0;
			while (true) {
				if (setKeyBoard() == 5) {
					system("cls");
					tam = 1;
					break;
				}
				else if (setKeyBoard() == 3 && page == sum &&page!=1) {
					system("cls");
					writeString(2, 2, name);
					menuDisplay(2, 4, 23, sum - 1, sum);
					page--;
					temp = first[sum - 1];
					a = 0;
					break;
				}
				else if (setKeyBoard() == 3 && page == 1 &&page!=sum) {
					while (true) {
						if (setKeyBoard() == 4) {
							system("cls");
							writeString(2, 2, name);
							menuDisplay(2, 4, 23, 2, sum);
							page = 2;
							if (first[page]->data.ma_sach == 0) { thu = 1; }
							else temp = first[2];
							a = 0;
							break;
						}
						else if (setKeyBoard() == 5) {
							system("cls");
							tam = 1;
							break;
						}
					}
				}
				break;
			}
			if (thu == 1) { continue; }
		}
	}
}
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
        getline(infile, newNode->data.ho_ten, '|');
        getline(infile, newNode->data.Ma_KH, '|');
        getline(infile, newNode->data.sdt_KH);
        newNode->next = NULL;

        if (customerHead == NULL) {
            // Nếu danh sách rỗng, node mới trở thành đầu danh sách
            customerHead = newNode;
        } else {
            // Liên kết node mới vào cuối danh sách
            temp->next = newNode;
        }

        temp = newNode;  // Cập nhật temp để trỏ đến node cuối
    }

    infile.close();  // Đóng file
}
void LinkedList::displayCustomer() {
    CustomerNode* temp = customerHead;

    if (temp == NULL) {
        cout << "Danh sách khách hàng hiện đang rỗng." << endl;
        return;
    }

    // Print the table header
    cout << left << setw(25) << "Ho Ten" 
         << setw(15) << "Ma KH"
         << setw(15) << "SDT KH" << endl;

    cout << "---------------------------------------------------" << endl;

    // Print the customer details in table format
    while (temp != NULL) {
        cout << left << setw(25) << temp->data.ho_ten
             << setw(15) << temp->data.Ma_KH
             << setw(15) << temp->data.sdt_KH<< endl;

        temp = temp->next;  // Move to the next customer in the list
    }
}
// Tìm kiếm theo tên sách,thể loại,tên,tác giả
int LinkedList::find_Node(int i)
{
    // Tìm kiếm theo thể loại,tên,tác giả 
    BookNode* temp = this->bookHead;
    int position = 1;
    for(temp; temp!=NULL; temp = temp->next){
        if((temp->data.ma_sach !=i)){
            return position;
        }
        ++position;
    }
    return -1;
}
BookNode* LinkedList::read(string str, int i) {
    BookNode* newBook = nullptr;  // Head of the new list
    BookNode* tail = nullptr;     // Tail pointer to append nodes
    BookNode* temp = this->bookHead;

    // Iterate through the linked list
    while (temp != nullptr) {
        bool match = false;  // Flag to track if a match is found

        // Determine what to search based on the value of i
        if (i == 1 && temp->data.ten_sach.find(str) != string::npos) {
            match = true;  // Search in `ten_sach`
        } else if (i == 2 && temp->data.the_loai.find(str) != string::npos) {
            match = true;  // Search in `the_loai`
        } else if (i == 3 && temp->data.tac_gia.find(str) != string::npos) {
            match = true;  // Search in `tac_gia`
        }

        // If a match is found, create a new node
        if (match) {
            BookNode* newNode = new BookNode;
            newNode->data = temp->data;
            newNode->next = nullptr;

            // Append to the list
            if (newBook == nullptr) {
                newBook = newNode;  // Set as head
                tail = newNode;     // Set as tail
            } else {
                tail->next = newNode;
                tail = newNode;     // Move the tail to the last node
            }
        }

        // Move to the next node
        temp = temp->next;
    }

    // Return the newBook list containing matched books
    return newBook;
}
