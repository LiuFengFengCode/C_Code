#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//������ת�ȣ�����һ��������к��л���
//int main()
//{
//	int arr1[3][2] = { {1,2},{3,4},{5,6} };
//	int arr2[2][3] = { 0 };
//	int i, j;
//
//	printf("before arr:\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			printf("%2d  ", arr1[i][j]);
//			arr2[j][i] = arr1[i][j];
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%2d  ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//��һ��3X4�ľ���Ҫ���������ֵ�����Ǹ�Ԫ�ص�ֵ���Լ����ڵ��кź��к�
int main()
{
	int arr[3][4] = { {1,2,3,4},{9,8,7,6},{-10,10,-5,2} };
	int i = 0;
	int j = 0;
	int max = arr[0][0];
	int row = 0;
	int col = 0;
//���ʹ��Ԥ����#define m 3  #define n 4�Ļ���������ʱ�ı������к������Ƚϣ�ʵ���Ը���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				row = i+1;
				col = j+1;
			}	
		}
	}
	printf("���ֵΪ��%d\n�к�Ϊ��%d\n�к�Ϊ��%d\n", max, row, col);
	return 0;
}