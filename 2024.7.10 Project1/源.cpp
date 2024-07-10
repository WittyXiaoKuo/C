int main()
{
	//1. auto不能作为函数的参数
	//2. auto不能直接用来声明数组
	int x = 10;

	//等价
	auto a = &x;
	auto* b = &x;

	//等价
	auto a = x;//(int)
	auto b = &x;//(int*)

	//右边必须是指针
	auto* c = &a;

	//引用
	auto& d = x;
}