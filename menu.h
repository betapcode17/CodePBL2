#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoXY(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawBox(int x, int y, int width, int height) {
    gotoXY(x, y); cout << char(218); 
    gotoXY(x + width - 1, y); cout << char(191); 
    gotoXY(x, y + height - 1); cout << char(192); 
    gotoXY(x + width - 1, y + height - 1); cout << char(217); 

    for (int i = 1; i < width - 1; ++i) {
        gotoXY(x + i, y); cout << char(196); 
        gotoXY(x + i, y + height - 1); cout << char(196); 
    }

    for (int i = 1; i < height - 1; ++i) {
        gotoXY(x, y + i); cout << char(179); 
        gotoXY(x + width - 1, y + i); cout << char(179); 
    }
}
void setcolor(int text_color, int background_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background_color << 4) | text_color);
}

void Showcur(bool CursorVisibility) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    ConCurInf.bVisible = CursorVisibility;
    ConCurInf.dwSize = 1;
    SetConsoleCursorInfo(handle, &ConCurInf);
}

string menuItems[] = {
    "1> San Pham ",
    "2> Khach Hang",
    "3> Thong tin",
    "4> Thong ke",
    "5> Thoat   "
};
string menuBook[] = {
    "1> Nhap sach",
    "2> Quan Li sach",
    "3> Thoat"
};
string menuKH[] = {
    "1> Nhap khach hang",
    "2> Quan Li khanh hang",
    "3> Thoat"
};
const int menuSize = 5; // Số lượng mục trong menu

void Noi_dung_menu() {
    for (int i = 0; i < menuSize; i++) {
        gotoXY(43, 10 + i * 3); // Chỉnh khoảng cách giữa các mục thành 3 đơn vị
        cout << menuItems[i];
    }
}

// Hàm để in thanh sáng trên mục menu hiện tại
void thanh_sang(int x, int y, int w, int h, int b_color) {
    setcolor(15, b_color); // Màu chữ trắng (15), màu nền tùy chọn
    for (int iy = y + 1; iy <= y + h - 1; iy++) {
        for (int ix = x + 1; ix <= x + w - 1; ix++) {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
   
     In lại dòng chữ trong thanh sáng
    gotoXY(x + 2, y + 1);
    cout << menuItems[(y - 7) / 3]; // Cập nhật lại chỉ mục dựa trên khoảng cách 3 đơn vị
}

// Hàm vẽ khung cho mỗi mục trong menu
void box(int x, int y, int w, int h, int t_color, int b_color) {
    setcolor(b_color, 0); // Màu nền của khung
    for (int iy = y + 1; iy <= y + h - 1; iy++) {
        for (int ix = x + 1; ix <= x + w - 1; ix++) {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    setcolor(15, 0);
    //======== Vẽ viền =======
    setcolor(t_color, 0);
    if (h <= 1 || w <= 1) return;
    for (int ix = x; ix <= x + w; ix++) {
        gotoXY(ix, y);
        cout << char(196); // In đường ngang trên
        gotoXY(ix, y + h);
        cout << char(196); // In đường ngang dưới
    }
    for (int iy = y; iy <= y + h; iy++) {
        gotoXY(x, iy);
        cout << char(179); // In đường dọc trái
        gotoXY(x + w, iy);
        cout << char(179); // In đường dọc phải
    }
    gotoXY(x, y);
    cout << char(218); // Góc trên bên trái
    
    gotoXY(x + w, y);
    cout << char(191); // Góc trên bên phải
    
    gotoXY(x, y + h);
    cout << char(192); // Góc dưới bên trái
    
    gotoXY(x + w, y + h);
    cout << char(217); // Góc dưới bên phải
}

void Tieu_de() {
    box(41,0,43,6,14,0);
    gotoXY(51,3);
    cout << "MENU QUAN LI SACH THEO CUA HANG CHUYEN VE SACH";
    setcolor(7, 0);
}

// Hàm chính để hiển thị menu
int MENU() {
    Showcur(0);
    //-------- Thiết lập ban đầu -----
    int x = 41; // Vị trí x bắt đầu của menu
    int y = 9;  // Vị trí y bắt đầu của menu
    int w = 27;
    int h = 2;
    int t_color = 11;
    int b_color = 0;
    int b_color_sang = 014;
    string nd = "";
    int n = menuSize - 1; // Cập nhật lại số lượng mục menu
    drawBox(40, 7, 30, 20);
    Noi_dung_menu();
    
    //----------- Điều khiển thanh sáng ---------
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    bool kt = true;
    while (true) {
        if (kt == true) {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color); // Reset thanh sáng cũ
            xcu = xp;
            ycu = yp;
            thanh_sang(xcu, ycu, w, h, b_color_sang); // In thanh sáng mới
            kt = false;
        }
        
        // Điều khiển phím
        if (_kbhit()) {
            char c = _getch();
          if (c == -32) { // Phím mũi tên
    kt = true;
    c = _getch();
    if (c == 72) {  // Phím mũi tên lên
        if (yp != y) 
            yp -= 3;
        else 
            yp = y + 3 * (menuSize - 1); // Quay lại mục cuối cùng
    } else if (c == 80) {  // Phím mũi tên xuống
        if (yp != y + 3 * (menuSize - 1)) 
            yp += 3;
        else 
            yp = y; // Quay lại mục đầu tiên
    }
}
        }
    }

    // Đặt lại màu nền và màu chữ về mặc định
    setcolor(7, 0);
    gotoXY(0, 30); // Di chuyển con trỏ xuống dưới
}

int main() {
    box(41,0,43,6,14,0);
    Tieu_de();
    int x = MENU();
    setcolor(7, 0);
    _getch();
    return 0;
}
