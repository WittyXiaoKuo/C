//ȱʡ����(���������Ͷ���ͬʱ��,������ʱ��)
//ȫȱʡ����
void F1(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl << endl;
}
//��ȱʡ����(���������������ȱ)
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

