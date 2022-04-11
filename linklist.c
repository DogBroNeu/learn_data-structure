#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//节点结构体
typedef struct LINKNODE
{
    void* data;//指向任何类型的数据
    struct LINKNODE* next;
}LinkNode;
//链表结构体
typedef struct LINKLIST
{
    LinkNode* head;//头节点
    int size;//链表个数
    //不需要容量
}LinkList;

//打印函数指针
typedef void(*PRINTLINLNODE)(void*);

//初始化链表
LinkList* Init_LinkList();
//指定位置插入
void Insert_LinkList(LinkList* list,int pos,void* data);
//删除指定位置的值
void Remove_LinkList(LinkList* list,int pos);
//获得链表的长度
int Size_LinkList(LinkList* list);
//返回第一个节点
void* Front_LinkList(LinkList* list);
//释放链表内存
void FreeSpace_LinkList(LinkList* list);
//查找
int Find_LinkList(LinkList* list,void* data);
//打印链表节点
void Print_LinkList(LinkList* list,PRINTLINLNODE print);


//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*) malloc(sizeof(LinkList));
    list->size = 0;
    //头节点 是不保存信息的
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
    
    return list;
}
//指定位置插入
void Insert_LinkList(LinkList* list,int pos,void* data)
{
    int i = 0;
    if(list == NULL){return;}
    if(data == NULL){return;}

    //友好的处理 pos越界
    if(pos < 0 || pos > list->size)
    {
        pos = list->size;
    }
    //创建新的节点
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;
    
    //找节点
    //辅助指针变量
    LinkNode* pCerrent = list->head;
    for(i = 0; i < pos; i++)
    {
        pCerrent = pCerrent->next;
    }

    //新节点入链表
    newnode->next = pCerrent->next;
    pCerrent->next = newnode;

    list->size++;
}
//删除指定位置的值
void Remove_LinkList(LinkList* list,int pos)
{
    int i = 0;
    if(list == NULL) {return;}
    if(pos < 0 || pos >= list->size)
    {
        return;
    }
    //查找删除节点的前一个节点
    LinkNode* pCerrent = list->head;
    for(i = 0;i < pos; i++) 
    {
        pCerrent = pCerrent->next;
    }
    //缓存删除的节点
    LinkNode* pDel = pCerrent->next;
    pCerrent->next = pDel->next;
    //释放删除节点的内存
    free(pDel);
    list->size--;
}
//获得链表的长度
int Size_LinkList(LinkList* list)
{
    return list->size;
}
//返回第一个节点
void* Front_LinkList(LinkList* list)
{
    return list->head->next->data;
}
//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
    if(list == NULL) {return;}
    //辅助指针变量
    LinkNode* pCerrent = list->head;
    while(pCerrent != NULL)
    {
        //缓存下一个节点
        LinkNode* pNext = pCerrent->next;
        free(pCerrent);
        pCerrent = pNext;
    }
    //释放链表内存
    list->size = 0;
    free(list);
}
//查找
int Find_LinkList(LinkList* list,void* data)
{
    int i = 0;
    if(list == NULL){return -1;}
    if(data == NULL){return -1;}
    //遍历查找
    LinkNode* pCerrent = list->head->next;
    while(pCerrent != NULL)
    {
        if(pCerrent->data == data)
        {
            break;
        }
        i++;
        pCerrent = pCerrent->next;//节点往后移动
    }
    return i;
}
//打印链表节点
void Print_LinkList(LinkList* list,PRINTLINLNODE print)
{
    if(list == NULL){return;}
    //辅助指针变量
    LinkNode* pCerrent = list->head->next;
    while(pCerrent != NULL)
    {
        print(pCerrent->data);
        pCerrent = pCerrent->next;
    }

}
//自定义数据
typedef struct PERSON
{
    char name[64];
    int age;
    int score;
}Person;

void MyPrint(void* data)
{
    Person* p = (Person*)data;
    printf("Name:%s Age:%d Score:%d\n",p->name,p->age,p->score);
}

int main()
{
    //创建链表
    LinkList* list = Init_LinkList();
    //创建数据
    Person p1 = {"aaa",100,99};
    Person p2 = {"bbb",101,50};
    Person p3 = {"ccc",102,70};
    Person p4 = {"ddd",103,10};
    Person p5 = {"eee",104,97};
    //插入链表
    Insert_LinkList(list,0,&p1);
    Insert_LinkList(list,0,&p2);
    Insert_LinkList(list,0,&p3);
    Insert_LinkList(list,0,&p4);
    Insert_LinkList(list,0,&p5);
    //打印
    Print_LinkList(list,MyPrint);
    //删除3
    Remove_LinkList(list,3);
    printf("********************************\n");
    Print_LinkList(list,MyPrint);
    
    printf("********************************\n");
    //返回第一个节点
    Person*  ret = (Person*)Front_LinkList(list);
    printf("Name:%s Age:%d Score:%d\n",ret->name,ret->age,ret->score);
    FreeSpace_LinkList(list);
    printf("********************************\n");
    printf("********************************\n");
    return 0;
}