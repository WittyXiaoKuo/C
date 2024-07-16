#pragma once
#include<iostream>
using namespace std;
int main()
{
	int a[6] = {8,5,7,8,5,7};
	for (auto elem : a)
	{
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}