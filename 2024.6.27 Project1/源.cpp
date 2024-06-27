//堆（二叉树）
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
void HPInit(HP* php)//堆的初始化
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HPDestroy(HP* php)//堆的销毁
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void Swap(HPDataType* p1, HPDataType* p2)//交换
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])//小堆
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HPPush(HP* php, HPDataType x)//插入数据
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (!tmp)
		{
			perror("realloc fail");
			exit(1);
		}
		php->capacity = newcapacity;
		php->a = tmp;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}
void AdjustDown(HPDataType* a, int n, int parent)//向下调整
{
	int child = parent * 2 + 1;//找出最小的孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])//小堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HPPop(HP* php)//删除数据
{
	assert(php && php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HPTop(HP* php)//访问堆顶数据
{
	assert(php && php->size > 0);
	return php->a[0];
}
bool HPEmpty(HP* php)//判断堆是否为空
{
	assert(php);
	return php->size == 0;
}
void HeapSort(int* a, int n)//堆排序
{
	////向上调整建堆(NlogN)
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆(logN)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}
int main()
{
	HP hp;
	HPInit(&hp);//初始化
	int a[] = { 4,2,8,1,5,6,9,7,15,76,84,59,32 };
	int len = sizeof(a) / sizeof(a[0]);
	//	for (size_t i = 0; i < len; i++)
	//	{
	//		HPPush(&hp, a[i]);//插入数据
	//	}
	//	int i = 0;
	//	while (!HPEmpty(&hp))//判空
	//	{
	//		printf("%d ", HPTop(&hp));//访问堆顶数据
	//		//a[i++] = HPTop(&hp);
	//		HPPop(&hp);//删除数据
	//	}
	HeapSort(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
