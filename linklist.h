#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "node.h"
#include "Nganh.h"
using namespace std;

void Form()
{
    cout << "+";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(15) << "Tên" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(15) << "Ngày Sinh" << setw(5) << "|";
    cout << setw(17) << "Địa Chỉ" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(8) << "Toán" << setw(3) << "|";
    cout << setw(6) << "Lý" << setw(3) << "|";
    cout << setw(7) << "Hóa" << setw(3) << "|";
    cout << setw(9) << "Tổng" << setw(3) << "|" << endl;
}
void Form1(){
                cout << setw(75) << "+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << setw(107) << "|   1. Tên                     |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(111) << "|   2. Địa chỉ                 |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   3. CCCD                    |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   4. SBD                     |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(108) << "|   5. Năm sinh                |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(109) << "|   6. Giới tính               |" << endl;
            cout << setw(75) << "+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << endl;
}

class LinkedList
{
public:
    node *head;
    node *tail;
    node* getHead(){
        return head;
    }
    LinkedList()
    {
        head = tail = NULL;
    }
     void insert(ThiSinh sv)
    {
        node *newNode = new node(sv);
        if (head)
        {
            tail->next=newNode;
            tail=tail->next;
        }
        else head=tail=newNode;
    }
     bool Delete(string sbd, string name)
    {
        node *p = search(sbd, name);
        if (p != NULL)
        {
            node *pre;
            node *temp = head;
            while (temp != NULL && p->data.getsbd() != temp->data.getsbd())
            {
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete (temp);
            return true;
        }
        else
            return false;
    }
     void xuat()
    {
        node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
        cout << "|";
        for (int i = 0; i < 153; i++)
            cout << "-";
        cout << "|" << endl;
    }
    node *search(string sbd, string name)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data.getsbd().find(sbd) != string::npos && temp->data.getname().find(name) != string ::npos)
                return temp;
            else
                temp = temp->next;
        }
        return NULL;
    }
    void sapxepdiem(){
    if (head == NULL)
    {
        cout << "Danh sách rỗng.";
        return;
    }

    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    bool swapped;
    node *ptr1;
    node *lptr = NULL;

    // Lặp lại quá trình sắp xếp cho đến khi không có cặp phần tử nào được tráo đổi
    for (int i = 0; i < count - 1; i++)
    {
        swapped = false;
        ptr1 = head;

        // Lặp qua tất cả các phần tử và so sánh điểm của chúng
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ptr1->data.getsum() < ptr1->next->data.getsum())
            {
                // Hoán đổi nội dung giữa hai phần tử
                ThiSinh temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }

        // Nếu không có phần tử nào được tráo đổi, thì danh sách đã được sắp xếp
        if (swapped == false)
            break;
}

    }
     bool testempty()
    {
        return (head==nullptr);
    }
    bool ktra(string cccd)
    {
        node *p = head;
        while (p != nullptr)
        {
            if (p->data.getcccd().find(cccd) != string::npos)
                return true;
            p = p->next;
        }
        return false;
    }
 
   
 void docfile();
    void ghifile();
    void check();
    
    float searchnganh(string str);
    
};
void LinkedList::docfile()
{
    ifstream inputFile;
    ThiSinh ts;
    inputFile.open("dsthisinh.txt", ios::in);
    if (inputFile.is_open())
    {
        string line;
        size_t pos;
        while (getline(inputFile, line))
        {

            pos = line.find(",");
            ts.setname(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setcccd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
           ts.setgt(line.substr(0, pos));
            line.erase(0, pos + 1);

            Date d;
            pos = line.find("/");
            d.day = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find("/");
            d.month = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(",");
            d.year = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            ts.setdate(d);

            pos = line.find(",");
            ts.setaddress(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setsbd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setto(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setli(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.sethoa(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            vector<string> tam;
            for (; line!= "\n";)
            {
                pos = line.find(",");
                tam.push_back(line.substr(0, pos));
                // ts.setnv(tam[i], i);
                line.erase(0, pos + 1);
            }

            insert(ts);
        }

        inputFile.close();
    }
    else
    {
        cout << "Không thể mở file." << endl;
    }
}
void LinkedList::ghifile()

{
    ofstream outputFile;
    outputFile.open("dsthisinh.txt", ios::out);
    if (outputFile.is_open())
    {
        node *current = head;
        while (current != NULL)
        {
            outputFile << current->data.getname() << ","
                       << current->data.getcccd() << ","
                       << current->data.getgt() << ","
                       << current->data.getdate().day << "/"
                       << current->data.getdate().month << "/"
                       << current->data.getdate().year << ","
                       << current->data.getaddress() << ","
                       << current->data.getsbd() << ","
                       << current->data.getto() << ","
                       << current->data.getli() << ","
                       << current->data.gethoa();

            for (int i = 0; i < current->data.getspt(); i++)
            {
                outputFile << "," << current->data.getnv(i);
            }

            cout << endl;
            current = current->next;
        }
        outputFile.close();
    }
    else
    {
        cout << "Không thể mở file." << endl;
    }
}
float LinkedList::searchnganh(string s)
{
    s = capitalizeFirstLetter(s);
    Nganhdaotao *p = pHead;
    while (p != NULL)
    {
        if (p->TenNganh == s)
            return p->DiemChuan;
        p = p->next;
    }
    cout << "Không có tên ngành này" << endl;
    return 0;
}


void LinkedList::check()
{
    int i = 0;
    LinkedList dsdau;
    node *temp = head;
    while (temp != NULL)
    {
        do
        {
            float dc = searchnganh(temp->data.getnv(i));
            if (dc && temp->data.getsum() > dc)
            {
                dsdau.insert(temp->data);
                break;
            }
            else if (dc)
                return;
            else
                i++;
        } while (i < temp->data.getspt());
        temp = temp->next;
    }
    dsdau.sapxepdiem();
}