#include "list.h"
#include "mystack.h"

int main() {
	//List myList;
	Stack myStack;
	myStack = createStack();
	for (int i = 0; i < 10; i++) 
	{
		push(myStack, i);
	}
	printStack(myStack);
	printf("%d\n",topElement(myStack));

	for (int i = 0; i < 5; i++)
	{
		pop(myStack);
	}
	printf("%d\n", topElement(myStack));
	printStack(myStack);

	releaseStack(myStack);
	printStack(myStack);

	freeStack(myStack);
	printStack(myStack);

	return 0;
}