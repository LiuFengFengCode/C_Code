#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%4d ", p[i]);
	}
}

void bubble_sort(int* p, int sz)
{
	int i, j;
	int tmp;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//�����ԱȵĴ���
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (p[j] > p[j + 1])
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}


int main()
{
	//ð������
	int arr[] = {5,4,3,2,1,0,9,8,7,6};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	print(arr,sz);
	return 0;
}