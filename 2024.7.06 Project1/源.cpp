int main()
{
	int a = 0;

	int& b = a;//�����﷨�ϲ������¿ռ�

	int* pa = &a;//ָ��Ҫ���ٿռ�
	//�ӻ������������ú�ָ�뼸��һ��
	int c = 0;

	int* p1 = NULL;
	const int& pb = *p1;//�����ڻ�����û�н����õĴ���

	//cout << pb << endl;//�����н����õ�����,�����ҵ�
	cout << sizeof(b) <<endl;
	cout << sizeof(int&) <<endl;

	char a1 = 'w';
	char& b1 = a1;
	cout << sizeof(b1) << endl;//�������͵Ĵ�Сȡ���������õĶ�������ʹ�С,�˴���ָ�벻ͬ
	return 0;
}
