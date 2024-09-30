#include <iostream>
#include <windows.h>
#include <conio.h>
#include "HeThong.h"
using namespace std;

// --- Variables ---
string menu[] = {
    "1> San Pham ",
    "2> Khach Hang",
    "3> Thong tin",
    "4> Thong ke",
    "5> Thoat   "
};
int menuSize = sizeof(menu) / sizeof(menu[0]);

string menuSanPham[] = {
    "1> Nhap san pham ",
    "2> Quan Li san Pham"
};
int menuSanPhamSize = sizeof(menuSanPham) / sizeof(menuSanPham[0]);

string menuCRUD[] ={
    "1> Xem thong tin cua sach",
    "2> Them sach moi",
    "3> Xoa sach",
    "4> Cap nhat sach"
};
int menuCRUDSize = sizeof(menuCRUD) / sizeof(menuCRUD[0]);

string menuRead[] ={
    "1> Tim kiem thong tin sach",
    "2> Sap xep thong tin sach",
};
int menuReadSize = sizeof(menuRead) / sizeof(menuRead[0]);

string menuSearch[] ={
    "1> Tim kiem sach theo the loai",
    "2> Tim kiem sach theo ten sach",
    "3> Tim kiem sach theo tac gia",
    "4> Tim kiem sach theo nam xuat ban",
};
int menuSearchSize = sizeof(menuSearch) / sizeof(menuSearch[0]);

string menuSort[] ={
    "1> Sap xep sach theo so luong",
    "2> Sap xep sach theo so tien",
    "3> Sap xep sach theo nam xuat ban",
};
int menuSortSize = sizeof(menuSort) / sizeof(menuSort[0]);

// --- Functions ---
void thanh_sang(int x, int y, int w, int h, int b_color, string menuItems[], int currentItem) {
    setcolor(15, b_color); // Màu chữ trắng (15), màu nền tùy chọn
    for (int iy = y + 1; iy <= y + h - 1; iy++) {
        for (int ix = x + 1; ix <= x + w - 1; ix++) {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    gotoXY(x + 2, y + 1);
    cout << menuItems[currentItem]; // Hiển thị mục menu tương ứng
    
    // Reset màu trở lại màu mặc định sau khi in thanh sáng
 // Màu mặc định: chữ trắng, nền đen
}
int MENU(string menuItems[], int menuSize, int x, int y, int w, int h, int boxX, int boxY, int boxW) {
    Showcur(0);
    int t_color = 11;
    int b_color = 0;
    int b_color_sang = 14;
    int currentItem = 0;

    // Draw box for menu
    drawBox(boxX, boxY, boxW, menuSize * 3 + 4);

    // Print all menu items with default color
    for (int i = 0; i < menuSize; i++) {
        gotoXY(x + 2, y + i * 3 + 1);
        setcolor(7, 0);  // Default color
        cout << menuItems[i];
    }

    int xp = x, yp = y, xcu = xp, ycu = yp;
    bool kt = true;

    while (true) {
        if (kt == true) {
            // Reset previous item to default color
            thanh_sang(xcu, ycu, w, h, b_color, menuItems, (ycu - y) / 3);

            // Update current coordinates
            xcu = xp;
            ycu = yp;

            // Highlight new item
            thanh_sang(xcu, ycu, w, h, b_color_sang, menuItems, (yp - y) / 3);
            kt = false;
        }

        if (_kbhit()) {
            char c = _getch();
            if (c == -32) { // Arrow keys
                kt = true;
                c = _getch();
                if (c == 72) {  // Up arrow key
                    if (yp != y)
                        yp -= 3;
                    else
                        yp = y + 3 * (menuSize - 1); // Loop back to last item
                } else if (c == 80) {  // Down arrow key
                    if (yp != y + 3 * (menuSize - 1))
                        yp += 3;
                    else
                        yp = y; // Loop back to first item
                }
            } else if (c == 13) { // Enter key
                setcolor(7, 0);  // Reset color to default before executing action
                return (yp - y) / 3;  // Return the selected menu index
            } else if (c == 27) { // ESC key
                setcolor(7, 0);  // Reset color to default on ESC
                return -1;  // Exit on ESC key press
            }
        }
    }

    // Reset color to default at the end
    setcolor(7, 0);
    gotoXY(0, 30);
    return -1;
}

void ShowMenu() {
    int choice;
    bool exitFlag = false; 
    
    while (!exitFlag) {
        choice = MENU(menu, menuSize, 41, 9, 28, 2, 40, 7, 30);
        
        if (choice == 0) {  // San Pham
            bool productMenuExit = false;
            while (!productMenuExit) {
            
                int k = MENU(menuSanPham, menuSanPhamSize, 73, 9, 30, 2, 72, 7, 35);
                if (k == 0) {
                    // Xử lý Nhap san pham
                    _getch();  
                } else if (k == 1) {
                    bool crudMenuExit = false;
                    while (!crudMenuExit) {
                        system("cls");
                        int i = MENU(menuCRUD, menuCRUDSize, 41, 9, 30, 2, 40, 7, 40);
                        
                        if (i == 0) { // "Xem thong tin cua sach"
                            bool readMenuExit = false;
                            while (!readMenuExit) {
                                system("cls");
                                int b = MENU(menuRead, menuReadSize, 41, 9, 30, 2, 40, 7, 40);
                                if (b == 0) {
                                    // Xử lý Tim kiem sach
                                    bool searchMenuExit = false;
                                    while (!searchMenuExit) {
                                        system("cls");
                                        int s = MENU(menuSearch, menuSearchSize, 41, 9, 30, 2, 40, 7, 40);
                                        if (s == 0) {
                                            // Xử lý Tim kiem sach theo the loai
                                        } else if (s == 1) {
                                            // Xử lý Tim kiem sach theo ten sach
                                        } else if (s == 2) {
                                            // Xử lý Tim kiem sach theo tac gia
                                        } else if (s == 3) {
                                            // Xử lý Tim kiem sach theo nam xuat ban
                                        } else if (_getch() == 27) {
                                            searchMenuExit = true; // Thoát menu Search
                                        }
                                    }
                                } else if (b == 1) {
                                    bool sortMenuExit = false;
                                    while (!sortMenuExit) {
                                        system("cls");
                                        int s = MENU(menuSort, menuSortSize, 41, 9, 30, 2, 40, 7, 40);
                                        if (s == 0) {
                                            // Xử lý Sap xep sach theo so luong
                                        } else if (s == 1) {
                                            // Xử lý Sap xep sach theo so tien
                                        } else if (s == 2) {
                                            // Xử lý Sap xep sach theo nam xuat ban
                                        } else if (setKeyBoard()== 5) {
                                            sortMenuExit = true; // Thoát menu Sort
                                        }
                                    }
                                } else if (setKeyBoard()==5) {
                                    readMenuExit = true; // Thoát menu Read
                                }
                            }
                        } else if (setKeyBoard()==5) {
                            crudMenuExit = true;
							system("cls"); // Thoát menu CRUD
                        }
                    }
                } else if (setKeyBoard()==5) {
                    productMenuExit = true; // Thoát menu San Pham
                }
            }
        } else if (setKeyBoard()==5) {
            exitFlag = true; // Thoát menu chính
        }
    }
}
