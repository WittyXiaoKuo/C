//输入一个整数,每隔三位加一个逗号
#include <stdio.h>
void addCommas(int num) {
	char str[50];
	int len = 0, i = 1;
	while (num)
	{
		str[len++] = num % 10 + '0';
		num /= 10;
		if (len == 3 && num > 0)
		{
			str[len++] = ',';
		}
		else if ((len - i) % 3 == 0 && len > 1 && num > 0) {
			str[len++] = ',';
			i++;
		}
	}
	for (i = len - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
}
int main() {
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	addCommas(num);
	return 0;
}
