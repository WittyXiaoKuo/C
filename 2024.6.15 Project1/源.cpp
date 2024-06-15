#include <stdio.h>
#include <string.h>
void removeChars(char* str1, char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++) 
	{
		for (int j = 0; j < len2; j++) 
		{
			if (str1[i] == str2[j]) 
			{
				for (int k = i; k < len1 - 1; k++) 
				{
					str1[k] = str1[k + 1];
				}
				len1--;
				i--;
				break;
			}
		}
	}
	str1[len1] = '\0';
}

int main() {
	char str1[] = "hello world";
	char str2[] = "lo";
	printf("原始字符串 str1: %s\n", str1);
	removeChars(str1, str2);
	printf("处理后字符串: %s\n", str1);
	return 0;
}
