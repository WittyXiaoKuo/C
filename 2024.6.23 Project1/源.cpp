//栈
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int STDateType;
typedef struct stack
{
	STDateType* a;//数组指针
	int top;//栈顶
	int capacity;//空间大小
}ST;
void STInit(ST* pst)//栈的初始化
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
void STPush(ST* pst, STDateType x)//入栈
{
	assert(pst);
	if (pst->capacity == pst->top)//需要扩容
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDateType* tmp = (STDateType*)realloc(pst->a, newcapacity * sizeof(STDateType));
		if (!tmp)
		{
			printf("realloc fail\n");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top++] = x;
}
void STPop(ST* pst)//出栈
{
	assert(pst);
	pst->top--;
}
STDateType STTop(ST* pst)//获取栈顶元素
{
	assert(pst && pst->top > 0);
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst)//判断栈是否为空
{
	assert(pst);
	return pst->top == 0;
}
int STsize(ST* pst)//获取栈内数据个数
{
	assert(pst);
	return pst->top;
}
void STDestroy(ST* pst)//栈的销毁
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
int main()
{
	ST st;
	STInit(&st);//栈的初始化
	STPush(&st, 1);//入栈
	STPush(&st, 2);
	printf("%d ", STTop(&st));
	STPop(&st);
	STPush(&st, 3);
	STPush(&st, 4);
	//while (!STEmpty(&st))//判空
	//{
	//	printf("%d ", STTop(&st));
	//	STPop(&st);
	//}
	int ret = STsize(&st);//获取栈内数据个数
	printf("%d ", ret);
	STDestroy(&st);//栈的销毁
	return 0;
}
