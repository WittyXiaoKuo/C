bool TestAuto()
{
	return true;
}
int main()
{
	int a = 10;
	//auto会自动识别后面数据的类型,可以替代很长类型的定义,使用auto定义变量时必须对其进行初始化
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//typeid()name()可以查看数据类型
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	return 0;
}