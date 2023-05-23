 #include<iostream>
#include<string>
using namespace std;
/***********begin**********/
//此处完成各个类的书写，并实现题目输出
class base
{
   public:
   void InStorage(int);
   void OutStorage(int);
   void Calculate();
   //private:
   string loc;
   double price;
   int num;
   double total;
};

class Shirt:public base
{
   public:
   Shirt(string,double,int,string);
   private:
   string mat;
};

class Cap:public base
{
   public:
   Cap(string,double,int,string,string);
   private:
   string mat;
   string shape;
};

class Capboard:public base
{
   public:
   Capboard(string,double,int,string,string);
   private:
   string mat;
   string color;
};

Cap::Cap(string lo,double pr,int nu,string ma,string sh)
{
   loc = lo;
   price = pr;
   num = nu;
   mat = ma;
   shape = sh;
}

Capboard::Capboard(string lo,double pr,int nu,string ma,string co)
{
   loc = lo;
   price = pr;
   num = nu;
   mat = ma;
   color = co;
}

Shirt::Shirt(string lo,double pr,int nu,string ma)
{
   loc = lo;
   price = pr;
   num = nu;
   mat = ma;
}

void base::InStorage(int i)
{
   num += i;
}

void base::OutStorage(int i)
{
   if(i>num)
   {
      cout<<"Insufficient  number!"<<endl;
      //num = 0;                             //题目要求但数据集有问题
   }else{
      num -= i;
   }
}

void base::Calculate()
{
   total = price*num;
   cout<<"total money="<<total<<endl;
}
/**********end***********/
int main() {

   Shirt s1("江西南昌",235,150,"纯棉");
   Cap p1("四川成都",88,150,"尼龙","平顶");
   Capboard cup1("云南昆明",3500,10,"云松木","原色");
   int i,j,k,m;
   cin>>i>>j>>k>>m;
   s1.InStorage(i);
   s1.OutStorage(j);
   p1.OutStorage(k);
   cup1.OutStorage(m);
   s1.Calculate();
   p1.Calculate();
   cup1.Calculate();
}