#include <iostream>
using namespace std;

class StInfo
{
    /********* Begin *********/
    //在此处声明StInfo类
    public:
    void SetInfo(int sid,char *name,char* cla,char* phone);
    void PrintInfo();
    private:
    int SID;
    char *Name;
    char *Class;
    char *Phone;
    
    /********* End *********/
};

/********* Begin *********/
//在此处定义StInfo类
void StInfo::SetInfo(int sid,char *name,char* cla,char* phone)
{
    SID = sid;
    Name = name;
    Class = cla;
    Phone = phone;
}

void StInfo::PrintInfo()
{
    cout<<"学号："<<SID<<endl<<"姓名："<<Name<<endl<<"班级："<<Class<<endl<<"手机号："<<Phone;
}
/********* End *********/
