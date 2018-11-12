//练习数据结构的C实现方式
//author:  FAN SHUHAN
//2018-11-9

#include <stdlib.h>
#include <stdio.h>

typedef int dataType;
//表、list
typedef struct Node
{
	dataType data;
	Node *next;
} Node;

//ypedef Node *List;//list是一个指向node的指针

//初始化链表，即将链表表头指向空
void initList(Node*pHead) 
{
	pHead = NULL;
}
	


//创建一个新的链表，当输入的数据为负数时，完成创建,即最后一个节点的数据一定为负数
Node* creatList(Node *pHead)
{
	Node *aNode, *tempNode;
	
	//分配内存给aNode
	aNode = (Node*)malloc(sizeof(Node));

	//检测分配是否正确，不正确则抛出错误
	if (NULL == aNode)
	{
		printf("memory allocation error 1");
		exit(-1);
	}
	tempNode = aNode;

	scanf_s("%d", &aNode->data);
	if (aNode->data < 0) 
	{
		printf("fail! data < 0, finish creating.\n");
		return pHead;
	}

	aNode->next = NULL;
	pHead = aNode;

	while (aNode->data > 0)
	{
		//分配新内存给aNode并检测
		aNode = (Node*)malloc(sizeof(Node));
		if (NULL == aNode)
		{
			printf("memory allocation error 1\n");
			exit(-1);
		}

		scanf_s("%d", &aNode->data);
		aNode->next = NULL;
		tempNode->next = aNode;
		tempNode = aNode;
		
	}
	printf("done!\n");
	return pHead;
}

void printList(Node * pHead)
{
	//Node *resentNode;
	int i = 0;

	if (pHead == NULL)
	{
		printf("a empty list!\n");
		//return;
	}
	else
	{
		while (pHead != NULL)
		{
			printf("%d", pHead->data);
			i++;
			(i % 5 == 0) ? printf("\n") : printf(" ");
			pHead = pHead->next;
		}
	}
	printf("\n");
	
}
//增删查改
//往链表末端添加一个新的节点
Node *insert(Node *pHead, dataType data)
{
	Node *aNode;
	aNode = (Node*)malloc(sizeof(Node));
	if (aNode == NULL)
	{
		printf("memory error 1!\n");
		exit(-1);
	}
	aNode->data = data;
	aNode->next = NULL;

	//找到最后一个节点
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	pHead->next = aNode;

}

//判断一个链表是不是空链表，如果是空链表，则返回1（true）；C中没有bool类型貌似
int isEmptyList(Node * pHead)
{
	return pHead->next == NULL ? 1 : 0;
}

//删除，删除一个指定的值，如果该值不存在，则打印提醒；返回删除后的链表
//查找与修改是类似的，找到该数据，修改或返回他
Node *deleteNode(Node *pHead, dataType data)
{
	Node *currentNode = NULL;//标记被删除的节点，以方便free
	Node *previousNode = NULL;//标记前一个node
	
	//judge the list is empty or not
	if (isEmptyList(pHead))
	{
		printf("empty list@@!");
		return pHead;
	}

	//初始情况，当前节点与前序节点相同
	previousNode = currentNode = pHead;

	//找到指定数据，或者
	while ((currentNode != NULL) && (currentNode->data != data))
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	//
	if (currentNode == NULL) 
	{
		printf("List doesn't include this value\n");
	}
	else if (previousNode == currentNode)
	{
		pHead = currentNode->next;
		free(currentNode);
	}
	else
	{
		previousNode->next = currentNode->next;
		free(currentNode);
	}
	return pHead;
}

//清空整个链表
void clearList(Node *pHead)
{
	Node *temp = NULL;
	if (isEmptyList(pHead)) 
	{
		printf("empty list");
		return;
	}

	while (pHead != NULL)
	{
		temp = pHead;
		free(temp);
		pHead = pHead->next;
		
	}
}


int main() 
{
	Node* myList = NULL;

	initList(myList);
	myList = creatList(myList);
	//printList(myList);
	insert(myList,5);
	insert(myList, 9);
	insert(myList, 12);
	printList(myList);
	myList = deleteNode(myList, 5);
	printList(myList);
	myList = deleteNode(myList, 3);
	printList(myList);
	myList = deleteNode(myList, 1);
	printList(myList);
	clearList(myList);
	if (isEmptyList(myList)) printf("1!");
	//printList(myList);

	return 1;
}