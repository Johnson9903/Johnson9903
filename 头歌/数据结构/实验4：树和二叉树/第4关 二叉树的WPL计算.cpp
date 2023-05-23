#include<iostream>
using namespace std;
typedef struct BiTNode
{
	int weight;
	struct BiTNode *left,*right;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T)
{//先序建立二叉树
	int x;
	cin>>x;
	if(x==0) T=NULL;
	else
    {
		T=new BiTNode;
		T->weight=x;
		CreateBiTree(T->left);
		CreateBiTree(T->right);
	}
}
int WPL(BiTree &T,int d)
{//求二叉树T的带权路径长度
/**************begin************/
   int wpl = 0;
   int l = 0,r = 0;
   if(T)
   {
       //wpl = T->weight;
       if(!T->left&&!T->right)
       {
           wpl += T->weight*d;
       }
       d++;
           l=WPL(T->left,d);
           r=WPL(T->right,d);
               wpl += l;
               wpl += r;
           /*if(l>r)
           {
               wpl=(wpl+l);
           }else{
               wpl=(wpl+r);
           }*/
       /*else{
           return T->weight*d;
       }*/
   }
   return wpl;
    /**************end************/
}
int main()
{
	while(1)
    {
		BiTree T;
		CreateBiTree(T);
		if(!T) break;
		int d=0;          //调用时T指向二叉树的根结点，d为0
		cout<<WPL(T,d)<<endl;
	}
	return 0;
}