#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>


//�����Ĳ��Կո��\0�����𣬿ո��ASCII��Ϳո��ASCII�ǲ�һ���ģ������㳤�ȵ�ʱ��ո�Ҳ��
//#include <string.h>
//
//int main()
//{ 
//	char s[] = "Address  ";
//	char ch = '\0';
//	printf("%d\n", strlen(s));
//	printf("%d", ch);
//	return 0;
//}


//��s���г��ֵ�s1��ȫ���滻��s2������ַ���
int my_rep(char* s, char* s1, char* s2)
{
	assert(s && s1 && s2);
	assert(strlen(s1) == strlen(s2));
	char* p = NULL;//��������s�������е�Ԫ��
	char* p1 = NULL;//��������s1�������е�Ԫ��
	char* p2 = s2;//��������s1�������е�Ԫ��
	char* cur = s;//������λ��ʱ�ĵ�ַ
/*	int flag_num = 0*/;//ȷ��Ҫ�滻���ַ�������,Ҳ������sizeof
	int isflag = 0;//�ж��Ƿ��ҵ��ַ����ҿ����滻�ദ
	int flag_pri = 0;//�ж��Ƿ��ҵ����ַ���
	int i = 0;//������s2���ַ�����ѭ���ķ�ʽ����s��
	int sz = strlen(s1);
	while (*cur)
	{
		p = cur;
		p1 = s1;
		while (*p1 && *p && (*p == *p1))
		{
			p++;
			p1++;
			//flag_num++;
		}
		if (!*p1)
		{ 
			isflag = 1;
			flag_pri = 1;
			for (i = 0; i < sz; i++)//�����flag_num�Ļ���Ҫд��flag_num��
			{
				*(cur + i) = *(p2 + i);
			}
			p2 = s2;
		}
		if (!(*p) && (*p1)) return 0;
		if (isflag) cur += sz;//���Ҫ��flag_num�Ļ���Ҫ�ĳ�flag_num-1
		cur++;
		isflag = 0;
		//flag_num = 0;Ҫ�ǵù���
	}
	if (!flag_pri)
		return 0;
	else
		return 1;
}

int main()
{
	char s[] = "abbbcabbbc";
	char s1[20];
	char s2[20];

	printf("ԭ����s:%s\n", s);
	printf("������Ҫ�滻���ַ���:");
	gets(s1);
	printf("s1:%s\n", s1);
	printf("������Ҫ�滻�ɵ��ַ���:");
	gets(s2);
	printf("s2:%s\n", s2);

	printf("\n");

	//my_rep(s, s1, s2);

	if (my_rep(s, s1, s2))
	{
		printf("�ı���s:%s", s);
	}
	else
		printf("û���ҵ���Ӧ���ַ���");

	return 0;
}