//��ֵ���������ܵıȽ�
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
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < N; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < N; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
int main()
{
	TestRefAndValue();
	return 0;
}
