//队列
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int QDataType;
typedef struct QListNode//队列
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
void QueueInit(Queue* pq)//队列初始化
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq,QDataType x)//队尾入列
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
void QueuePop(Queue* pq)//队头出列
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
QDataType QueueFront(Queue* pq)//访问队头元素
{
	assert(pq);
	return pq->phead->val;
}
QDataType QueueBack(Queue* pq)//访问队尾元素
{
	assert(pq&&pq->size>0);
	return pq->ptail->val;
}
bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);
	return pq->size == 0;
}
int QueueSize(Queue*pq)//计算队列长度
{
	assert(pq);
	return pq->size;
}
void QueueDestroy(Queue* pq)//队列的销毁
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
	QueueInit(&q);//初始化
	QueuePush(&q, 1);//队尾入列
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));//访问队尾元素
		QueuePop(&q);//对头出列
	}
	//printf("%d\n", QueueBack(&q));//访问队尾元素
	//QueueEmpty(&q);//判断队列是否为空
	//QueueSize(&q);//计算队列长度
	QueueDestroy(&q);//队列的销毁
	return 0;
}
