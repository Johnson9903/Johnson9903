#include <iostream>

using namespace std;

typedef struct node  //定义节点数据结构
{ int d;
 struct node *next;
};

void prtList( node *head) //负责输出显示线性链表
{
    while(head!=NULL)
    {
        cout << head->d << ' ';
        head = head->next;
    }
        cout << endl;
}

node * invertList( node *head) //负责逆转链表的函数，您需要完成的作业
{
    //请同学们在这里写代码，完成以head为头指针的线性链表的逆序
    node* result = NULL;
    node* p;
    while(head != NULL)
    {
        p = new node;
        p->d = head->d;
        p->next = result;
        result = p;
        head = head->next;
    }
    return result;
}

main()
{
    node *p, *head = NULL, *newHead;

    int K = 10, i;
    for(i=1;i<K;i++)   //创建并初始化一个长度为K的链表，链表内容是自然数
    {
        p =new node;
        p->d = i;

        p->next = head; //头插法
        head = p;
    }

    prtList(head);  //显示链表的当前值

    newHead = invertList(head);

    prtList(newHead);  //显示链表的当前值
}




