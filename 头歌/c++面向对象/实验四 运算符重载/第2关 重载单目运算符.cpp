 #include <iostream>
using namespace std;
/*********在begin和end之间填入代码，实现complex类的定义，重载前置++运算符和重载后置++运算符及display()函数********/
/***********begin*************/
class Complex
{
    public:
    float real;
    float imag;
    void display();
    Complex operator++();
    Complex operator++(int);
};

Complex Complex::operator++()
{
    Complex c(*this);
    ++real;
    ++imag;
    return c;
}

Complex Complex::operator++(int)
{
    Complex c(*this);
    real++;
    imag++;
    return c;
}

void Complex::display()
{
    if(real==0)
    {
        if(imag>0)
           cout<<imag<<"i";
        else if(imag==0)
            cout<<real;
        else
           cout<<imag<<"i";
    }
    else {
        if(imag>0)
           cout<<real<<"+"<<imag<<"i";
        else if(imag==0)
            cout<<real;
        else
           cout<<real<<imag<<"i";
       }
}
/***********end************/
int main()
{
   Complex c1,c2;
   cin>>c1.real>>c1.imag;
   c1.display();
   cout<<endl;
   ++c1;
   c2=c1++;
   c2.display();
   cout<<endl;
   c1.display();
}