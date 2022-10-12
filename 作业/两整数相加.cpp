#include <stdio.h>

int main()
{
    int p;
    int a,b,c;
    int plus(int x,int y);
    int password = 12345671;
    
    printf("请输入密码：");
    scanf("%d",&p);
    if(p == password){
    printf("请输入两个整数：");
    scanf("%d,%d",&a,&b);
    c = plus(a,b);
    printf("%d\n",c);
    }else{
		printf("密码错误！\n");
	}
    
    return 0;
}

int plus(int x,int y)
{
    int z;
    z = x + y;
    
    return(z);
}
