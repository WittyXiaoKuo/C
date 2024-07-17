#include"Stack.h"
#pragma pack(1)//修改默认对齐数
//struct Stack
//{
//	int* _a;
//	int _top;
//	int _capacity;
//};

//class A3//空类的大小是1个字节,这一个字节不存储有效数据,用来标识对象被定义出来
//{
//	int a;
//};
int main()
{
	// 类 -> 对象   1->多
	// 对象的实例化
	// 对象的占用的大小，只考虑成员变量
	Stack st1;
	Stack st2;
	st1.Init();
	st2.Init();

	cout << sizeof(st1) << endl;//对象的占用大小,只考虑成员变量
	cout << sizeof(Stack) << endl;
	//cout << sizeof(A3) << endl;

	return 0;
}