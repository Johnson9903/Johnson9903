#include<stdio.h>

int main(){
	
	int a,b,c;
	int abc;
	int cba;
	scanf("%d",&abc);
	a = abc/100;
	b = (abc-a*100)/10;
	c = abc-a*100-b*10;
	cba = c*100+b*10+a;
	printf("%d",cba);
	
	return 0;
}
