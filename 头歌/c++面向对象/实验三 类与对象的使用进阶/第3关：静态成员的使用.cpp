#include <iostream>
using namespace std;
//class Salesman ，请在这里完成Saleman类
class Salesman
{

  public:
  void CalculateQuantity();
  void CalculateSale();
  static double CalculateAveragePrice();
  //private:
  int num;
  int quantity;
  float price;
  static float salesamount;
 };
 float Salesman::salesamount = 0;
 int calQuan = 0;
 void Salesman::CalculateQuantity()
 {
   calQuan += quantity;
 }
 void Salesman::CalculateSale()
 {
   salesamount += quantity*price;
 }
 double Salesman::CalculateAveragePrice()
 {
   return salesamount/calQuan;
 }
 //
int main()
{

    Salesman  sa[3];
    for(int i=0;i<3;i++)
       {
         cin>>sa[i].num>>sa[i].quantity>>sa[i].price;  
         sa[i].CalculateQuantity();
         sa[i].CalculateSale();
       } 
    cout<<"sum="<<Salesman::salesamount<<endl;
    cout<<"averageprice="<<Salesman::CalculateAveragePrice();
}