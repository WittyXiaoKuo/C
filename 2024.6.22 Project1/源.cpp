//˫���ͷѭ������
#include<stdlib.h>
#include<assert.h>
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;
ListNode* BuyListNode(LTDateType x)//�����ڵ�
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
ListNode* ListInit()//��ʼ������
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void Listprint(ListNode* phead)//��ӡ����
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
void ListInsert(ListNode* pos, LTDateType x)//��ָ��λ�ò������ݣ���һ����λ�ã�
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListInsert2(ListNode* phead, LTDateType k, LTDateType x)//��ָ��λ�ò������ݣ������������ݣ�
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
void ListErase(ListNode* pos)//��ָ��λ��ɾ������
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void ListPushBack(ListNode* phead, LTDateType x)//β��
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
void ListPushFront1(ListNode* phead, LTDateType x)//ͷ�巨һ��������������
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
void ListPushFront2(ListNode* phead, LTDateType x)//ͷ�巨������˳���ܸı䣩
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	ListInsert(phead->next, x);
}
void ListPopFront(ListNode* phead)//ͷɾ
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
void ListPopBack(ListNode* phead)//βɾ
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
ListNode* ListFind(ListNode* phead, LTDateType x)//���Ҳ��޸�
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
void ListDestroy(ListNode* phead)//��������
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
	ListNode* plist = ListInit();//��ʼ��
	// //β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//Listprint(plist);
	// //ͷ��
	// //��һ��
	//ListPushFront1(plist, 0);
	//Listprint(plist);
	// //������
	//ListPushFront2(plist, 0);
	//Listprint(plist);
	// //ͷɾ
	//ListPopFront(plist);
	//Listprint(plist);
	// //βɾ
	//ListPopBack(plist);
	//Listprint(plist);
	// //���Ҳ��޸�
	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		pos->val = 666;
		printf("�ҵ���\n");
	}
	else
	{
		printf("û���ҵ�\n");
	}
	Listprint(plist);
	Listprint(pos);
	// //��ָ��λ�ò�������
	// ��һ��
	//ListNode* pos = ListFind(plist, 3);
	//ListInsert(pos, 30);
	//Listprint(plist);
	//������
	//ListInsert2(plist,9,30);
	//Listprint(plist);
	// //��ָ��λ��ɾ������
	//ListNode* pos = ListFind(plist, 2);
	//ListErase(pos);
	//Listprint(plist);
	// //��������
	ListDestroy(plist);
	return 0;
}
