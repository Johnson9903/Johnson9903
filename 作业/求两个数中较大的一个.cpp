#include <stdio.h>

int main()
{
	int max(int x,int y);
	int a,b,m;

	printf("��������������");
	scanf("%d,%d",&a,&b);
	m = max(a,b);
	
	printf("�����%d\n",m);
	
	return 0;
}

int max(int x,int y)
{
	int z;
	
	if(x>=y)z = x;
	else z = y;
	
	return (z);
}
