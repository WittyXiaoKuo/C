int main()
{
	//1. auto������Ϊ�����Ĳ���
	//2. auto����ֱ��������������
	int x = 10;

	//�ȼ�
	auto a = &x;
	auto* b = &x;

	//�ȼ�
	auto a = x;//(int)
	auto b = &x;//(int*)

	//�ұ߱�����ָ��
	auto* c = &a;

	//����
	auto& d = x;
}