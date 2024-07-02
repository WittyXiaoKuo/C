//缺省参数(不能声明和定义同时给,在声明时给)
//全缺省参数
void F1(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl << endl;
}
//半缺省参数(必须从右往左依次缺)
void F2(int a, int b = 20, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl << endl;
}
int main()
{
	F1(1, 2, 3);
	F1(1, 2);
	F1(1);
	F1();

	F2(1, 2, 3);
	F2(1, 2);
	F2(1);
}

