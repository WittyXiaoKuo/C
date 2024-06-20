//����̬��˳���
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;//����ָ��
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}SL;
//˳���ĸ�ʽ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//˳��������
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
//����
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		//����ռ�
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (!tmp)//!tmp
		{
			perror("realloc file");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}
//˳���Ĳ��루β�壩
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);//�жϿռ��Ƿ���㣬�Ӷ���������
	ps->arr[ps->size++] = x;
}
//˳���Ĳ��루ͷ�壩
void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	////���������һλ����һ��
	memmove(ps->arr + 1, ps->arr, ps->size++ * sizeof(SLDataType));
	////���������һλ��������
	//for (int i = ps->size++; i >0; i--)
	//{
	//	ps->arr[i] = ps->arr[i-1];
	//}
	ps->arr[0] = x;
}
//˳����ɾ����βɾ��
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}
//˳����ɾ����ͷɾ��
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	//������ǰ��һλ����һ��
	memmove(ps->arr, ps->arr + 1, ps->size-- * sizeof(SLDataType));
	////���������һλ��������
	//for (int i = 0; i < ps->size--; i++)
	//{
	//	ps->arr[i] = ps->arr[i + 1];
	//}
}
//˳���ָ��λ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps && (pos >= 0 && pos <= ps->size));
	SLCheckCapacity(ps);
	memmove(ps->arr + pos + 1, ps->arr + pos, (ps->size++ - pos) * sizeof(SLDataType));
	ps->arr[pos] = x;
}
//˳���ָ��λ��ɾ������
void SLErase(SL* ps, int pos)
{
	assert(ps && (pos >= 0 && pos <= ps->size));
	memmove(ps->arr + pos - 1, ps->arr + pos, (ps->size-- - pos) * sizeof(SLDataType));
}
//˳������ָ������
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//��ӡ
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
