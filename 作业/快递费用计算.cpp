#include<stdio.h>

float price;
	int main(void)
	{  
	  /*********Begin*********/
	  int city;
      int CityNum();
      float weight;
      scanf("%d,%f",&city,&weight);
	  switch(city){
          case 0:
            if(weight<=1){
                weight = 1;
                price = 10;
            }else{
                if(weight/(int)weight>1)
                weight = (int)weight + 1;
                price = 10+(weight-1)*3;
            }
            printf("Price: %.2f\n",price);
            break;
          case 1:
                if(weight<=1){
                weight = 1;
                price = 10;
            }else{
                if(weight/(int)weight>1)
                weight = (int)weight + 1;
                price = 10+(weight-1)*4;
            }
            printf("Price: %.2f\n",price);
            break;
          case 2:
          if(weight<=1){
                weight = 1;
                price = 15;
            }else{
                if(weight/(int)weight>1)
                weight = (int)weight + 1;
                price = 15+(weight-1)*5;
            }
            printf("Price: %.2f\n",price);
            break;
        case 3:
        if(weight<=1){
                weight = 1;
                price = 15;
            }else{
                if(weight/(int)weight>1)
                weight = (int)weight + 1;
                price = 15+(weight-1)*6.5;
            }
            printf("Price: %.2f\n",price);
            break;
          case 4:
            if(weight<=1){
                weight = 1;
                price = 15;
            }else{
                if(weight/(int)weight>1)
                weight = (int)weight + 1;
                price = 15+(weight-1)*10;
            }
            printf("Price: %.2f\n",price);
            break;
        default:
            printf("Error in Area\n");
            printf("Price: 0.00 ");
            break;
      }
      
	  /*********End**********/ 
       return 0;
	}
