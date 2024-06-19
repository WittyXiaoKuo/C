#include<string.h>
#include<errno.h>
int main()
{
	FILE* pf = fopen("C:\\Users\\21788\\OneDrive\\桌面\\【鹏哥C语言UP主】C语言资料-比特就业课", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

#include<string.h>
#include<errno.h>
int main()
{
	FILE* pf = fopen("qqcom.c", "r");
	if (!pf)
	{
		//printf("%s\n", strerror(errno));
		perror(pf);
		return 1;
	}
	char arr1[100] = { 0 };
	char arr2[100] = "abcdefg";
	char arr3[100] = "天天都需要你的爱，我的心思由你猜\nI_LOVE_YOU";
	//fputc,fgetc输入和输出一个字符
	//fputc('a', pf); 
	//fputc('b', pf);
	//int i = 0;
	//for (i = 0; i < 100; i++)
	//{
	//	char ch = fgetc(pf);
	//	if (ch != EOF)
	//	{
	//		fprintf(stdout, "%c", ch);
	//	}
	//}
	//char ch=fgetc(pf);
	//fprintf(stdout, "%c", ch);
	//ch = fgetc(pf);
	//fprintf(stdout, "%c", ch);
	//fputs,fgets输入和输出字符串
	//fputs(arr2, pf);
	//int i = 0;
	while (fgets(arr1, 100, pf) != NULL)
	{
		fprintf(stdout, "%s", arr1);
	}
	//fgets(arr1, 100, pf);
	//fprintf(stdout, "%s", arr1);
	//fprintf,fscanf格式化输入和输出
	//fprintf(pf, "%s", arr3);
	//fscanf(pf, "%s", arr1);
	//fprintf(stdout, "%s", arr1);
	//sprintf将格式化的数据转化成字符串
	//sscanf将字符串转化成格式化的数据
	//fseek从任意位置开始读取数据
	//SEEK_SET从起始位置
	//SEEK_CUR从当前位置
	//SEEK_END从结尾位置
	//fseek(pf, 2, SEEK_SET);
	//int ch = fgetc(pf);
	//fprintf(stdout, "%c", ch);
	//ftell计算偏移量
	//fprintf(stdout, "\n%d", ftell(pf));
	//rewind回到开始位置
	//rewind(pf);
	//ch = fgetc(pf);
	//fprintf(stdout,"\n%c",ch);
	fclose(pf);
	pf = NULL;
	return 0;
}
