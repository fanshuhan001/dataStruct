//��ϰ���ݽṹ��Cʵ�ַ�ʽ
//author:  FAN SHUHAN
//2018-11-9

#include <stdlib.h>
#include <stdio.h>

typedef int dataType;
//��list
typedef struct Node
{
	dataType data;
	Node *next;
} Node;

//ypedef Node *List;//list��һ��ָ��node��ָ��

//��ʼ���������������ͷָ���
void initList(Node*pHead) 
{
	pHead = NULL;
}
	


//����һ���µ����������������Ϊ����ʱ����ɴ���,�����һ���ڵ������һ��Ϊ����
Node* creatList(Node *pHead)
{
	Node *aNode, *tempNode;
	
	//�����ڴ��aNode
	aNode = (Node*)malloc(sizeof(Node));

	//�������Ƿ���ȷ������ȷ���׳�����
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
		//�������ڴ��aNode�����
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
//��ɾ���
//������ĩ�����һ���µĽڵ�
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

	//�ҵ����һ���ڵ�
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	pHead->next = aNode;

}

//�ж�һ�������ǲ��ǿ���������ǿ������򷵻�1��true����C��û��bool����ò��
int isEmptyList(Node * pHead)
{
	return pHead->next == NULL ? 1 : 0;
}

//ɾ����ɾ��һ��ָ����ֵ�������ֵ�����ڣ����ӡ���ѣ�����ɾ���������
//�������޸������Ƶģ��ҵ������ݣ��޸Ļ򷵻���
Node *deleteNode(Node *pHead, dataType data)
{
	Node *currentNode = NULL;//��Ǳ�ɾ���Ľڵ㣬�Է���free
	Node *previousNode = NULL;//���ǰһ��node
	
	//judge the list is empty or not
	if (isEmptyList(pHead))
	{
		printf("empty list@@!");
		return pHead;
	}

	//��ʼ�������ǰ�ڵ���ǰ��ڵ���ͬ
	previousNode = currentNode = pHead;

	//�ҵ�ָ�����ݣ�����
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

//�����������
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