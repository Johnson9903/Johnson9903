#include<stdio.h>

int main(){
	/*
	int x = 1,a = 0,b = 0;
	switch (1) {
		case 0:
			x++;		
		case 1:
			a++;			
		case 2:
			a++;
			b++;			
	}
	printf("a=%d,b=%d",a,b);
	*/
	int day = 0;
	scanf("%d",&day);
	switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:printf("workday");
		break;	
		case 6:
		case 7:printf("weekend");
		break;
		default:
			break;
	}
	return 0;
}
