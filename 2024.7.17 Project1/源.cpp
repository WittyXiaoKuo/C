#include"Stack.h"
#pragma pack(1)//�޸�Ĭ�϶�����
//struct Stack
//{
//	int* _a;
//	int _top;
//	int _capacity;
//};

//class A3//����Ĵ�С��1���ֽ�,��һ���ֽڲ��洢��Ч����,������ʶ���󱻶������
//{
//	int a;
//};
int main()
{
	// �� -> ����   1->��
	// �����ʵ����
	// �����ռ�õĴ�С��ֻ���ǳ�Ա����
	Stack st1;
	Stack st2;
	st1.Init();
	st2.Init();

	cout << sizeof(st1) << endl;//�����ռ�ô�С,ֻ���ǳ�Ա����
	cout << sizeof(Stack) << endl;
	//cout << sizeof(A3) << endl;

	return 0;
}