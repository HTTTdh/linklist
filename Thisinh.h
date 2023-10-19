#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "person.h"
using namespace std;
class ThiSinh : public Person
{
private:
    string sbd;
    float to, li, ho;
    float sum;
    int spt;
    string *nv;

public:
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, float to, float li, float ho, int spt, string *nv);
    void setsbd(string sbd);
    string getsbd();
    void setto(float to);
    float getto();
    void setli(float li);
    float getli();
    void sethoa(float hoa);
    float gethoa();
    float getsum();
    void setspt(int spt);
    int getspt();
    void setnv(string nv, int i);
    string getnv(int i);
    void input();
    void display();
};

ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
    spt = 0;
    this->nv = NULL;
}
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, float to, float li, float ho, int spt, string *nv)
    : Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho), spt(spt)
{
    nv = new string[spt];
    for (int i = 0; i < spt; i++)
        this->nv[i] = nv[i];
};
void ThiSinh::setsbd(string sbd)
{
    this->sbd = sbd;
}
string ThiSinh::getsbd()
{
    return sbd;
}
void ThiSinh::setto(float to)
{
    this->to = to;
}
float ThiSinh::getto()
{
    return to;
}
void ThiSinh::setli(float li)
{
    this->li = li;
}
float ThiSinh::getli()
{
    return li;
}
void ThiSinh::sethoa(float hoa)
{
    this->ho = hoa;
}
float ThiSinh::gethoa()
{
    return ho;
}
float ThiSinh::getsum()
{
    return to + li + ho;
}
void ThiSinh::setspt(int spt)
{
    this->spt = spt;
}

int ThiSinh::getspt()
{
    return spt;
}

void ThiSinh::setnv(string nv, int i)
{
    this->nv[i] = nv[i];
}
string ThiSinh::getnv(int i)
{
    return nv[i];
}
void ThiSinh::input()
{
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    nhapthongtin();
    fflush(stdin);
    cout << "Nhập số báo danh: ";
    getline(cin, sbd);
    cout << "Nhập điểm toán: ";
    cin >> to;
    cout << "Nhập điểm lý: ";
    cin >> li;
    cout << "Nhập điểm hóa: ";
    cin >> ho;
    cout << "Nhập số nguyện vọng ";
    cin >> spt;
    for (int i = 0; i < spt; i++)
    {
        fflush(stdin);
        cout << "Nhập nguyện vọng thứ " << i + 1 << " ";
        getline(cin, nv[i]);
        cin.ignore(1);
    }
    cout << endl;
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
}
void ThiSinh::display()
{
    cout << "|";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "|" << endl;
    cout << "|" << getname() << setw(34 - getname().length()) << "|";
    cout << getcccd() << setw(20 - getcccd().length()) << "|";
    cout << setw(4) << getgt() << setw(4) << "|";
    cout << getdate().day << "/" << getdate().month << "/" << getdate().year << setw(19 - getdate().sizedate()) << "|";
    cout << getaddress() << setw(20 - getaddress().length()) << "|";
    cout << getsbd() << setw(16 - getsbd().length()) << "|";
    cout << setw(7) << getto() << setw(3) << "|";
    cout << setw(5) << getli() << setw(3) << "|";
    cout << setw(6) << gethoa() << setw(3) << "|";
    cout << setw(5) << getsum() << setw(5) << "|" << endl;
}
