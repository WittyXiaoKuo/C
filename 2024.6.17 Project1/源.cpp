int My_strlen(char* str)
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdefg";
	int ret = My_strlen(arr);
	printf("%d\n", ret);
	return 0;
}
