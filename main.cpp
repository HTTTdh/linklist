#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "Thisinh.h"
#include "linklist.h"
#include "Nganh.h"
using namespace std;

void signin(string &name, string &sbd)
{
    fflush(stdin);
    cout << "Tên: ";
    getline(cin, name);
    name = capitalizeFirstLetter(name);
    cout << "sbd: ";
    getline(cin, sbd);
}

void TextColor(int x) // X là mã màu
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
typedef bool (*CompareFunc)(const ThiSinh &, const string &);

bool CompareByName(const ThiSinh &ts, const string &name)
{
    return (ts.getname().find(name) != string::npos);
}

bool CompareByAddress(const ThiSinh &ts, const string &address)
{
    return (ts.getaddress().find(address) != string::npos);
}

bool CompareByCCCD(const ThiSinh &ts, const string &cccd)
{
    return (ts.getcccd().find(cccd) != string::npos);
}

bool CompareBySBD(const ThiSinh &ts, const string &sbd)
{
    return (ts.getsbd().find(sbd) != string::npos);
}

bool CompareByYear(const ThiSinh &ts, const string &yearStr)
{
    int year = std::stoi(yearStr);
    return (ts.getdate().year == year);
}

bool CompareByGender(const ThiSinh &ts, const string &gender)
{
    
    return (ts.getgt().find(gender) != string::npos);
}

void DisplayFilteredData(LinkedList &list, const string &message, CompareFunc compareFunc, string compareValue)
{
    fflush(stdin);
    node *p = list.getHead();
    cout << message + ": ";
    getline(cin, compareValue);
    compareValue = capitalizeFirstLetter(compareValue);
    Form();
    while (p != nullptr)
    {
        if (compareFunc(p->data, compareValue))
        {
            p->data.display();
        }
        p = p->next;
    }
    cout << "|";
    for (int i = 0; i < 153; i++)
    {
        cout << "-";
    }
    cout << "|" << endl;
    system("pause");
}

void search_info(LinkedList &list)
{
    string value;
    string c;
    int lc;
    do
    {
        system("cls");
        cout << setw(105) << "CÁC THÔNG TIN CẦN TÌM" << endl;
        Form1();
        cout << setw(80) << "Mời nhập lựa chọn :";
        cin >> lc;
        while (lc < 0 || lc > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
            cin >> lc;
        }
        switch (lc)
        {
        case 1:
            DisplayFilteredData(list, "nhập tên bạn muốn hiển thị", CompareByName, value);
            break;
        case 2:
            DisplayFilteredData(list, "nhập địa chỉ bạn muốn hiển thị", CompareByAddress, value);
            break;
        case 3:
            DisplayFilteredData(list, "nhập những số trong cccd bạn muốn hiển thị", CompareByCCCD, value);
            break;
        case 4:
            DisplayFilteredData(list, "nhập những số có trong số báo danh mà bạn muốn hiển thị", CompareBySBD, value);
            break;
        case 5:
        {
            string yearString;
            DisplayFilteredData(list, "nhập năm sinh bạn muốn hiển thị", CompareByYear, value);
            break;
        }
        case 6:
            DisplayFilteredData(list, "Bạn muốn hiển thị giới tính nào (Nam/Nu)", CompareByGender, value);
            break;
        }
        cout << "bạn có muốn tìm kiếm thông tin tiếp hay không? (y/n) ";
        cin >> c;
    } while (c == "y" || c == "Y");
}
typedef void (*EditInfoFuncPtr)(LinkedList&, string, string);

 void edit_infor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    string New;
    int d;
    string c;
    Date date;
    int lc;
    do
    {
        system("cls");
            cout << setw(105) << "CÁC THÔNG TIN CẦN SỬA" << endl;
            Form1();
            cout << setw(80) << "Mời nhập lựa chọn :";
            cin >> lc;
        while (lc < 0 || lc > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
            cin >> lc;
        }
        switch (lc)
        {
        case 1:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại tên: ";
                cin.ignore();
                getline(cin, New);
                p->data.setname(New);
            }
            break;
        case 2:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại ngày/tháng/năm sinh: " << endl;
                cout << "Nhập ngày: ";
                cin >> date.day;
                cout << "Nhập tháng: ";
                cin >> date.month;
                cout << "Nhập năm: ";
                cin >> date.year;
                p->data.setdate(date);
            }
            break;
        case 3:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newAddress;
                cout << "Nhập địa chỉ mới: ";
                cin.ignore();
                getline(cin, newAddress);
                p->data.setaddress(newAddress);
            }
            break;
        case 4:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newCCCD;
                cout << "Nhập số CCCD mới: ";
                cin.ignore();
                getline(cin, newCCCD);
                p->data.setcccd(newCCCD);
            }
            break;
        case 5:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newgt;
                cout << "Nhập giới tính (Nam/Nu) ";
                cin >> newgt;
                p->data.setgt(newgt);
            }
            break;
        case 6:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                float newMath, newPhysics, newChemistry;
                cout << "Nhập điểm toán mới: ";
                cin >> newMath;
                cout << "Nhập điểm lý mới: ";
                cin >> newPhysics;
                cout << "Nhập điểm hóa mới: ";
                cin >> newChemistry;
                p->data.setto(newMath);
                p->data.setli(newPhysics);
                p->data.sethoa(newChemistry);
            }
            break;
        }
        cout << "bạn có muốn sửa thông tin nào nữa không?(y/n)";
        cin >> c;
    } while (c == "y" || c == "Y");
}

