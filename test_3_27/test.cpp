#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
	char name[20];
	int age;
	double grad;
	char xuhao[20];
}stu;


//���δ�ӡ
void print_int(int* p, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%5d", p[i]);
	}
}


//�����ʹ�ӡ
void print_float(float* p, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%f  ", p[i]);
	}
}


//�ṹ���ӡ
void print_stu(stu* p, int sz)
{
	int i;
	for(i = 0;i<sz;i++)
		printf("%-9s\t%-9d\t%-9lf\t%-9s\n", (p[i]).name,(p[i]).age,(p[i]).grad,(p[i]).xuhao);
}


//���αȽϷ�
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *((int*)e2));
}

//�����ͱȽϷ�
int cmp_float(const void* e1, const void* e2)
{
	return ((int)(*(float*)e1 - *(float*)e2));
}


//�ṹ��Ƚ�
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name,((stu*)e2)->name);//->�����ȼ���ǿ������ת�������͸ߣ�����Ҫ������������
}

int cmp_stu_age(const void* e1, const void* e2)
{
	return (((stu*)e1)->age-((stu*)e2)->age);
}

int cmp_stu_grade(const void* e1, const void* e2)
{
	return ((int)(((stu*)e1)->grad-((stu*)e2)->grad));//->�����ȼ���ǿ������ת�������͸ߣ�����Ҫ������������
}

int cmp_stu_xuehao(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->xuhao, ((stu*)e2)->xuhao);//->�����ȼ���ǿ������ת�������͸ߣ�����Ҫ������������
}

//���ܣ�����������
//ע�����ﴫ��ȥ�����ַ�ָ�롣ͬʱ����Ҫ����Ԫ�ص��ֽ�������Ϊchar*һ��ֻ��
//�ı�һ���ֽڣ�ֻ��֪��Ԫ��һ���ж����ֽ���ʱ��֪��Ҫ�ı���ٸ��ֽڣ���Ҫ�Ĵ�������
void Swap(char* p1,char* p2,int width)
{
	int i = 0;
	char temp;
	//ѭ���������ֽڸı�Ԫ��
	for (i = 0; i < width; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		//Ҫ�ǵõ�ַ++��Ҫ��Ȼ�Ĳ���
		p1++;
		p2++;
	}
}


//���ܣ��Ƚ�������������С�����˳��
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	//����
	int i = 0;
	int j = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//�����ȽϵĴ���
		for (j = 0; j < sz - 1 - i; j++)
		{
			//�㾦֮�ʣ�ǿ������ת�����ͬʱҪ�ǵý��ֽ�����������
			//Ҫע�⣬����Ҫ��������±��Լ��䣬����j * width��(j+1) * width�����þͳ�����
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width) > 0)
			{
				Swap((char*)base+j*width, (char*)base + (j+1) * width,width);
			}
		}
	}
	
}


//ʹ��qsortʵ�ֿ�������(һ���Լ�д��һ��ԭ�����е�)�������Ÿ��ָ������͵�˳��
//int main()
//{
//	int arr[] = { 7,9,8,6,5,4,3,2,1,0 };
//	float f[] = { 8.0,9.0,6.0,7.0,1.0,2.0,3.0,4.0,5.0,0.0 };
//	int sza = sizeof(arr) / sizeof(arr[0]);
//	int szf = sizeof(f) / sizeof(f[0]);
//
//	qsort(arr, sza, sizeof(arr[0]), cmp_int);
//	qsort(f, szf, sizeof(f[0]), cmp_float);
//
//	print1(arr,sza);
//	printf("\n");
//	print2(f,szf);
//
//	return 0;
//}



//ȫ���Լ�д��bubble_sort(void* base,int sz,int width,int(*cmp)(const void* e1 ,const void* e2))
int main()
{
	int arr[] = { 7,9,8,6,5,4,3,2,1,0 };
	float f[] = { 8.0,9.0,6.0,7.0,1.0,2.0,3.0,4.0,5.0,0.0 };
	stu s[3] = { { "zhangsan",18,98.9,"211218092"},{"lisi",19,78.6,"211218090"},{"wangwu",20,89.6,"211218099"}};
	int szs = sizeof(s) / sizeof(s[0]);
	int sza = sizeof(arr) / sizeof(arr[0]);
	int szf = sizeof(f) / sizeof(f[0]);

	bubble_sort(arr, sza, sizeof(arr[0]), cmp_int);
	bubble_sort(f, szf, sizeof(f[0]), cmp_float);
	bubble_sort(s, szs, sizeof(s[0]), cmp_stu_xuehao);
	print_int(arr,sza);
	printf("\n");
	print_float(f, szf);
	printf("\n");
	print_stu(s, szs);
}

