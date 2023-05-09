#include <iostream>
#include <cstring>
using namespace std;
 
int count(char a,char b[])
{
    int sum = 0;
    for(int i = 0;i<6;i++)
    {
        if(b[i] == a)
        {
            sum++;
        }
    }
    return sum;
}
 
int main()
{
    char course[6][10] = { "Chinese","Math","Politics","Geography","Music","Art" };
    char x[6], y[6];
    char tc[3] = { 'A','B','C' };
    //在下面的begin-end之间填入代码，完成程序的功能
    //*************begin***********************************//
 
for(int i = 0;i<6;i++)
{
    x[i] = 'A';
}
for(x[5]='A';1;x[5]++)
{
    for(int i = 5;i>=0;i--){
        if(x[i]=='D'){
            x[i] = 'A';
            x[i-1]++;
        }
    }
    if(count('A',x)<=2&&count('B',x)<=2&&count('C',x)<=2)
{
if((x[1]!=x[2])&&(x[0]!=x[3])&&(x[3]!='B')&&((x[3]!='A')&&(x[1]!='A'))&&((x[4]!='B')&&(x[0]!='B')))
{
    for(int j = 0;j<6;j++){
        y[j] = x[j];
    }
    break;
    }
	}
}
    
    char t;
    cin>>t;
    if(t == 'A')
    {
        for(int i = 0;i<6;i++)
        {
            if(y[i] == 'A'){
                cout<<"A is "<<course[i]<<endl;
            }
        }
    }
    else if(t == 'B')
    {
        for(int i = 0;i<6;i++)
        {
            if(y[i] == 'B'){
                cout<<"B is "<<course[i]<<endl;
            }
        }
    }
    else if(t == 'C')
    {
        for(int i = 0;i<6;i++)
        {
            if(y[i] == 'C'){
                cout<<"C is "<<course[i]<<endl;
            }
        }
    }
    else{
        return 1;
    }
    //**************end***********************************//
 
    return 0;
}