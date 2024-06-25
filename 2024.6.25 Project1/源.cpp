//×Ö·û´®Ïà³Ë
#include<stdlib.h>
char* multiply(char* num1, char* num2) {
	int sum = 0;
	char* arr[100];
	sum = atoi(num1) * atoi(num2);
	sprintf(arr, "%d", sum);
	return arr;
}
int main()
{
	//char arr1[] = "123";
	//int i = atoi(arr1);
	//printf("%d\n", i);
	char arr1[10] = { 0 }, arr2[10] = { 0 };
	scanf("%s\n%s", arr1, arr2);
	char* arr;
	arr = multiply(arr1, arr2);
	printf("%s\n", arr);
	return 0;
}
