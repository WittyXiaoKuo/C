//（动态）顺序表
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;//数组指针
	int size;//有效数据个数
	int capacity;//空间大小
}SL;
//顺序表的格式化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//顺序表的销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
//扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		//申请空间
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
//顺序表的插入（尾插）
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);//判断空间是否充足，从而进行扩容
	ps->arr[ps->size++] = x;
}
//顺序表的插入（头插）
void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	////将数组后移一位（法一）
	memmove(ps->arr + 1, ps->arr, ps->size++ * sizeof(SLDataType));
	////将数组后移一位（法二）
	//for (int i = ps->size++; i >0; i--)
	//{
	//	ps->arr[i] = ps->arr[i-1];
	//}
	ps->arr[0] = x;
}
//顺序表的删除（尾删）
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}
//顺序表的删除（头删）
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	//将数组前移一位（法一）
	memmove(ps->arr, ps->arr + 1, ps->size-- * sizeof(SLDataType));
	////将数组后移一位（法二）
	//for (int i = 0; i < ps->size--; i++)
	//{
	//	ps->arr[i] = ps->arr[i + 1];
	//}
}
//顺序表指定位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps && (pos >= 0 && pos <= ps->size));
	SLCheckCapacity(ps);
	memmove(ps->arr + pos + 1, ps->arr + pos, (ps->size++ - pos) * sizeof(SLDataType));
	ps->arr[pos] = x;
}
//顺序表指定位置删除数据
void SLErase(SL* ps, int pos)
{
	assert(ps && (pos >= 0 && pos <= ps->size));
	memmove(ps->arr + pos - 1, ps->arr + pos, (ps->size-- - pos) * sizeof(SLDataType));
}
//顺序表查找指定数据
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
//打印
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
