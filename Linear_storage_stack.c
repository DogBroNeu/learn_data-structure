#include <stdlib.h>
#include<stdio.h>

//数组模拟栈的顺序存储
#define MAX_SIZE 1024
#define SEQSTACK_TURE  1
#define SEQSTACK_FALSE 0
typedef struct SEQSTACK
{
    void* data[MAX_SIZE];
    int size;
}SeqStack;

//初始化栈
SeqStack* Init_SeqStack();
//入栈
void Push_SeqStack(SeqStack* stack,void* data);
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack);
//出栈
void Pop_SeqStack(SeqStack* stack);
//判断是否为空
int IsEmpty(SeqStack* stack);
//返回栈中元素个数
int Size_SeqStack(SeqStack* stack);
//清空栈
void Clear_SeqStack(SeqStack* stack);
//销毁
void Free_SeqStack(SeqStack* stack);

//初始化栈
SeqStack* Init_SeqStack()
{
    SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        stack->data[i] = NULL;
    }
    stack->size = 0;
    return stack;
}
//入栈
void Push_SeqStack(SeqStack* stack,void* data)
{
    if(stack->size == MAX_SIZE) return;
    if(stack == NULL) return;
    if(data == NULL) return;
    stack->data[stack->size] = data;
    stack->size++;
}
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack)
{
    if(stack == NULL) return NULL;
    if(stack->size == 0) return NULL;
    return stack->data[stack->size - 1];
}
//出栈
void Pop_SeqStack(SeqStack* stack)
{
    if(stack == NULL) return;
    if(stack->size == 0) return;
    stack->data[stack->size - 1] = NULL;
    stack->size--;
}
//判断是否为空
int IsEmpty(SeqStack* stack)
{
    if(stack == NULL)
    {
        return -1;
    }
    if(stack->size == 0)
    {
        return SEQSTACK_TURE;
    }
    return SEQSTACK_FALSE;
}
//返回栈中元素个数
int Size_SeqStack(SeqStack* stack)
{
    return stack->size;
}
//清空栈
void Clear_SeqStack(SeqStack* stack)
{
    if(stack == NULL) return;
    for(int i; i < stack->size; i++)
    {
        stack->data[i] = NULL;
    }
}
//销毁
void Free_SeqStack(SeqStack* stack)
{
    if(stack == NULL) return;
    free(stack);
}

typedef struct PERSON
{
    char name[64];
    int age;
}Person;

int main()
{
    
    //创建栈
    SeqStack* stack = Init_SeqStack();
    //创建数据
    Person p1 = {"aaa",10};
    Person p2 = {"bbb",20};
    Person p3 = {"ccc",30};
    Person p4 = {"ddd",40};
    Person p5 = {"eee",50};
    //入栈
    Push_SeqStack(stack,&p1);
    Push_SeqStack(stack,&p2);
    Push_SeqStack(stack,&p3);
    Push_SeqStack(stack,&p4);
    Push_SeqStack(stack,&p5);

    while(Size_SeqStack(stack) > 0)
    {
        // 访问栈顶元素
        Person* person = (Person*)Top_SeqStack(stack);
        printf("Name:%s Age:%d\n",person->name,person->age);
        //弹出栈顶元素
        Pop_SeqStack(stack);
    }
    //释放内存
    Free_SeqStack(stack);
    return 0 ;
}