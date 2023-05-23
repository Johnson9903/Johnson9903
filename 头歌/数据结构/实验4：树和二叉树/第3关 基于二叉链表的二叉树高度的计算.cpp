#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//先序建立二叉树
	if(S[i]=='0')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=S[i];
		CreateBiTree(T->lchild,S,++i);
		CreateBiTree(T->rchild,S,++i);
	}
}
int Depth(BiTree T)
{//二叉树高度的计算
/**************begin************/
	int d = 1;
    int r = 0,l = 0;
    if(T)
    {
        if(T->lchild||T->rchild)
        {
            if(T->lchild)
            {
                l+=Depth(T->lchild);
            }
            if(T->rchild)
            {
                r+=Depth(T->rchild);
            }
            if(l>r){
                d+=l;
            }else{
                d+=r;
            }
        }else{
            return d;
        }
    }
    return d;
    /**************end************/
}
int main()
{
	char S[100];
	while(cin>>S)
	{
	    if(strcmp(S,"0")==0) break;
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		cout<<Depth(T)<<endl;
	}
	return 0;
}