bool TestAuto()
{
	return true;
}
int main()
{
	int a = 10;
	//auto���Զ�ʶ��������ݵ�����,��������ܳ����͵Ķ���,ʹ��auto�������ʱ���������г�ʼ��
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//typeid()name()���Բ鿴��������
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	return 0;
}