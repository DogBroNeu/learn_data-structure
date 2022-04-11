#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
//节点结构体
typedef struct CIRCLELINKNODE
{
    struct LINKNODE* next;
}CircleLinkNode;
//链表结构体
typedef struct CIRCLELINKLIST
{
    CircleLinkNode head;//头节点
    int size;//链表个数
}CircleLinkList;

//打印函数指针
typedef void(*PRINTLINLNODE)(CircleLinkNode *);

typedef int(*COMPARENODE)(CircleLinkNode*,CircleLinkNode*);
//初始化链表
CircleLinkNode* Init_CircleLinkList();
//指定位置插入
void Insert_CircleLinkList(CircleLinkList* clist,int pos,CircleLinkNode* data);
//删除指定位置的值
void RemoveByPos_CiecleLinkList(CircleLinkList* clist,int pos);
//根据值删除
void RemoveByValue_CiecleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare);
//获得链表的长度
int Size_LinkList(CircleLinkList* clist);
//判断是否为空
int IsEmpty_CiecleLinkList(CircleLinkList* clist);
//返回第一个节点
CircleLinkNode* Front_LinkList(CircleLinkList* clist);
//释放链表内存
void FreeSpace_LinkList(CircleLinkList* clist);
//查找
int Find_LinkList(CircleLinkList* list,CircleLinkNode* data,COMPARENODE compare);
//打印链表节点
void Print_LinkList(CircleLinkList* list,PRINTLINLNODE print);

//初始化链表
CircleLinkNode* Init_CircleLinkList()
{
    CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    clist->head.next = &(clist->head);
    clist->size = 0;
    return clist;
}
//指定位置插入
void Insert_CircleLinkList(CircleLinkList* clist,int pos,CircleLinkNode* data)
{
    if(clist == NULL) return;
    if(data == NULL) return;
    if(pos < 0 || pos > clist->size)
    {
        pos = clist->size;
    }
    //根据位置查找
    CircleLinkNode* pCurrent = &(clist->head);
    for(int i; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //新数据入链表
    data->next = pCurrent->next;
    pCurrent->next = data;

    clist->size++;
}
//删除指定位置的值
void RemoveByPos_CiecleLinkList(CircleLinkList* clist,int pos)
{
    if(clist == NULL) return;
    if(pos < 0 || pos >= clist->size) return;
    //根据pos找节点
    CircleLinkNode* pCurrent = &(clist->head);
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //缓存当前节点的下一个节点
    CircleLinkNode* pNext = pCurrent->next;
    pCurrent->next = pNext->next;
    clist->size--;
}
//根据值删除
void RemoveByValue_CiecleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
    int i = 0;
    int flag = -1;
    if(clist == NULL) return;
    if(data == NULL) return;
    CircleLinkNode* pPrev = &(clist->head);
    CircleLinkNode* pCurrent = pPrev->next;
    for( i= 0; i < clist->size; i++)
    {
        if(compare(pCurrent,data) == 1)
        {
            pPrev->next = pCurrent->next;
            break;
        }
        pPrev->next = pCurrent;
        pCurrent = pPrev->next;
    }
    

}
//获得链表的长度
int Size_LinkList(CircleLinkList* clist)
{
    return clist->size;
}
//判断是否为空
int IsEmpty_CiecleLinkList(CircleLinkList* clist)
{
    if(clist->size == 0 )
    {
        return CIRCLELINKLIST_TRUE;
    }
    return CIRCLELINKLIST_FALSE;
}
//返回第一个节点
CircleLinkNode* Front_LinkList(CircleLinkList* clist)
{
    return clist->head.next;
}
//释放链表内存
void FreeSpace_LinkList(CircleLinkList* clist)
{
    if(clist == NULL) return;

    free(clist);
}
//查找
int Find_LinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
    int i = 0;
    int flag = -1;
    if(clist == NULL) return -1;
    if(data == NULL) return -1;
    CircleLinkNode* pCurrent = clist->head.next;
    for(i = 0; i < clist->size; i++)
    {
        if(compare(pCurrent,data) == CIRCLELINKLIST_TRUE)
        {
            flag = i;
            break;
        }
        pCurrent = pCurrent->next;
    }
    return flag;
}
//打印链表节点
void Print_LinkList(CircleLinkList* clist,PRINTLINLNODE print)
{
    int i = 0;
    if(clist == NULL) return;
    //辅助指针变量
    CircleLinkNode* pCurrent = clist->head.next;
    for(i = 0; i < clist->size; i++)
    {
        if(pCurrent == &(clist->head))
        {
            printf("********************************\n");
            pCurrent = pCurrent->next;
        }
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}

typedef struct PERSON
{
    CircleLinkNode node;
    char name[64];
    int age;
    int score;
}Person;
void MyPrint(CircleLinkNode* data)
{
    Person* p = (Person*)data;
    printf("Name:%s Age:%d Score:%d \n",p->name,p->age,p->score);
}
int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2)
{
    Person* p1 = (Person*)data1;
    Person* p2 = (Person*)data2;
    if(strcmp(p1->name,p2->name) == 0 && p1->score == p2->score && p1->age == p2->age)
    {
        printf("yes!!!!!!\n");
        return 1;
    }
    return 0;
}
int main()
{
    CircleLinkList* clist = Init_CircleLinkList();
     
    Person p1,p2,p3,p4,p5;
    Person pDel;
    
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");
    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;
    p1.score = 58;
    p2.score = 545;
    p3.score = 56;
    p4.score = 52;
    p5.score = 78;
    //如链表
    Insert_CircleLinkList(clist,1,(CircleLinkNode*)&p1);
    Insert_CircleLinkList(clist,1,(CircleLinkNode*)&p2);
    Insert_CircleLinkList(clist,1,(CircleLinkNode*)&p3);
    Insert_CircleLinkList(clist,1,(CircleLinkNode*)&p4);
    Insert_CircleLinkList(clist,1,(CircleLinkNode*)&p5);

    Print_LinkList(clist,MyPrint);
    printf("********************************\n");
    printf("********************************\n");
    
    strcpy(pDel.name, "aaa");
    pDel.score = 58;
    pDel.age = 10;
    RemoveByValue_CiecleLinkList(clist,(CircleLinkNode*)&p1,MyCompare);
    // RemoveByPos_CiecleLinkList(clist,2);
    Print_LinkList(clist,MyPrint);
    FreeSpace_LinkList(clist);
    printf("********************************\n");
    printf("********************************\n");
    return 0;
}