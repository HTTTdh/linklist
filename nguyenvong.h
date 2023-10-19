#include<iostream>
#include"Thisinh.h"
#include"Nganh.h"
#include"linklist.h"
using namespace std;
 float search(string s)
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

class NguyenVong : public ThiSinh
{
    private:
        int spt;
        string *nv;
    public:
    NguyenVong::NguyenVong() : ThiSinh()
{
    spt=0;
    this->nv = NULL;
}
NguyenVong::NguyenVong(string cccd, string name, Date date, string address, int gt, string sbd, float to, float li, float ho) 
: ThiSinh(cccd, name, date, address, gt, sbd, to, li, ho), spt(spt){
    nv = new string [spt];
    for (int i=0;i<spt;i++)
    this->nv[i] = nv[i];
}
void nhapnv(){
    cout << "Nhập số nguyện vọng ";
    cin >> spt;
    for (int i=0;i<spt;i++){
        cout << "Nhập nguyện vọng thứ " << i+1 << " " ;
        getline(cin, nv[i]);
    }
}

void setspt(int spt){
    this->spt = spt;
}

int getspt(){
    return spt;
}

void setnv(string *nv, int i){
    
}

};