#include<stdio.h>

int main(){
    long n = 0;//初始化n、n_
    long m1 = 1,m2 = 1;//初始化m1、m2
    int u = 1,v = 3;//初始化u、v
    
    int dots[n][3];//初始化点
    scanf("%ld",&n);
    scanf("%ld%ld",&m1,&m2);
    int i = 0;
    while(i != m1){
        scanf("%d%d",&u,&v);
        dots[n][0] = u;
        dots[n][1] = v;
        dots[n][2] = 0;
        n++;
    }                                    //记录m1无向边
    n++;
    long n_ = n;
    i = 0;
    while(i != m2){
        scanf("%d%d",&u,&v);
        dots[n][0] = u;
        dots[n][1] = v;
        dots[n][2] = i;
        n++;
        i++;
    }                                    //记录m2无向边
    long i_ = 0;
    while(i_ < n){
    printf("%d\n",dots[n][2]);
        i_++;
    }
    
    return 0;
}