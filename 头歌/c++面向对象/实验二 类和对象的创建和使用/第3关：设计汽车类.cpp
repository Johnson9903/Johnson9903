#include <iostream>
#include <cstring>
using namespace std;

/********* Begin *********/
//在此处实现一个汽车类
class Car
{
    public:
    void DoorOn();
    void DoorOff();
    void LightOn();
    void LightOff();
    void SpeedUp();
    void SpeedDown();
    void PrintAll();
    private:
    string Door;
    string Light;
    double Speed = 0;
};
void Car::DoorOn()
{
    Door = "ON";
}
void Car::DoorOff()
{
    Door = "OFF";
}
void Car::LightOn()
{
    Light = "ON";
}
void Car::LightOff()
{
    Light = "OFF";
}
void Car::SpeedUp()
{
    Speed+=10;
}
void Car::SpeedDown()
{
    Speed-=10;
}
void Car::PrintAll()
{
    cout<<"车门 "<<Door<<endl<<"车灯 "<<Light<<endl<<"速度 "<<Speed;
}
/********* End *********/

int main()
{
    /********* Begin *********/
    //在此处解析执行输出汽车的整体状态
	char cmds[25];
    cin>>cmds;
    Car car;
    for(int i = 0;i<25;i++)
    {
        if(cmds[i] == '1')
        {
            car.DoorOn();
        }else if(cmds[i] == '2')
        {
            car.DoorOff();
        }else if(cmds[i] == '3')
        {
            car.LightOn();
        }else if(cmds[i] == '4')
        {
            car.LightOff();
        }else if(cmds[i] == '5')
        {
            car.SpeedUp();
        }else if(cmds[i] == '6')
        {
            car.SpeedDown();
        }
    }
    car.PrintAll();
    
    
    /********* End *********/
}