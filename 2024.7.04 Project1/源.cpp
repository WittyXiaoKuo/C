int main()
{
	//Ȩ�޵ķ���
	// mֻ�ܶ�
	// n����ҵı���,�ɶ���д,Ȩ�޵ķŴ�,������
	//const int m = 0;
	////int& n = m;
	

	//Ȩ�޵�ƽ��,����
	//const int m = 0;
	//const int& n = m;


	////Ȩ�޵�ƽ��,����
	int q5 = 0;
	int& p5 = q5;


	//Ȩ�޵���С,����
	int a = 0;//�ɶ���д
	const int& b = a;//�ɶ�


	//Ȩ����С
	int q = 0;//�ɶ���д
	int& p = q;//�ɶ���д
	const int& w = p;//ֻ�ǲ���ͨ��wȥ�޸�(�ɶ�)
	p++;


	// p1�����޸� *p1�����ԣ�const�����ǵ�*p1
	const int m = 0;//�ɶ�
	const int* p1 = &m;//�ɶ�
	p1++;
	// Ȩ�޵ķŴ�
	//int* p2 = p1;//�ɶ���д
	//Ȩ�޵�ƽ��
	const int* p2 = p1;
	p2++;

	// Ȩ�޵���С
	int x = 0;//�ɶ���д
	int* p3 = &x;//�ɶ���д
	const int* p4 = p3;//�ɶ�

	return 0;	
}
