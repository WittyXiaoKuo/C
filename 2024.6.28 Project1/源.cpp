//TOP_K问题
#include<time.h>
#include<stdlib.h>
typedef int HPDataType;
void Swap(HPDataType* p1, HPDataType* p2)//交换
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(HPDataType* a, int n, int parent)//向下调整
{
	int child = parent * 2 + 1;//找出最小的孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])//小堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void Createnum()
{
	//造数据
	int n = 100000, i = 0;
	srand((unsigned int)time(0));
	const char* file = "TOP_K.c";
	FILE* fin = fopen(file, "w");
	if (!fin)
	{
		perror("fopen fail");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}
void Top_k()
{
	int k = 0, i = 0;
	printf("请输入K:>");
	scanf("%d", &k);
	int* kmaxheap = (int*)malloc(sizeof(int) * k);
	if (!kmaxheap)
	{
		perror("malloc fail");
		exit(1);
	}
	const char* file = "TOP_K.c";
	FILE* fout = fopen(file, "r");
	if (!fout)
	{
		perror("fopen error");
		exit(1);
	}
	//读取文件前k个数据
	for (i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kmaxheap[i]);
	}
	//建堆
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kmaxheap, k, i);
	}
	//读取剩下数据进行比较
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > kmaxheap[0])
		{
			kmaxheap[0] = x;
			AdjustDown(kmaxheap, k, 0);
		}
	}
	printf("最大的前%d数据位:\n", k);
	for (i = 0; i < k; i++)
	{
		printf("%d ", kmaxheap[i]);
	}
	printf("\n");
	fclose(fout);
}
int main()
{
	//Createnum();
	Top_k();
	return 0;
}
