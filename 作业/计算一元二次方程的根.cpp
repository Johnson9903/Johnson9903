#include<stdio.h>
#include<math.h>
	int main(void)
	{  
	  /*********Begin*********/
	  //sqrt()
	  float a,b,c;
      float x1,x2;
      printf("Please enter the coefficients a,b,c:\n");
      scanf("%f,%f,%f",&a,&b,&c);
      if(b*b-4*a*c<0){
          printf("error!\n");
      }else{
      x1 = -b/(2*a)+sqrt(b*b-4*a*c)/(2*a);
      x2 = -b/(2*a)-sqrt(b*b-4*a*c)/(2*a);
      printf("x1=%.4f, x2=%.4f\n",x1,x2);
      }
	  /*********End**********/ 
       return 0;
	}
