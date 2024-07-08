#define Swap(a,b) {int tmp=a;a=b;b=tmp;}
#define ADD(a,b) ((a)+(b))
int main()
{
	int a = 0;
	int b = 10;
	cout << Swap(a, b) << endl;
	cout << ADD(a, b) << endl;
}
//频繁调用的小函数
//C->宏函数
//C++->内联函数
