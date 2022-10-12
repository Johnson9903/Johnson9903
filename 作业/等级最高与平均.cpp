#include <stdio.h>

	int L1,L2,L3,L4,L5,L6,L7,L8,L9,LA,LB,LC,LD;

int main()
{
	int levelH(),levelA();
	L1,L2,L3,L4,L5,L6,L7,L8,L9,LA,LB,LC,LD >=0;
	L1,L2,L3,L4,L5,L6,L7,L8,L9,LA,LB,LC,LD <=100;
	
	printf("请输入等级：");
	scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&L1,&L2,&L3,&L4,&L5,&L6,&L7,&L8,&L9,&LA,&LB,&LC,&LD);
	
	printf("最高等级为：%d\n最低等级为：%f\n",levelH(),levelA());
	
	return 0;
}

int levelH()
{
	if(L1>L2&&L1>L3&&L1>L4&&L1>L5&&L1>L6&&L1>L7&&L1>L8&&L1>L9&&L1>LA&&L1>LB&&L1>LC&&L1>LD){
		return(L1);
	}else if(L2>L1&&L2>L3&&L2>L4&&L2>L5&&L2>L6&&L2>L7&&L2>L8&&L2>L9&&L2>LA&&L2>LB&&L2>LC&&L2>LD){
		return(L2);
	}else if(L3>L2&&L3>L1&&L3>L4&&L3>L5&&L3>L6&&L3>L7&&L3>L8&&L3>L9&&L3>LA&&L3>LB&&L3>LC&&L3>LD){
		return(L3);
	}else if(L4>L2&&L4>L3&&L4>L1&&L4>L5&&L4>L6&&L4>L7&&L4>L8&&L4>L9&&L4>LA&&L4>LB&&L4>LC&&L4>LD){
		return(L4);
	}else if(L5>L2&&L5>L3&&L5>L4&&L5>L1&&L5>L6&&L5>L7&&L5>L8&&L5>L9&&L5>LA&&L5>LB&&L5>LC&&L5>LD){
		return(L5);
	}else if(L6>L2&&L6>L3&&L6>L4&&L6>L5&&L6>L1&&L6>L7&&L6>L8&&L6>L9&&L6>LA&&L6>LB&&L6>LC&&L6>LD){
		return(L6);
	}else if(L7>L2&&L7>L3&&L7>L4&&L7>L5&&L7>L6&&L7>L1&&L7>L8&&L7>L9&&L7>LA&&L7>LB&&L7>LC&&L7>LD){
		return(L7);
	}else if(L8>L2&&L8>L3&&L8>L4&&L8>L5&&L8>L6&&L8>L7&&L8>L1&&L8>L9&&L8>LA&&L8>LB&&L8>LC&&L8>LD){
		return(L8);
	}else if(L9>L2&&L9>L3&&L9>L4&&L9>L5&&L9>L6&&L9>L7&&L9>L8&&L9>L1&&L9>LA&&L9>LB&&L9>LC&&L9>LD){
		return(L9);
	}else if(LA>L2&&LA>L3&&LA>L4&&LA>L5&&LA>L6&&LA>L7&&LA>L8&&LA>L9&&LA>L1&&LA>LB&&LA>LC&&LA>LD){
		return(LA);
	}else if(LB>L2&&LB>L3&&LB>L4&&LB>L5&&LB>L6&&LB>L7&&LB>L8&&LB>L9&&LB>LA&&LB>L1&&LB>LC&&LB>LD){
		return(LB);
	}else if(LC>L2&&LC>L3&&LC>L4&&LC>L5&&LC>L6&&LC>L7&&LC>L8&&LC>L9&&LC>LA&&LC>LB&&LC>L1&&LC>LD){
		return(LC);
	}else if(LD>L2&&LD>L3&&LD>L4&&LD>L5&&LD>L6&&LD>L7&&LD>L8&&LD>L9&&LD>LA&&LD>LB&&LD>LC&&LD>L1){
		return(LD);
	}
	
	//L1	L2	L3	L4	L5	L6	L7	L8	L9	L10	L11	L12	L13
	//L1	L2	L3	L4	L5	L6	L7	L8	L9	L10	L11	L12	L13
	
/*	else if(L>L2&&L>L3&&L>L4&&L>L5&&L>L6&&L>L7&&L>L8&&L>L9&&L>LA&&L>LB&&L>LC&&L>LD){
	return(L);
}*/
}

int levelA()
{
	double average;
	average = (L1+L2+L3+L4+L5+L6+L7+L8+L9+LA+LB+LC+LD);//如何计算L个数？
	
	return(average);
}
