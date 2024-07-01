#include<iostream>
using namespace std;
int main()
{
	//"<<"流插入
	int i = 1;
	double j = 1.9154684651;
	//等同于printf,但不限制类型
	cout << i << "生" << j << "世" << endl;
	//"precision"用来确定精度
	std::cout.precision(5);
	cout << i << " " << j << endl;
	//">>"流提取
	//等同于scanf,但不限制类型且不用'&'
	std::cin >> i >> j;
	cout << i << " " << j << endl;
}
