//双向带头循环链表
#include<stdlib.h>
#include<assert.h>
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;
ListNode* BuyListNode(LTDateType x)//创建节点
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
ListNode* ListInit()//初始化链表
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void Listprint(ListNode* phead)//打印链表
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
void ListInsert(ListNode* pos, LTDateType x)//在指定位置插入数据（法一：传位置）
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListInsert2(ListNode* phead, LTDateType k, LTDateType x)//在指定位置插入数据（法二：传数据）
{
	ListNode* next = phead->next;
	ListNode* pcur = phead;
	ListNode* newnode = (ListNode*)BuyListNode(x);
	while (next->val != k)
	{
		pcur = next;
		next = next->next;
	}
	pcur->next = newnode;
	newnode->prev = pcur;
	newnode->next = next;
	next->prev = newnode;

}
void ListErase(ListNode* pos)//在指定位置删除数据
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void ListPushBack(ListNode* phead, LTDateType x)//尾插
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* tail = phead->prev;
	//tail->next = newnode;;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}
void ListPushFront1(ListNode* phead, LTDateType x)//头插法一：（常规做法）
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* tail = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = tail;z
	//tail->prev = newnode;
	ListInsert(phead->next, x);
}
void ListPushFront2(ListNode* phead, LTDateType x)//头插法二：（顺序不能改变）
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	ListInsert(phead->next, x);
}
void ListPopFront(ListNode* phead)//头删
{
	assert(phead);
	//assert(phead->next != phead);
	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);
}
void ListPopBack(ListNode* phead)//尾删
{
	assert(phead);
	//ListNode* first = phead->prev;
	//ListNode* second = first->prev;
	//phead->prev = second;
	//second->next = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->prev);
}
ListNode* ListFind(ListNode* phead, LTDateType x)//查找并修改
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->val != x && cur != phead)
	{
		cur = cur->next;
	}
	if (cur == phead)
	{
		return NULL;
	}
	else
	{
		return cur;
	}
}
void ListDestroy(ListNode* phead)//销毁链表
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
int main()
{
	ListNode* plist = ListInit();//初始化
	// //尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//Listprint(plist);
	// //头插
	// //法一：
	//ListPushFront1(plist, 0);
	//Listprint(plist);
	// //法二：
	//ListPushFront2(plist, 0);
	//Listprint(plist);
	// //头删
	//ListPopFront(plist);
	//Listprint(plist);
	// //尾删
	//ListPopBack(plist);
	//Listprint(plist);
	// //查找并修改
	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		pos->val = 666;
		printf("找到了\n");
	}
	else
	{
		printf("没有找到\n");
	}
	Listprint(plist);
	Listprint(pos);
	// //在指定位置插入数据
	// 法一：
	//ListNode* pos = ListFind(plist, 3);
	//ListInsert(pos, 30);
	//Listprint(plist);
	//法二：
	//ListInsert2(plist,9,30);
	//Listprint(plist);
	// //在指定位置删除数据
	//ListNode* pos = ListFind(plist, 2);
	//ListErase(pos);
	//Listprint(plist);
	// //销毁链表
	ListDestroy(plist);
	return 0;
}
