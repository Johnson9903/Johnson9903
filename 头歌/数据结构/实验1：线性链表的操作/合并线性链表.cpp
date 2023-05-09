 #include <iostream>

using namespace std;

typedef struct node //定义节点数据结构
{ int d;
 struct node *next;
};

void prtList( node *head) //负责输出显示线性链表
{
    cout<< "当前链表的内容为：";
    while(head!=NULL)
    {
        cout << head->d << ' ';
        head = head->next;
    }
        cout << endl;
}

node* combineList( node *AH, node *BH) //负责合并链表，你需要完成的作业
{
    node *ch;
    node *p;
    p = new node;
    node *head;
    head = p;
    /*int len = 0;
    while(AH != NULL)
    {
        len++;
        AH = AH->next;
    }
    while(BH != NULL)
    {
        len++;
        BH = BH->next;
    }*/
    //请同学们在这里写代码，完成以AH和BH为头指针的两个线性链表的合并，新链表的头指针赋给ch。
    while(BH!=NULL&&AH!=NULL)
    {
        p->next = new node;
        if(AH->d<BH->d)
        {
            /*p->d = BH->d;
            p->next = ch; //头插法
            ch = p;*/
            p->d = BH->d;
            ch = p;
            p = ch->next;
            BH = BH->next;
        }
        else
        {
            /*p->d = AH->d;
            p->next = ch; //头插法
            ch = p;*/
            p->d = AH->d;
            ch = p;
            p = ch->next;
            AH = AH->next;
        }
        /*if(AH == NULL)
        {
            while(BH != NULL)
            {
                p->d = BH->d;
                ch = p;
                p = ch->next;
                BH = BH->next;
            }
        }
        else
        {
            while(AH != NULL)
            {
                p->d = AH->d;
                ch = p;
                p = ch->next;
                AH = AH->next;
            }
        }*/
    }
    ch->next->d = 1;
    ch = head;
    return ch;
}

main()
{
    node *p, *AH = NULL, *BH = NULL, *CH=NULL;

    int K = 10, i;
    for(i=1;i<=K;i=i+2)   //创建并初始化一个长度为K的链表，链表内容是自然数
    {
        p =new node;
        p->d = i;

        p->next = AH; //头插法
        AH = p;
    }


    for(i=2;i<=K+5;i=i+4)   //创建并初始化一个长度为K的链表，链表内容是自然数
    {
        p =new node;
        p->d = i;

        p->next = BH; //头插法
        BH = p;
    }
    cout << "合并前A链表"<<endl;
    prtList(AH);  //显示链表1的当前值
    cout << "合并前B链表"<<endl;
    prtList(BH);  //显示链表2的当前值

    CH = combineList(AH, BH);

    cout << "合并后"<<endl;
    prtList(CH);
}