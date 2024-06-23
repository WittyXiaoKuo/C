//ջ
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int STDateType;
typedef struct stack
{
	STDateType* a;//����ָ��
	int top;//ջ��
	int capacity;//�ռ��С
}ST;
void STInit(ST* pst)//ջ�ĳ�ʼ��
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
void STPush(ST* pst, STDateType x)//��ջ
{
	assert(pst);
	if (pst->capacity == pst->top)//��Ҫ����
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
void STPop(ST* pst)//��ջ
{
	assert(pst);
	pst->top--;
}
STDateType STTop(ST* pst)//��ȡջ��Ԫ��
{
	assert(pst && pst->top > 0);
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst)//�ж�ջ�Ƿ�Ϊ��
{
	assert(pst);
	return pst->top == 0;
}
int STsize(ST* pst)//��ȡջ�����ݸ���
{
	assert(pst);
	return pst->top;
}
void STDestroy(ST* pst)//ջ������
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
int main()
{
	ST st;
	STInit(&st);//ջ�ĳ�ʼ��
	STPush(&st, 1);//��ջ
	STPush(&st, 2);
	printf("%d ", STTop(&st));
	STPop(&st);
	STPush(&st, 3);
	STPush(&st, 4);
	//while (!STEmpty(&st))//�п�
	//{
	//	printf("%d ", STTop(&st));
	//	STPop(&st);
	//}
	int ret = STsize(&st);//��ȡջ�����ݸ���
	printf("%d ", ret);
	STDestroy(&st);//ջ������
	return 0;
}
