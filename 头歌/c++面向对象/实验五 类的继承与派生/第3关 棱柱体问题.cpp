 #include <iostream>
using namespace std;
#include<string>
#include"time.h"
#include"math.h"
//亲在begin和end之间完成各个类的定义及实现
/*********begin**********/
class Plane
{
   public:
    double _area;
    double area(){return _area;}
};
class Circle:public Plane
{
   public:
   double rad;
};
class Triangle:public Plane
{
   public:
   double tang1;
   double tang2;
   double tang3;
};
class Rectangle:public Plane
{
   public:
   double length;
   double width;
};
class Square:public Rectangle
{
   public:
   double length;
};
class Body
{
   public :
   double volume();
    int num;//棱的数量,0为圆柱体
    double height;
    Plane plane;
    double _superficialarea;
    double _volume;
    double superficialarea();
};
class Circularcolumn:public Body,public Circle
{
   public:
   Circularcolumn(int,double,double);
   double superficialarea();
   /*private:
   double rad;*/
};
class Triangularprism:public Body,public Triangle
{
   public:
   Triangularprism(int,double,double,double,double);
   double superficialarea();
   /*private:
   double tang1;
   double tang2;
   double tang3;*/
};
class Quadrangular:public Body,public Rectangle
{
   public:
   Quadrangular(int,double,double);
   double superficialarea();
   /*private:
   double length;*/
};

Circularcolumn::Circularcolumn(int n,double h,double r)
{
   num = n;
   height = h;
   rad = r;
   plane._area = 3.14*r*r;
   superficialarea();
}
Triangularprism::Triangularprism(int n,double h,double t1,double t2,double t3)
{
   num = n;
   height = h;
   tang1 = t1;
   tang2 = t2;
   tang3 = t3;
   double p = (tang1+tang2+tang3)/2;
   plane._area = sqrt(p*(p-t1)*(p-t2)*(p-t3));
   superficialarea();
}
Quadrangular::Quadrangular(int n,double h,double l)
{
   num = n;
   height = h;
   length = l;
   plane._area = l*l;
   superficialarea();
}

double Body::volume()
{
   _volume = plane._area*height;
   return _volume;
}
double Body::superficialarea()
{
   return _superficialarea;
}
double Circularcolumn::superficialarea()
{
   _superficialarea = plane._area*2+2*3.14*rad*height;
   return _superficialarea;
}
double Triangularprism::superficialarea()
{
   _superficialarea = plane._area*2+(tang1+tang2+tang3)*height;
   return _superficialarea;
}
double Quadrangular::superficialarea()
{
   _superficialarea = plane._area*2+4*(length*height);
   return _superficialarea;
}

/**********end********/
int main() {
    int n;
    double height,r,t1,t2,t3,l;
    cin>>n>>height>>r;//输入n=0，表示圆柱体
    Circularcolumn c1(n,height,r);
    cin>>n>>height>>t1>>t2>>t3;//输入n=3,表示三棱柱
    Triangularprism t(n,height,t1,t2,t3);
    cin>>n>>height>>l;//输入n=4表示正四棱柱
    Quadrangular qu(n,height,l);
    Body *body[3];
    body[0]=&c1;
    body[1]=&t;
    body[2]=&qu;
    double superficalsum=0;
    double volumesum=0;
    for(int i=0;i<3;i++)
       {
          volumesum+=body[i]->volume();//volume()获取该体的体积
          superficalsum+=body[i]->superficialarea();//获取该体的表面积
       }
    cout<<"all volume="<<volumesum<<endl;
    cout<<"all superfilarea="<<superficalsum<<endl;
}
