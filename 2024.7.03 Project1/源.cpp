//引用做参数
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 19, b = 91;
	Swap(a, b);
	printf("%d %d", a, b);
	return 0;
}
