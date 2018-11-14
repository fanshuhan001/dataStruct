#include <stdlib.h>
#include <stdio.h>
//����ʵ��
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
void releaseStack(Stack aStack);//���
dataType topElement(Stack aStack);
void freeStack(Stack aStack);
void printStack(Stack aStack);
//����ʵ��
typedef struct
{
	int capacity;//ջ�����
	int topEle; //��¼ջ��λ��
	dataType *stackData;
}aArrStack, *arrStack;

arrStack createArrStack(int);
void push(arrStack aStack, dataType data);
void pop(arrStack aStack);
int isEmptyStack(arrStack aStack);
void releaseStack(arrStack aStack);//���
dataType topElement(arrStack aStack);
void freeStack(arrStack aStack);
void printStack(arrStack aStack);