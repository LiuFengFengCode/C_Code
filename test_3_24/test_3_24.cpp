#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define len 20

//int main()
//{
//	//float c = 32.8;
//	int a = 3;
//	//int b = 2;
//	//a = (int) c;
//	printf("%d\n", -a++);
//	printf("%d", a);
//	return 0;
//}


//ɾ���ַ����������ֵ������ch��ͬ���ַ������Ǽ򵥵�ɾ��������Ҫ�����滻����
//���±����ű��
char* squeeze(char *s, char c)
{
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
	return s;
}

int main()
{
	char arr[len] = "abcdefgccdgh";
	//char len = sizeof(arr) / sizeof(arr[0]);
	char ch = 'c';
	//char arr1[8] = {0};
	char* p = NULL;
	p = squeeze(arr, ch);

	//arr1[8] = squeeze(arr, ch);

	printf("%s", p);
	return 0;
}
