# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef  int  SElemType;
typedef  int  QElemType;

# include "sqstack.h"
# include "sqqueue.h"

void output(QElemType s);
void input(QElemType &s);
void outputS(SElemType s);
void inputS(SElemType &s);
int comp(SElemType a, SElemType b);
int LocateElem_Sq(SqStack L, SElemType e, int (*compare)(SElemType, SElemType)) ;

int  main()
{
	SqQueue  q1,q2;            //定义二个队列，代表甲、乙手中的牌
	SqStack  s;                //定义一个栈，代表桌面上的牌
	int i,t,x,n;
	InitQueue(q1);
	InitQueue(q2);
	InitStack(s);	
	for(i=1;i<=6;i++)
	{
		scanf("%d",&t);
    	EnQueue(q1,t);
	}
	for(i=1;i<=6;i++)
	{
		scanf("%d",&t);
		EnQueue(q2,t);
	}
   // 请在这里补充代码，完成本关任务
   /********** Begin **********/ 
	QElemType e,e1,e2;
	int i1,i2,*ix;
	while(!QueueEmpty(q1)&&!QueueEmpty(q2)){
		DeQueue(q1,e1);
		i1=LocateElem_Sq(s,e1,comp);
		Push(s,e1);
		while(i1>=0){
			ix=s.base+i1;
			while(ix<s.top){
				Pop(s,e);
				EnQueue(q1,e);
			}
			DeQueue(q1,e1);
			i1=LocateElem_Sq(s,e1,comp);
			Push(s,e1);
		}
		printf("甲：");
		QueueTraverse(q1,outputS);

		DeQueue(q2,e2);
		i2=LocateElem_Sq(s,e2,comp);
		Push(s,e2);
		while(i2>=0){
			ix=s.base+i2;
			while(ix<s.top){
				Pop(s,e);
				EnQueue(q2,e);
			}
			DeQueue(q2,e2);
			i2=LocateElem_Sq(s,e2,comp);
			Push(s,e2);
		}
		printf("乙：");
		QueueTraverse(q2,outputS);
		printf("栈：");
		StackTraverse(s,outputS);
	}
	if(QueueEmpty(q1))
		printf("乙获胜");
	else
		printf("甲获胜");
	/********** End **********/	
    return 0;
}

int LocateElem_Sq(SqStack L, SElemType e, int (*compare)(SElemType, SElemType)) 
{  
  // 在顺序栈L中查找第1个值与e满足compare()的元素的位序。
  // 若找到，则返回其在L中的位序，否则返回0。
  int i;
  SElemType *p;
  i = 0;        // i的初值为第1个元素的位序
  p = L.base;   // p的初值为第1个元素的存储位置
  int length = L.top-L.base;
  while (i <length && !(*compare)(*p++, e)) 
    ++i;
  if (i < length) 
	  return i;
  else 
	  return -1;
} // LocateElem_Sq

void output(QElemType s)
{
	printf("%d,",s);	   
}

void input(QElemType &s)
{ 	
	scanf("%d",&s);	
}
void outputS(SElemType s)
{
	printf("%d,",s);	   
}

void inputS(SElemType &s)
{ 	
	scanf("%d",&s);	
}
int comp(SElemType a, SElemType b)
{
	if(a>b)
		return 0;
	else
		if(a == b)
			return 1;
		else
			return 0;
}
