#include <stdio.h>

main()
{
	printf("int的大小为：%d\n",sizeof(int));
	printf("short int的大小为：%d\n",sizeof(short int));
	printf("long int的大小为：%d\n",sizeof(long int));
	printf("long long int的大小为：%d\n",sizeof(long long int));
	printf("char的大小为：%d\n",sizeof(char));
	printf("float的大小为：%d\n",sizeof(float));
	printf("double的大小为：%d\n",sizeof(double));
	printf("long double的大小为：%d\n",sizeof(long double));
	printf("_Bool的大小为：%d\n",sizeof(bool));
	
	return 0;
}
