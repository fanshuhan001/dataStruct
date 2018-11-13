#include "mystack.h"

int isEmptyStack(Stack aStack) {
	if (aStack == NULL)
	{
		printf("this stack should be created first!\n");
		return -1;
	}
	else if (aStack->next == NULL)
	{
		return 1;
	}
	else return 0;
}

//创建一个空的列表（栈），第一个节点为标记-、-header,而不是第一个节点
Stack createStack(void) 
{
	Stack newStack;

	newStack = (Stack)malloc(sizeof(sNode));
	if (newStack == NULL) 
	{
		printf("error 1, no more memory");
		exit(-1);
	}

	newStack->next = NULL;
}

//压栈，放入最前段
void push(Stack aStack, dataType data) 
{
	Stack newStack;

	newStack = (Stack)malloc(sizeof(sNode));
	if (newStack == NULL) 
	{
		printf("error 1, no more memory");
		exit(-1);
	}
	else
	{
		newStack->data = data;
		newStack->next = aStack->next;
		aStack->next = newStack;
	}
}



void pop(Stack aStack) 
{
	if (isEmptyStack(aStack))
	{
		printf("empty stack, cann't pop!\n");
		return;
	}
	
	Stack tempStack;

	tempStack = aStack->next;
	aStack->next = tempStack->next;
	free(tempStack);
}

//清空
void releaseStack(Stack aStack) 
{
	while (!isEmptyStack(aStack)) pop(aStack);
}

dataType topElement(Stack aStack) 
{
	if (!isEmptyStack(aStack)) return aStack->next->data;
}

//删除这栈
void freeStack(Stack aStack) 
{
	releaseStack(aStack);
	free(aStack);
}

void printStack(Stack aStack)
{
	//Node *resentNode;
	int i = 0;

	if (aStack->next == NULL)
	{
		printf("a empty list!\n");
		//return;
	}
	else
	{
		while (aStack->next != NULL)
		{
			printf("%d", aStack->next->data);
			i++;
			(i % 5 == 0) ? printf("\n") : printf(" ");
			aStack = aStack->next;
		}
		printf("\n");
	}
}
