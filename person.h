#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
#include"date.h"
using namespace std;
class Person
{
protected:
    string cccd;
    string name;
    Date date;
    string address;
    int gt;

public:
    Person();
    Person(string cccd, string name, Date date, string address, int gt);
    void setcccd(string cccd);
    string getcccd();
    void setname(string name);
    string getname();
    void setdate(Date date);
    Date getdate();
    void setaddress(string address);
    string getaddress();
    void setgt(int gt);
    int getgt();
    void nhapthongtin();
};

Person::Person()
{
    cccd = "";
    name = "";
    date.day = 0;
    date.month = 0;
    date.year = 0;
    address = "";
    gt = 0;
}
Person::Person(string cccd, string name, Date date, string address, int gt) : cccd(cccd), name(name), date(date), address(address), gt(gt){};
void Person::setcccd(string cccd)
{
    this->cccd = cccd;
}
string Person::getcccd()
{
    return cccd;
}
void Person::setname(string name)
{
    this->name = name;
}
string Person::getname()
{
    return name;
}
void Person::setdate(Date date)
{
    this->date.day = date.day;
    this->date.month = date.month;
    this->date.year = date.year;
}
Date Person::getdate()
{
    return date;
}
void Person::setaddress(string address)
{
    this->address = address;
}
string Person::getaddress()
{
    return address;
}
void Person::setgt(int gt)
{
    this->gt = gt;
}
int Person::getgt()
{
    return gt;
}
void Person::nhapthongtin()
{
    fflush(stdin);
    cout << "Nhập họ tên: ";
    getline(cin, name);
    cout << "Nhập số cccd: ";
    getline(cin, cccd);
    cout << "Nhập ngày sinh: ";
    cin >> date.day;
    cout << "Nhập tháng sinh: ";
    cin >> date.month;
    cout << "Nhập năm sinh: ";
    cin >> date.year;
    cin.ignore(1);
    cout << "Nhập địa chỉ (chỉ nhập tỉnh): ";
    getline(cin, address);
    cout << "Nhập giới tính (0: Nam, 1: Nữ): ";
    cin >> gt;
}