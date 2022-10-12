#include <stdio.h>

#define Passward 123456789

main()
{
	
	int passward;
	//int p1;
		printf("请输入密码：\t");
		//int sscanf(char *passward,p1);
		if((passward = getchar()) = Passward){
			printf("是自己人@_@\n");
		}else{
			printf("密码错误！\n");
			return 0;
		}	
	return 0;
}
