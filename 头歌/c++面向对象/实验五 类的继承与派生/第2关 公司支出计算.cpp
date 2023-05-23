#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//请在此处完成YearWork,MonthWorker,WeekWoker及Company类的编码
/***********begin***********/
class Employee
{
    public:
    float salary;
    float yearS;
};

class Company
{
    public:
    float salarypay();
    Employee emp[30];
};

class WeekWorker:public Employee
{
    public:
    WeekWorker(float);
    void earning();
};

class MonthWorker:public Employee
{
    public:
    MonthWorker(float);
    void earning();
};

class YearWorker:public Employee
{
    public:
    YearWorker(float);
    void earning();
};

WeekWorker::WeekWorker(float sa)
{
    salary = sa;
    earning();
}

void WeekWorker::earning()
{
    yearS = salary*52;
}

MonthWorker::MonthWorker(float sa)
{
    salary = sa;
    earning();
}

void MonthWorker::earning()
{
    yearS = salary*12;
}

YearWorker::YearWorker(float sa)
{
    salary = sa;
    earning();
}

void YearWorker::earning()
{
    yearS = salary;
}

float Company::salarypay()
{
    float total;
    for(int i = 0;i<30;i++)
    {
        total+=emp[i].yearS;
    }
    return total;
}
/************end**********/
int main() {
   Company co;
  for(int i=0;i<30;i++)
  {
     int r=rand()%3+1;
     switch (r) {
     case 1:
         co.emp[i]=WeekWorker(580);
         break;
     case 2:
         co.emp[i]=MonthWorker(2500);
         break;
     case 3:
         co.emp[i]=YearWorker(22000);
         break;
     default:
         break;
     }
  }
   cout<<"company total pay="<<co.salarypay();
   return 0;
}
