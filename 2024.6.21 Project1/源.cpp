//单向无头不循环链表
#include<stdlib.h>
#include<assert.h>
typedef int NodeDataType;
typedef struct Node//链表
{
	NodeDataType val;
	struct Node* next;
}Node;

Node* createNode(NodeDataType x)//创建节点
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
void printfList(Node* p)//打印链表
{
	Node* cur = p;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
void pushFront(Node** pphead, NodeDataType d)//头插
{
	Node* newNode = createNode(d);
	newNode->next = *pphead;
	*pphead = newNode;
}
void pushBack(Node** pphead, NodeDataType d)//尾插
{
	Node* newNode = createNode(d);
	if (*pphead == NULL)//空链表
	{
		*pphead = newNode;
	}
	else//非空链表
	{
		Node* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void popFront(Node** pphead)//头删
{
	assert(*pphead);
	Node* del = *pphead;
	*pphead = (*pphead)->next;//del->next
	free(del);
	del = NULL;
}
void popBack(Node** pphead)//尾删
{
	assert(*pphead);
	if ((*pphead)->next == NULL)//一个节点的情况
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//多于一个节点的情况
	{
		Node* tail = *pphead;
		//不仅要删除最后一个节点，还要让前一个节点的next置空
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
Node* FindList(Node* phead, NodeDataType d)//找出指定数据
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
//法一：
void InsertList1(Node** pphead, NodeDataType d, NodeDataType x)//在指定位置插入数据
{
	assert(*pphead);
	Node* newnode = createNode(x);
	Node* per = *pphead;
	if ((*pphead)->val == d)//相当于头插（在第一个节点前插入）
	{
		pushFront(pphead, x);
		//newnode->next = *pphead;
		//*pphead = newnode;
	}
	else//在其他位置插入）
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
//法二：
void InsertList2(Node** pphead, Node* pos, NodeDataType x)//在指定位置插入数据
{
	assert(*pphead);
	Node* newnode = createNode(x);
	Node* per = *pphead;
	if (*pphead == pos)//相当于头插（在第一个节点前插入）
	{
		pushFront(pphead, x);
	}
	else//在其他位置插入）
	{
		while (per->next != pos)
		{
			per = per->next;
		}
		per->next = newnode;
		newnode->next = pos;
	}
}
void deleteNode(Node** pphead, NodeDataType k)//删除指定元素
{
	assert(*pphead);
	Node* cur = *pphead;
	if (cur->val == k)//要删除的元素是第一个节点
	{
		*pphead = cur->next;
		free(cur);
		cur = NULL;
		return;
	}
	Node* prev = NULL;//要删除的元素不是第一个元素
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
int lenList1(Node* phead, int count)//求出链表长度
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
void DestroyList(Node* phead)//链表的销毁
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
	// //创建节点
	//Node* p1 = createNode(1);
	//Node* p2 = createNode(2);
	//Node* p3 = createNode(3);
	//Node* p4 = createNode(4);
	//p1->next = p2;//链接节点
	//p2->next = p3;
	//p3->next = p4;
	//printfList(p1);//打印链表
	// //头插
	//Node* phead = NULL;//空链表
	//pushFront(&phead, 1);
	//pushFront(&phead, 2);
	//pushFront(&phead, 3);
	//pushFront(&phead, 4);
	//printfList(phead);
	// //尾插
	Node* phead = NULL;//空链表
	pushBack(&phead, 1);
	pushBack(&phead, 2);
	pushBack(&phead, 3);
	pushBack(&phead, 4);
	//printfList(phead);
	// //头删
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	//popFront(&phead);
	//printfList(phead);
	////尾删
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	//popBack(&phead);
	//printfList(phead);
	////找出某个数据
	//Node*ret = FindList(phead, 4);
	//printfList(ret);
	//在指定位置插入数据
	//法一：
	InsertList1(&phead, 1, 30);
	printfList(phead);
	////法二：
	//Node* pos = FindList(phead, 3);
	//InsertList2(&phead, pos, 30);
	//printfList(phead);
	// //指定删除元素
	//deleteNode(&phead, 3);
	//printfList(phead);
	// //求链表长度
	//// 法一：
	//int count = 0,ret=0;
	//ret=lenList1(phead, count);
	//printf("%d\n", ret);
	////法二：
	//int count = 0;
	//lenList2(phead, &count);
	//printf("%d\n", count);
	// //链表的销毁
	DestroyList(phead);
	return 0;
}
