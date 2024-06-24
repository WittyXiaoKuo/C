//����
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int QDataType;
typedef struct QListNode//����
{
	struct QListNode* next;
	QDataType val;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
void QueueInit(Queue* pq)//���г�ʼ��
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq,QDataType x)//��β����
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)//��ͷ����
{
	assert(pq&&pq->size!=0);
	//Queue* next = pq->phead->next;
	//free(pq->phead);
	//pq->phead = next;
	//if (pq->phead == pq->ptail)
	//{
	//	pq->phead = pq->ptail = NULL;
	//}
	//pq->size--;
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}
QDataType QueueFront(Queue* pq)//���ʶ�ͷԪ��
{
	assert(pq);
	return pq->phead->val;
}
QDataType QueueBack(Queue* pq)//���ʶ�βԪ��
{
	assert(pq&&pq->size>0);
	return pq->ptail->val;
}
bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
	assert(pq);
	return pq->size == 0;
}
int QueueSize(Queue*pq)//������г���
{
	assert(pq);
	return pq->size;
}
void QueueDestroy(Queue* pq)//���е�����
{
	assert(pq);
	while (pq->phead)
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead=next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
int main()
{
	Queue q;
	QueueInit(&q);//��ʼ��
	QueuePush(&q, 1);//��β����
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));//���ʶ�βԪ��
		QueuePop(&q);//��ͷ����
	}
	//printf("%d\n", QueueBack(&q));//���ʶ�βԪ��
	//QueueEmpty(&q);//�ж϶����Ƿ�Ϊ��
	//QueueSize(&q);//������г���
	QueueDestroy(&q);//���е�����
	return 0;
}
