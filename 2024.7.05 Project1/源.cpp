//传值和引用性能的比较
#define N 100000
#include<iostream>
using namespace std;
#include<cassert>
#include <ctime>
struct A { int a[N]; };

void TestFunc1(A a) {}
void TestFunc2(A& a) {}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < N; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < N; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
int main()
{
	TestRefAndValue();
	return 0;
}