int main()
{
    LinkedList danhsach;
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    danhsach.docfile();
    do
    {
        system("cls");
        TextColor(4);
        cout << setw(135) << "~- QUẢN LÝ ĐIỂM THI CỦA CÁC THÍ SINH VÀO MỘT TRƯỜNG ĐẠI HỌC -~" << endl;
        TextColor(10);
        cout << setw(27);
        for (int i = 1; i <= 125; ++i)
            cout << "-";
        cout << setw(124) << "DANH SÁCH CÁC THAO TÁC";
        cout << setw(140) << "+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << setw(114) << "|   1. Thêm 1 thí sinh vào danh sách.              |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(116) << "|   2. Xoá 1 thí sinh khỏi danh sách.              |\n ";
        cout << setw(57) << "|" << setw(51) << "|" << endl;
        cout << setw(114) << "|   3. Sửa thông tin 1 thí sinh.                   |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   4. Xuất thông tin của một thí sinh.            |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   5. Tìm kiếm các thông tin của thí sinh.        |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(121) << "|   6. Danh sách các thí sinh đậu đại học.         |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(117) << "|   7. Danh sách các ngành đào tạo.                |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   8. Sắp xếp danh sách theo điểm.                |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(111) << "|   0. Thoát.                                      |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(58) << "+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << endl;
        TextColor(7);
        cout << setw(80) << "Mời nhập lựa chọn : ";
        cin >> option;
        while (option < 0 || option > 8)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
            cin >> option;
        }
        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            string c;
            do
            {
                ts.input();
                if (danhsach.ktra(ts.getcccd()) == true)
                {
                    cout << "Đã tồn tại số cccd này" << endl;
                    cout << "bạn có muốn nhập lại hay không ? (y/n) ";
                    cin >> c;
                }
                else
                {
                    danhsach.insert(ts);
                    danhsach.ghifile();
                    cout << "Đã thêm thành công\n";
                    break;
                }
                if (c == "n" || c == "N")
                {
                    cout << "Thêm không thành công\n";
                    break;
                }
            } while (c == "y" || c == "Y");
            system("pause");
            break;
        }
        case 2:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn xóa thông tin của ai:" << endl;
            signin(name, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                if (danhsach.Delete(sbd, name) == true)
                {
                    danhsach.ghifile();
                    cout << "Đã xóa thành công\n";
                }
                else
                    cout << "Không xóa được thông tin này" << endl;
            }
            else
                cout << "Không tìm thấy thông tin cần xóa" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn sửa thông tin của ai:" << endl;
            signin(name, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                edit_infor(danhsach, sbd, name);
                danhsach.ghifile();
                cout << "Đã cập nhật thông tin\n";
            }
            else
                cout << "Không tìm thấy thông tin cần sửa" << endl;
            system("pause");
            break;
        }
        case 4:
        {
            Form();
            danhsach.xuat();
            system("pause");
            break;
        }
        case 5:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn tìm kiếm thông qua thông tin gì?" << endl;
            search_info(danhsach);
            system("pause");
            break;
        }
        case 6:
        {
            danhsach.check();
            system("pause");
            break;
        }
        case 7:
        {
            mofile();
            output();
            system("pause");
            break;
        }
        case 8:
        {
            danhsach.sapxepdiem();
            danhsach.xuat();
            system("pause");
            break;
        }
        }
    } while (option != false);
}
