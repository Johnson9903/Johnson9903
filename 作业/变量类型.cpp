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
	
	printf("�����û���Ϊ��%c\n",name);
	printf("��������Ϊ��%d\n",passward);
	printf("Բ����Ϊ��%.2f\n",pai);
	printf("Բ���ʾ�ȷ��10λС��Ϊ��%11.10f\n",npai);
	
	return 0;
}
