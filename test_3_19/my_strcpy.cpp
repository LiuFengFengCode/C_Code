#define _CRT_SECURE_NO_WARNINGS 1

#include "my_strcpy.h"


//��������������ַ��������ģ�������\0����������������Ҫ�������ĵط��ĵ�ַ��
// ��Ŀ�ĵصĵ�ַ������pa��Ŀ�ĵĵ�ַ��ָ�룬pb��Դ��ַ��length1��Ŀ�ĵص��ֽڴ�С��
//length2����Դ�ص��ֽڴ�С��
char* my_strcpy(char* pa, const char* pb,int length1,int length2)
{
	char* ret = pa;    //��������Ŀ�ĵĵĵ�ַ����������++�Ľ��У�pa�ĵ�ַ��������Ԫ�ص�ַ
	assert(pa != NULL);//�����ж�Ŀ�ĵĲ��ǿ�ָ�룬���������������Ϊ�棬�޷�Ӧ��Ϊ�ٱ���
	assert(pb != NULL);
	assert(length1 >= length2);
	while (*pa++ = *pb++);
	return ret;
}