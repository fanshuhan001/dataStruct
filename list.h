#include <stdlib.h>
#include <stdio.h>

typedef int dataType;
//±í¡¢list
typedef struct Node
{
	dataType data;
	Node *next;
} Node;

typedef Node * List;

List initList();
void deleteList(Node *pHead);
Node *deleteNode(Node *pHead, dataType data);
int isEmptyList(Node * pHead);
void add(Node *pHead, dataType data);
void printList(Node * pHead);
Node* createList(Node *pHead);