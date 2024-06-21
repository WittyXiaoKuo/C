//������ͷ��ѭ������
#include<stdlib.h>
#include<assert.h>
typedef int NodeDataType;
typedef struct Node//����
{
	NodeDataType val;
	struct Node* next;
}Node;

Node* createNode(NodeDataType x)//�����ڵ�
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		perror("malloc fail");
		exit(1);
	}
	p->val = x;
	p->next = NULL;
	return p;
}
void printfList(Node* p)//��ӡ����
{
	Node* cur = p;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
void pushFront(Node** pphead, NodeDataType d)//ͷ��
{
	Node* newNode = createNode(d);
	newNode->next = *pphead;
	*pphead = newNode;
}
void pushBack(Node** pphead, NodeDataType d)//β��
{
	Node* newNode = createNode(d);
	if (*pphead == NULL)//������
	{
		*pphead = newNode;
	}
	else//�ǿ�����
	{
		Node* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void popFront(Node** pphead)//ͷɾ
{
	assert(*pphead);
	Node* del = *pphead;
	*pphead = (*pphead)->next;//del->next
	free(del);
	del = NULL;
}
void popBack(Node** pphead)//βɾ
{
	assert(*pphead);
	if ((*pphead)->next == NULL)//һ���ڵ�����
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//����һ���ڵ�����
	{
		Node* tail = *pphead;
		//����Ҫɾ�����һ���ڵ㣬��Ҫ��ǰһ���ڵ��next�ÿ�
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
Node* FindList(Node* phead, NodeDataType d)//�ҳ�ָ������
{
	assert(phead);
	Node* cur = phead;
	while (cur)
	{
		if (cur->val == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��һ��
void InsertList1(Node** pphead, NodeDataType d, NodeDataType x)//��ָ��λ�ò�������
{
	assert(*pphead);
	Node* newnode = createNode(x);
	Node* per = *pphead;
	if ((*pphead)->val == d)//�൱��ͷ�壨�ڵ�һ���ڵ�ǰ���룩
	{
		pushFront(pphead, x);
		//newnode->next = *pphead;
		//*pphead = newnode;
	}
	else//������λ�ò��룩
	{
		Node* cur = NULL;
		while (per->val != d)
		{
			cur = per;
			per = per->next;
		}
		cur->next = newnode;
		newnode->next = per;
	}
}
//������
void InsertList2(Node** pphead, Node* pos, NodeDataType x)//��ָ��λ�ò�������
{
	assert(*pphead);
	Node* newnode = createNode(x);
	Node* per = *pphead;
	if (*pphead == pos)//�൱��ͷ�壨�ڵ�һ���ڵ�ǰ���룩
	{
		pushFront(pphead, x);
	}
	else//������λ�ò��룩
	{
		while (per->next != pos)
		{
			per = per->next;
		}
		per->next = newnode;
		newnode->next = pos;
	}
}
void deleteNode(Node** pphead, NodeDataType k)//ɾ��ָ��Ԫ��
{
	assert(*pphead);
	Node* cur = *pphead;
	if (cur->val == k)//Ҫɾ����Ԫ���ǵ�һ���ڵ�
	{
		*pphead = cur->next;
		free(cur);
		cur = NULL;
		return;
	}
	Node* prev = NULL;//Ҫɾ����Ԫ�ز��ǵ�һ��Ԫ��
	while (cur->val != k && cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		return;
	}
	else
	{
		prev->next = cur->next;
		free(cur);
		cur = NULL;
	}
}
int lenList1(Node* phead, int count)//���������
{
	while (phead != NULL)
	{
		count++;
		phead = phead->next;
	}
	return count;
}
//void lenList2(Node* phead, int* count)
//{
//	while (phead != NULL)
//	{
//		(*count)++;
//		phead = phead->next;
//	}
//}
void DestroyList(Node* phead)//���������
{
	Node* cur = phead;
	while (cur != NULL)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}
int main()
{
	// //�����ڵ�
	//Node* p1 = createNode(1);
	//Node* p2 = createNode(2);
	//Node* p3 = createNode(3);
	//Node* p4 = createNode(4);
	//p1->next = p2;//���ӽڵ�
	//p2->next = p3;
	//p3->next = p4;
	//printfList(p1);//��ӡ����
	// //ͷ��
	//Node* phead = NULL;//������
	//pushFront(&phead, 1);
	//pushFront(&phead, 2);
	//pushFront(&phead, 3);
	//pushFront(&phead, 4);
	//printfList(phead);
	// //β��
	Node* phead = NULL;//������
	pushBack(&phead, 1);
	pushBack(&phead, 2);
	pushBack(&phead, 3);
	pushBack(&phead, 4);
	//printfList(phead);
	// //ͷɾ
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	////βɾ
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	////�ҳ�ĳ������
	//Node*ret = FindList(phead, 4);
	//printfList(ret);
	//��ָ��λ�ò�������
	//��һ��
	InsertList1(&phead, 1, 30);
	printfList(phead);
	////������
	//Node* pos = FindList(phead, 3);
	//InsertList2(&phead, pos, 30);
	//printfList(phead);
	// //ָ��ɾ��Ԫ��
	//deleteNode(&phead, 3);
	//printfList(phead);
	// //��������
	//// ��һ��
	//int count = 0,ret=0;
	//ret=lenList1(phead, count);
	//printf("%d\n", ret);
	////������
	//int count = 0;
	//lenList2(phead, &count);
	//printf("%d\n", count);
	// //���������
	DestroyList(phead);
	return 0;
}
