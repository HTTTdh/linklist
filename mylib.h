#pragma once // tránh d?ng d? thu vi?n khi g?i ch?ng file lên nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thu vi?n h? tr? v? th?i gian th?c */
#include "windows.h" // thu vi?n này bá d?o l?m nhé - ch?a nhi?u d? choi nek - c? tìm hi?u d?n d?n s
//======= l?y t?a d? x c?a con tr? hi?n t?i =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= l?y t?a d? y c?a con tr? hi?n t?i =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== d?ch con tr? hi?n t?i d?n di?m có t?a d? (x,y) ==========
void gotoXY(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= d?t màu cho ch? =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ?n tr? chu?t ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= tr? v? mã phím ngu?i dùng b?m =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void SetColor1(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void textbackground(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    // Xóa các cờ màu nền cũ
    consoleInfo.wAttributes &= 0xFF0F;

    // Đặt màu nền mới
    consoleInfo.wAttributes |= (color << 4); 
    SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
}
void draw(int a,int b,int c, int d){

	   gotoXY(a,b);for (int i=a;i<=c;i++) {textcolor(8);std::cout <<  char(196);}

	   gotoXY(a,d);for (int i=a;i<=c;i++) {textcolor(8);std::cout <<  char(196);}
	   for (int i=1;i<=d-b;i++) {textcolor(8);gotoXY(a-1,b+i);std::cout << char(179) << std::endl;}
	   for (int i=1;i<=d-b;i++) {textcolor(8);gotoXY(c+1,b+i);std::cout << char(179) << std::endl;}
}
void draw1(int a,int b,int c, int d){
	   gotoXY(a,b);for (int i=a;i<=c;i++) {textcolor(0);std::cout <<  char(196);}

	   gotoXY(a,d);for (int i=a;i<=c;i++) {textcolor(0);std::cout <<  char(196);}
	   for (int i=1;i<=d-b;i++) {textcolor(0);gotoXY(a-1,b+i);std::cout << char(179) << std::endl;}
	   for (int i=1;i<=d-b;i++) {textcolor(0);gotoXY(c+1,b+i);std::cout << char(179) << std::endl;}
       for (int i = b + 1; i < d; i++) {
        for (int j = a + 1; j < c; j++) {
            textcolor(0);
            textbackground(9); 
            gotoXY(j, i);
            std::cout << ' ';
        }
    }
}
