 #include <iostream>
using namespace std;
//请在begin和end间完成Matrix类的编写，重载>>及<<运算符，建议重载为友元函数
/*********begin**********/
class Matrix
{
    public:
    friend istream &operator>>(istream&,Matrix&);
    friend ostream &operator<<(ostream&,Matrix&);
    float el[2][3] = {0};
};

istream &operator>>(istream &inp,Matrix &m)
{
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<3;j++)
        {
            inp>>m.el[i][j];
        }
    }
    return inp;
}
ostream &operator<<(ostream &out,Matrix &m)
{
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<3;j++)
        {
            out<<m.el[i][j]<<' ';
        }
        out<<endl;
    }
    return out;
}
/*********end*********/
int main()
{
    Matrix m1;
    cin>>m1;
    cout<<"output matrix"<<endl;
    cout<<m1;
}