#include<stdio.h>
#include<stdlib.h>
namespace bit//�Զ��������ռ�
{
	int rand = 0;
}
//�������޶���"::"ǰ��Ϊ��Ĭ��ȫ����

//// չ�������ռ� (һ�㲻չ��)
////using namespace bit;
// // ����Ĭ�ϲ���˳��
// // a����ǰ�ֲ���				�� ������
// // b��ȫ������				�� ����Ұ��
// // c����չ���������ռ��в���  �� �൱���Ŵ�ү���Լ��������ؼ���������˭��Ҫ����ժ
int main()
{
	int rand = 1;
	printf("%d\n", rand);//�ֲ���
	printf("%d\n", bit::rand);//�Զ�����
	printf("%p\n", ::rand);//ȫ����
	return 0;
}