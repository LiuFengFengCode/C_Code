#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//ð�����򣬴�С��������
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int j = 0;
	int temp = 0;
	printf("������10�����֣�\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");

	for (i = 9; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}