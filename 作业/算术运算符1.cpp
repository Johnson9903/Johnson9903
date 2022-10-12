#include <stdio.h>
#include <math.h>

int main()
{
/*	int i,j,k;
	i = 1+2;
	j = 1+2*3;
	k = i+j+pow(2,3);
	
	printf("\n%d\t%d\t%d\n",i,j,k);*/
	
	printf("整型：%d\n",1+(int)1.8);//非四舍五入，高精度向低精度转换会损失精度
	printf("浮点型：%f\n",1+2.0);
	return 0;
}
