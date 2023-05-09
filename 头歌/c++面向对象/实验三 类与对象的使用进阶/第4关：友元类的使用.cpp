#include <iostream>
using namespace std;
//请在下面完成Time类和Date类的编写
class Time
{
    public:
    Time(int,int,int,int,int,int);
    friend class Date;
    private:
    int sec;
    int min;
    int hour;
    int day;
    int month;
    int year;
};
class Date
{
    public:
    void display(Time &t);
    private:
    int day;
    int month;
    int year;
};

Time::Time(int s,int mi,int h,int d,int mo,int y)
{
    sec = s;
    min = mi;
    hour = h;
    day = d;
    month = mo;
    year = y;
}

void Date::display(Time &t)
{
    cout<<t.hour<<':'<<t.min<<':'<<t.sec;
}

int main()
{
    int sec,min,hour,day,mon,year;
    cin>>sec>>min>>hour>>day>>mon>>year;
    Time t1(sec,min,hour,day,mon,year);
    Date d;
    d.display(t1);

}
