#include<iostream>
using namespace std;
int main()
{
	//"<<"������
	int i = 1;
	double j = 1.9154684651;
	//��ͬ��printf,������������
	cout << i << "��" << j << "��" << endl;
	//"precision"����ȷ������
	std::cout.precision(5);
	cout << i << " " << j << endl;
	//">>"����ȡ
	//��ͬ��scanf,�������������Ҳ���'&'
	std::cin >> i >> j;
	cout << i << " " << j << endl;
}
