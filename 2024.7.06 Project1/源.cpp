int main()
{
	int a = 0;

	int& b = a;//引用语法上不开辟新空间

	int* pa = &a;//指针要开辟空间
	//从汇编层面来看引用和指针几乎一致
	int c = 0;

	int* p1 = NULL;
	const int& pb = *p1;//这里在汇编层面没有解引用的存在

	//cout << pb << endl;//这里有解引用的作用,程序会挂掉
	cout << sizeof(b) <<endl;
	cout << sizeof(int&) <<endl;

	char a1 = 'w';
	char& b1 = a1;
	cout << sizeof(b1) << endl;//引用类型的大小取决于所引用的对象的类型大小,此处与指针不同
	return 0;
}
