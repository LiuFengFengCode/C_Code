#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//ѧ��ʹ��strstr�⺯������һ���ַ���������һ�����ַ���,����ֵ��ָ�룬���ҵ��ַ����ĵ�ַ��
//int main()
//{
//	char* ret = NULL;
//	char arr1[] = "abcdefghi";
//	char arr2[] = "cdef";
//
//	ret = strstr(arr1, arr2);
//	printf("%s\n", ret);
//
//	return 0;
//}

//�Լ�дһ��my_strstr������ʵ������Ӧ�Ĺ���
//����Ҫʹһ�������м��书��ʱ������ʹ��whileѭ����д
//����temp = p1������p1��ֵһֱ�ڱ䣬���㲻ϣ����һֱ�䣬��ϣ����ͣ��ĳ��������ʱ
//Ҫ�ر�ע���abbbcdefg����bbc����Ӵ�������
char* my_strstr(const char* p1,const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = NULL;//��������p1�������е�Ԫ�أ�����p1��ֵ�Ͳ��ñ���
	char* s2 = NULL;//��������p2�������е�Ԫ�أ�����p2��ֵ�Ͳ��ñ���
	//ǿ������ת����ԭ��p2��const char*�������ܱ����ģ�cur�ǲ��ܱ�����
	//cur�������ǹ̶����ַ��������ҵ��Ӵ�ʱ�ĵ�ַ����������Ǹ�����
	char* cur = (char*)p1;
	if (!*p2) return (char*)p1;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') return cur;
		if (*s1 == '\0') return NULL;
		cur++;
	}
	return NULL;
}


int main()
{
	char* ret = NULL;
	char arr1[] = "abbbcdefghi";
	char arr2[] = "bbc";

	ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);

	return 0;
}