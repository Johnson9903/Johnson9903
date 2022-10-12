#include <stdio.h>

main()
{
	
	int huashi,sheshi;
	int min,max,step;
	
	min = 0;
	max = 300;
	step = 20;
	
	huashi = max;
	
	printf("ª™ œ∂»\t…„ œ∂»\n");
	
	while(huashi<=max && huashi>=min)
	{
		sheshi = 5*(huashi-32)/9;
		printf("%d\t%d\n",huashi,sheshi);
		huashi = huashi - step;
	}
	
	return 0;
}
