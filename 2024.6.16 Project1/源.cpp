//�������ܱȽ�
#include<stdlib.h>
#include<time.h>
//ð������
void BubbleSort(int* a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
//������
void Swap(int* p1, int* p2)//����
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)//���µ���
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])//���
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	//���µ�������(logN)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}
//��������
void InserSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i,tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
				a[end + 1] = a[end--];
			else
				break;
			a[end + 1] = tmp;
		}
	}
}
//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i,tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
				a[end + gap] = tmp;
			}
		}
	}
}
//ѡ������(������)
//void Swap(int* p1, int* p2)//����
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//��������
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
				a[end + 1] = a[end--];
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	 //left midi right
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
			return midi;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else // a[left] > a[midi]
	{
		if (a[midi] > a[right])
			return midi;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	 //С�����Ż������ٵݹ�ָ����򣬼��ٵݹ�Ĵ���
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		 //����ȡ��(Ŀ���Ǳ�����������£�Ч���˻�)
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);
		int keyi = left;
		int begin = left, end = right;
		while (begin < end)
		{
			 //�ұ���С
			while (begin < end && a[end] >= a[keyi])
				--end;
			 //����Ҵ�
			while (begin < end && a[begin] <= a[keyi])
				++begin;
			Swap(&a[begin], &a[end]);
		}
		Swap(&a[keyi], &a[begin]);
		keyi = begin;
		 //[left, keyi-1] keyi [keyi+1, right]
		QuickSort(a, left, keyi - 1);//��
		QuickSort(a, keyi + 1, right);//��
	}
}
void TestOP()//���Ը�������
{
	srand((unsigned int)time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand()+i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InserSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	HeapSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	BubbleSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	QuickSort(a4,0,N-1);
	int end4 = clock();

	int begin5 = clock();
	ShellSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	SelectSort(a6, N);
	int end6 = clock();
		
	printf("InserSort:%d\n", end1 - begin1);//����
	printf("HeapSort:%d\n", end2 - begin2);//��
	printf("BubbleSort:%d\n", end3 - begin3);//ð��
	printf("QuickSort:%d\n", end4 - begin4);//����
	printf("ShellSort:%d\n", end5 - begin5);//ϣ��
	printf("SelectSort:%d\n", end6 - begin6);//ѡ��

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{
	TestOP();
}
