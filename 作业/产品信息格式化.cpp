#include<stdio.h>

int num;
float price;
int dy,dm,dd;

	int main(void)
	{  
	  /*********Begin*********/
	  printf("Enter item number:\n");
      scanf("%d",&num);
	  printf("Enter unit price:\n");
      scanf("%f",&price);
      printf("Enter purchase date (mm/dd/yy):\n");
      scanf("%d/%d/%d",&dy,&dm,&dd);
      printf("Item Unit Purchase\n");
      printf("%-9d$ %-9.2f%02d%02d%02d\n",num,price,dy,dm,dd);
	  /*********End**********/ 
       return 0;
	}
