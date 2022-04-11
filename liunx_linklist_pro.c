#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链表小节点
typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;
//链表节点
typedef struct LINKLIST
{
    LinkNode head;//头节点
    int size;//链表个数

}LinkList;

//打印函数指针
typedef void(*PRINTLINLNODE)(LinkNode*);
//比较函数指针
typedef int(*COMPARENODE)(LinkNode*,LinkList*);

//初始化链表
LinkList* Init_LinkList();
//指定位置插入
void Insert_LinkList(LinkList* list,int pos,LinkNode* data);
//删除指定位置的值
void Remove_LinkList(LinkList* list,int pos);
//获得链表的长度
int Size_LinkList(LinkList* list);
//返回第一个节点
void* Front_LinkList(LinkList* list);
//释放链表内存
void FreeSpace_LinkList(LinkList* list);
//查找
int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare);
//打印链表节点
void Print_LinkList(LinkList* list,PRINTLINLNODE print);


//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*) malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->size = 0;
    
    return list;
}
//指定位置插入 
void Insert_LinkList(LinkList* list,int pos,LinkNode* data)
{
    int i = 0;
    if(list == NULL){return;}
    if(data == NULL){return;}

    //友好的处理 pos越界
    if(pos < 0 || pos > list->size)
    {
        pos = list->size;
    }
    //找节点
    //辅助指针变量
    LinkNode* pCerrent = &(list->head);
    for(i = 0; i < pos; i++)
    {
        pCerrent = pCerrent->next;
    }
    //插入新节点
    data->next = pCerrent->next;
    pCerrent->next = data;

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
    LinkNode* pCerrent = &(list->head);
    for(i = 0;i < pos; i++) 
    {
        pCerrent = pCerrent->next;
    }
    pCerrent->next = pCerrent->next->next;

    list->size--;
}
//获得链表的长度
int Size_LinkList(LinkList* list)
{
    return list->size;
}
//返回第一个节点
// void* Front_LinkList(LinkList* list)
// {
//     return list->head->next->data;
// }
//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
    if(list == NULL) {return;}
    free(list);
}
//查找
int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare)
{
    int i = 0;
    int flag = -1;
    if(list == NULL){return -1;}
    if(data == NULL){return -1;}
    //遍历查找
    LinkNode* pCerrent = &(list->head.next);
    while(pCerrent != NULL)
    {
        if(compare(pCerrent, data) == 0)
        {
            flag = i;
            break;
        }
        i++;
        pCerrent = pCerrent->next;//节点往后移动
    }
    return flag;
}
//打印链表节点
void Print_LinkList(LinkList* list,PRINTLINLNODE print)
{
    if(list == NULL){return;}
    //辅助指针变量
    LinkNode* pCerrent = list->head.next;
    while(pCerrent != NULL)
    {
        print(pCerrent);
        pCerrent = pCerrent->next;
    }

}
//自定义数据
typedef struct PERSON
{
    LinkNode node;
    char name[64];
    int age;
}Person;

void MyPrint(LinkNode* data)
{
    Person* p = (Person*) data;
    printf("Name:%s Age:%d \n",p->name,p->age);
}

int MyCompare(LinkNode* node1, LinkNode* node2)
{
    Person* p1 = (Person*) node1;
    Person* p2 = (Person*) node2;
    if(strcmp(p1->name,p2->name) == 0 && p1->age == p2->age)
    {
        return 0;
    }
    return -1;
}
int main()
{
    //创建链表
    LinkList* list = Init_LinkList();
    //创建数据
    // Person p1 = {"aaa",100};
    // Person p2 = {"bbb",101};
    // Person p3 = {"ccc",102};
    // Person p4 = {"ddd",103};
    // Person p5 = {"eee",104};
    Person p1,p2,p3,p4,p5;
    strcpy(p1.name,"aaa");
    strcpy(p2.name,"bbb");
    strcpy(p3.name,"ccc");
    strcpy(p4.name,"ddd");
    strcpy(p5.name,"eee");
    
    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;
    //插入链表
    Insert_LinkList(list,0,(LinkNode*)&p1);
    Insert_LinkList(list,0,(LinkNode*)&p2);
    Insert_LinkList(list,0,(LinkNode*)&p3);
    Insert_LinkList(list,0,(LinkNode*)&p4);
    Insert_LinkList(list,0,(LinkNode*)&p5);
    //打印
    Print_LinkList(list,MyPrint);
    //删除
    printf("********************************\n");
    Remove_LinkList(list,2);
    Print_LinkList(list,MyPrint);
    //查找
    printf("********************************\n");
    Person findP;
    strcpy(findP.name, "aaa");
    findP.age = 10;
    int pos = Find_LinkList(list,(LinkNode*)&p1,MyCompare);
    printf("pos:%d",pos);
    //释放链表内存
    FreeSpace_LinkList(list);
    printf("********************************\n");

    
    printf("********************************\n");


    printf("********************************\n");
    printf("********************************\n");
    return 0;
}