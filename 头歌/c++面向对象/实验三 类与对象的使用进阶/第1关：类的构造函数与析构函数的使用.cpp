#include<iostream>
using namespace std;
//Box类的定义及成员函数书写
//***begin***
   class Box{
     public:
     Box();
     Box(float,float,float);
     double getVolume();
     private:
     float length;
     float width;
     float height; 
   };
   Box::Box(float len = 0,float wid = 0,float hei = 0)
   {
     length = len;
     width = wid;
     height = hei;
   }
   double Box::getVolume()
   {
     double volume;
     volume = length*width*height;
     return volume;
   }
//***end***
int main(int argc, char *argv[])
{
  Box b1(4);
  Box b2(4,5);
  Box b3(4,10,8);
  cout<<b1.getVolume()<<","<<b2.getVolume()<<","<<b3.getVolume();
}
 