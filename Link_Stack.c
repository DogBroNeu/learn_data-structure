#include <stdlib.h>
#include<stdio.h>
#include <string.h>

//链式栈的节点
typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;

//链式栈
typedef struct LINSTACK
{
    LinkNode head;
    int size;
}LinkStack;

//初始化函数
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//返回栈元素的个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack);


//初始化函数
LinkStack* Init_LinkStack()
{
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack->head.next = NULL;
    stack->size = 0;
    return stack;
}
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data)
{
    if(stack == NULL) return;
    if(data == NULL) return;

    data->next = stack->head.next;
    stack->head.next = data;

    stack->size ++;
    printf("yes!!!\n");
}
//出栈
void Pop_LinkStack(LinkStack* stack)
{
    if(stack == NULL) return;
    if(stack->size == 0) return;
    //第一有效节点
    // LinkNode* node = stack->head.next;
    // stack->head.next = node->next;
    stack->head.next = stack->head.next->next;
    stack->size--;
}
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack)
{
    if(stack == NULL) return NULL;
    if(stack->size == 0) return NULL;
    return stack->head.next;
}
//返回栈元素的个数
int Size_LinkStack(LinkStack* stack)
{
    if(stack == NULL) return -1;
    return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
    if(stack == NULL) return;
    stack->head.next = NULL;
    stack->size = 0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack)
{
    if(stack == NULL) return;
    free(stack);
}

typedef struct PERSON
{
    LinkNode node;
    char name[64];
    int age;
}Person;

int main()
{
    //创建栈
    LinkStack* stack = Init_LinkStack();
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

    //入栈
    Push_LinkStack(stack,(LinkNode*)&p1);
    Push_LinkStack(stack,(LinkNode*)&p2);
    Push_LinkStack(stack,(LinkNode*)&p3);
    Push_LinkStack(stack,(LinkNode*)&p4);
    Push_LinkStack(stack,(LinkNode*)&p5);

    //输出
    while(Size_LinkStack(stack) > 0)
    {
        Person* person = (Person*)Top_LinkStack(stack);
        printf("Name:%s Age:%d\n",person->name,person->age);
        //弹出栈顶元素
        Pop_LinkStack(stack);
    }
    FreeSpace_LinkStack(stack);
    return 0 ;
}