#include<string.h>
#include<errno.h>
int main()
{
	FILE* pf = fopen("C:\\Users\\21788\\OneDrive\\����\\������C����UP����C��������-���ؾ�ҵ��", "r");
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
	char arr3[100] = "���춼��Ҫ��İ����ҵ���˼�����\nI_LOVE_YOU";
	//fputc,fgetc��������һ���ַ�
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
	//fputs,fgets���������ַ���
	//fputs(arr2, pf);
	//int i = 0;
	while (fgets(arr1, 100, pf) != NULL)
	{
		fprintf(stdout, "%s", arr1);
	}
	//fgets(arr1, 100, pf);
	//fprintf(stdout, "%s", arr1);
	//fprintf,fscanf��ʽ����������
	//fprintf(pf, "%s", arr3);
	//fscanf(pf, "%s", arr1);
	//fprintf(stdout, "%s", arr1);
	//sprintf����ʽ��������ת�����ַ���
	//sscanf���ַ���ת���ɸ�ʽ��������
	//fseek������λ�ÿ�ʼ��ȡ����
	//SEEK_SET����ʼλ��
	//SEEK_CUR�ӵ�ǰλ��
	//SEEK_END�ӽ�βλ��
	//fseek(pf, 2, SEEK_SET);
	//int ch = fgetc(pf);
	//fprintf(stdout, "%c", ch);
	//ftell����ƫ����
	//fprintf(stdout, "\n%d", ftell(pf));
	//rewind�ص���ʼλ��
	//rewind(pf);
	//ch = fgetc(pf);
	//fprintf(stdout,"\n%c",ch);
	fclose(pf);
	pf = NULL;
	return 0;
}
