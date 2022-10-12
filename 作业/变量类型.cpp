#include <stdio.h>
#include <string>

using std::string;
using std::wstring;

int main()
{
	char name;
	int passward;
	float pai;
	double npai;
	
	name = 'J';
	passward = 12345678;
	pai = 3.14;
	npai = 3.1415926535;
	
	printf("您的用户名为：%c\n",name);
	printf("您的密码为：%d\n",passward);
	printf("圆周率为：%.2f\n",pai);
	printf("圆周率精确到10位小数为：%11.10f\n",npai);
	
	return 0;
}
