#include <iostream>
using namespace std;
const int N = 50;
const int M = 100;

//求a,b的交集c=a交b
void jiao(int a[], int b[], int c[], int m, int n, int& k)
{
 //***************************begin*****************************
    int dic[10] = {0};
    k = 0;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(a[i] == b[j])
            {
                c[k++] = a[i];
            }
        }
    }
 //**************************end*********************************
}
void prt(int a[], int n)
{
    int i ,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 0; i < n - 1; i++) {
        cout << a[i] << ' ';
    }
    cout << a[i] << endl;
}

//校验集合a是否满足集合的定义，即没有重复元素
//有重复元素返回false，没有则返回true
bool check(int a[], int n)
{
 //***************************begin*****************************
    int dic[10] = {0};
    for(int i = 0;i<n;i++)
    {
        dic[a[i]]++;
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(a[i] == a[j])
            {
                dic[a[i]]++;
            }
            if(dic[a[i]] >= 2)
            {
                return false;
            }
        }
    }
    return true;
 //**************************end*********************************
}
int main( )
{
    int a[N];
    int b[N];
    int c[M];
    int na, nb, m;
    int i, j;
    cin>>na;
    for (i = 0; i < na; i++)
    {
        cin>>a[i];
    }
    cin>>nb;
    for (j = 0; j < nb; j++)
    {
        cin >> b[j];
    }
    if(check(a,na)&&check(b,nb)){
        jiao(a, b, c, na, nb, m);
        prt(c, m);
    }
    else
        cout<<" a or b is not set"<<endl;
    return 0;           
}