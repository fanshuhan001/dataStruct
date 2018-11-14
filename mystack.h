#include <stdlib.h>
#include <stdio.h>
//链表实现
typedef int dataType;
typedef struct sNode
{
	dataType data;
	sNode* next;
}sNode;
typedef sNode *Stack;

Stack createStack(void);
void push(Stack aStack, dataType data);
void pop(Stack aStack);
int isEmptyStack(Stack aStack);
void releaseStack(Stack aStack);//清空
dataType topElement(Stack aStack);
void freeStack(Stack aStack);
void printStack(Stack aStack);
//数组实现
typedef struct
{
	int capacity;//栈的深度
	int topEle; //记录栈顶位置
	dataType *stackData;
}aArrStack, *arrStack;

arrStack createArrStack(int);
void push(arrStack aStack, dataType data);
void pop(arrStack aStack);
int isEmptyStack(arrStack aStack);
void releaseStack(arrStack aStack);//清空
dataType topElement(arrStack aStack);
void freeStack(arrStack aStack);
void printStack(arrStack aStack);