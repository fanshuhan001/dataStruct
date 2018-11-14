#include "list.h"
#include "mystack.h"

int main() {
	//List myList;
	//Stack myStack;
	arrStack myStack;
	myStack = createArrStack(10);
	for (int i = 0; i < 10; i++) 
	{
		push(myStack, i);
		//printf("%d\n", topElement(myStack));
	}
	printf("--------------");
	printStack(myStack);
	printf("--------------");

	printf("%d\n",topElement(myStack));
	printf("--------------");

	for (int i = 0; i < 5; i++)
	{
		pop(myStack);
		printf("%d ", topElement(myStack));
	}
	push(myStack, 15);
	push(myStack, 25);
	printf("\n--------------");
	printf("%d\n", topElement(myStack));
	printf("--------------");
	printStack(myStack);
	printf("--------------");
	releaseStack(myStack);
	printStack(myStack);

	freeStack(myStack);
	push(myStack, 5);
	printStack(myStack);

	return 0;
}