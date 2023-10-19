#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Nganhdaotao
{
    string TenNganh;
    string MaNganh;
    float DiemChuan;
    Nganhdaotao *next;
};

Nganhdaotao *pHead = NULL;

void insertnganh(Nganhdaotao *p)
{
    if (pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        Nganhdaotao *temp = pHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void mofile()
{
    ifstream inputfile;
    inputfile.open("nganhdaotao.txt", ios::in);
    if (inputfile.is_open())
    {
        string line;
        while (getline(inputfile, line))
        {
            Nganhdaotao *p = new Nganhdaotao;

            size_t pos = line.find(",");
            p->TenNganh = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            p->MaNganh = line.substr(0, pos);
            line.erase(0, pos + 1);

            p->DiemChuan = stof(line);

            p->next = NULL;
            insertnganh(p);
        }
        inputfile.close();
    }
    else
    {
        cout << "Không thể mở file." << endl;
    }
}

void output()
{
    Nganhdaotao *temp = pHead;

    cout << setw(100) << "DANH SÁCH CÁC NGÀNH ĐÀO TẠO" << endl;
    cout << setw(41) << "+";
    for (int i = 0; i < 87; i++)
        cout << "-";
    cout << "+" << endl;
    cout <<setw(41) << "|" << setw(25) << "Tên Ngành" << setw(16) << "|";
    cout << setw(19) << "Mã Ngành" << setw(11) << "|";
    cout << setw(20) << "Điểm Chuẩn" << setw(6) << "|" << endl;

    while (temp != NULL)
    {
        cout <<setw(41) << "|";
        for (int i = 0; i < 87; i++)
            cout << "-";
        cout << "|" << endl;
        cout << setw(41) << "|"  << temp->TenNganh << setw(39-(temp->TenNganh).length()) << "|";
        cout <<setw(16) << temp->MaNganh << setw(12) << "|";
        cout <<setw(12) << temp->DiemChuan << setw(9) << "|" << endl;
        temp = temp->next;
    }

    cout<< setw(41) << "|";
    for (int i = 0; i < 87; i++)
        cout << "-";
    cout << "|" << endl;
}
string capitalizeFirstLetter(string str) {
    int len = str.length();
    if (len == 0 || str[0] == ' ') {
        return str;
    }
    str[0] = toupper(str[0]);
    for (int i = 1; i < len; i++) {
        if (str[i] == ' ' && isalpha(str[i + 1])) {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    return str;
}
 