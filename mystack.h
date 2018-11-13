#include <stdlib.h>
#include <stdio.h>

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
void releaseStack(Stack aStack);//Çå¿Õ
dataType topElement(Stack aStack);
void freeStack(Stack aStack);
void printStack(Stack aStack);