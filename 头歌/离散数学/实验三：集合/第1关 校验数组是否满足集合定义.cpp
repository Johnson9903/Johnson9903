#include <iostream>
using namespace std;

//校验集合a是否满足集合的定义，即没有重复元素
//有重复元素返回false，没有则返回true
const int N=50;
bool check(int a[], int n)
{
    //**********************begin***********************
    int dic[10] = {0};
    for(int i = 0;i<n;i++)
    {
        dic[i]++;
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
                return 0;
            }
        }
    }
    return 1;
    //**********************en**************************
}

int main()
{
    int a[N];
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    if(check(a,n))cout<<1<<endl;
    else cout<<0<<endl;
}