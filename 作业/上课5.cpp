#include<stdio.h>
#include<math.h>

int main(){
	
	float pi = 0;
	int fz = 1;
	float fm = 1;
	float n;
	printf("enter n\n"); 
	scanf("%f",&n);
	float t;
	do{
		t = fz/fm;
		pi += t;
		fm += 2;
		fz = -fz;
	}while(fabs(t) <= n);
	pi = pi*4;
	printf("%f",pi);
	
	/*
	for(int i = 1;i <= 5;i++){
		for(int k = 0;k <= 4-i;k++){
			printf("%2c",' ');
		}
		for(int n = 1;n <= 2*i-1;n++){
			printf("%2c",'*');
		}
		printf("\n");
	}
	*/
	/*
	int i;
	printf("%4c",'*');
	for(i = 1;i<=9;i++)printf("%4d",i);
	printf("\n");
	for(i = 1;i<=10;i++)printf("%4c",'-');
	printf("\n");
	for(i=1;i<=9;i++){
		printf("%4d",i);
			for(int j = 1;j<=i;j++){
				printf("%4d",i*j);
			}
		printf("\n");
	}
	*/
	return 0;
}
