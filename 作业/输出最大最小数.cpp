/********** Begin **********/
#include<stdio.h>

int main(){
    
    int a,b,c,mx,mn;
    scanf("%d%d%d",&a,&b,&c);
    int max(int x,int y,int z);
    int min(int x,int y,int z);
    
    mx = max(a,b,c);
    mn = min(a,b,c);
    printf("max = %d\n",mx);
    printf("min = %d\n",mn);
    return 0;
}

int max(int x,int y,int z){
    int max;
    if(x>=y){
        max = x;
        if(max<=z){
            max = z;
        }
    }else{
        max = y;
        if(max<=z){
            max = z;
        }
    }
    return(max);
}

int min(int x,int y,int z){
    int min;
    if(x<=y){
        min = x;
        if(min>=z){
            min = z;
        }
    }else{
        min = y;
        if(min>=z){
            min = z;
        }
    }
    return(min);
}
/********** End **********/
