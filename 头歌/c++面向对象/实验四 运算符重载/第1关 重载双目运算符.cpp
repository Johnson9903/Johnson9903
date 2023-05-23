 #include <iostream>
using namespace std;
/*在begin和end之间完成Matrix类的书写，其中el[2][3]为矩阵元素存储二维数组，并完成矩阵+运算符重载，display()函数完成矩阵的元素输出显示*/
/*****begin******/
class Matrix
{
    public:
    int el[2][3];
    void display();
};

Matrix operator+(const Matrix &m1,const Matrix &m2)
{
    Matrix m;
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<3;j++)
        {
            m.el[i][j] = m1.el[i][j]+m2.el[i][j];
        }
    }
    return m;
}

void Matrix::display()
{
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<3;j++){
            cout<<el[i][j]<<' ';
        }
        cout<<endl;
    }
}

/******end******/
int main()
{
    Matrix a,b,c;
   for(int i=0;i<2;i++)
       for(int j=0;j<3;j++)
       {
         cin>>a.el[i][j];
       }
   for(int i=0;i<2;i++)
       for(int j=0;j<3;j++)
       {
          cin>>b.el[i][j];
       }
   c=a+b;
   c.display();
}
