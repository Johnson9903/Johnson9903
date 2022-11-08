#include  <stdio.h>
int main()
{ 
	char c1,c2;
	c1=getchar();
	if(c1>='A'&&c1<='Z')
	{
		
	/*****以下一行有错误*****/
		c2=c1+32;
		
		if(c2>='a' && c2<='u')
			
	/*****以下一行有错误*****/
			c2=c2+5;
			
		else  if(c2>='v' && c2<='z')	c2=c2-21;
		printf("The letter %c change to %c\n",c1,c2);
	}
	
	return 0;
}
