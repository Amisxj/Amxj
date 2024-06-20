#include "student.h"
#include <stdio.h>
#include <string.h>
/*�������ܣ��Ӽ��̶���ѧ���ĳ�ʼ����ֵ
���������� ������ʽ�����ֱ�Ϊ�ṹ��ָ���Ԥ���¼����
��������ֵ���Ӽ�����ʵ�ʶ���ļ�¼����
*/
int readStu(Student* stu, int n)
{
	int i, j;
	for (i = 0;i < n;i++)
	{
		printf("Input one student\'s information\n");
		printf("num:  ");
		scanf("%ld", &stu[i].num);
		if (stu[i].num == 0) break;
		printf("name: ");
		scanf("%s", stu[i].name);
		printf("sex:  ");
		scanf("%s", stu[i].sex);
		stu[i].total = 0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three courses of the student:\n");
		for (j = 0;j < 3;j++)
			scanf("%d", &stu[i].score[j]);
		stu[i].rank = 0;                 /*����Ҫ�����ּܷ��㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}
/*�������ܣ��������ѧ����¼��ֵ
���������� ������ʽ�����ֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void printStu(Student* stu, int n)
{
	int i, j;
	for (i = 0;i < n;i++)
	{
		printf("%8ld  ", stu[i].num);
		printf("%8s", stu[i].name);
		printf("%8s", stu[i].sex);
		for (j = 0;j < 3;j++)
			printf("%6d", stu[i].score[j]);
		printf("%7d", stu[i].total);
		printf("%5d\n", stu[i].rank);
	}
}
/*�������ܣ��ж�����Student��¼�Ƿ����
���������� 3����ʽ�����ֱ�Ϊ���Ƚϵ������ṹ��������Ƚ�����
��������ֵ���ȽϵĽ������ȷ���1������ȷ���0
*/
int equal(Student s1, Student s2, int condition)
{
	if (condition == 1)           /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num == s2.num;
	else if (condition == 2)       /*�������condition��ֵΪ2����Ƚ�����*/
	{
		if (strcmp(s1.name, s2.name) == 0)
			return 1;
		else return 0;
	}
	else if (condition == 3)      /*�������condition��ֵΪ3����Ƚ�����*/
		return s1.rank == s2.rank;
	else if (condition == 4)      /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total == s2.total;
	else return 1;             /*�����������1*/
}
/*�������ܣ��Ƚ�����Student��¼�Ĵ�С
���������� 3����ʽ�����ֱ�Ϊ���Ƚϵ������ṹ��������Ƚ�����
��������ֵ���ȽϵĽ������1����¼���ڵ�2���򷵻�1�����򷵻�0
*/
int larger(Student s1, Student s2, int condition)
{
	if (condition == 1)                   /*��condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num > s2.num;
	else if (condition == 2)               /*��condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total > s2.total;
	else return 1;                      /*�����������1*/
}
/*�������ܣ������Ԫ������
���������� ������ʽ�����ֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void reverse(Student* stu, int n)
{
	int i;
	Student temp;
	for (i = 0;i < n / 2;i++)                  /*ѭ������ΪԪ��������һ��*/
	{
		temp = stu[i];
		stu[i] = stu[n - 1 - i];
		stu[n - 1 - i] = temp;
	}
}
/*�������ܣ���������ѧ�����ܷ�
���������� ������ʽ�����ֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void calcuTotal(Student* stu, int n)
{
	int i, j;
	for (i = 0;i < n;i++)                   /*���ѭ����������ѧ����¼*/
	{
		stu[i].total = 0;
		for (j = 0;j < 3;j++)               /*�ڲ�ѭ���������Ź���*/
			stu[i].total += stu[i].score[j];
	}
}
/*�������ܣ������ּܷ���������ͬ��ͬ����
���������� ������ʽ�����ֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void calcuRank(Student* stu, int n)
{
	int i;
	sortStu(stu, n, 2);                   /*����sortStu�㷨���ܷ���С��������*/
	reverse(stu, n);                    /*�����ã����ܷ��ɴ�С������*/
	stu[0].rank = 1;                    /*��һ����¼������һ����1*/
	for (i = 1;i < n;i++)                  /*�ӵڶ�����¼һֱ�����һ��ѭ��*/
	{
		if (equal(stu[i], stu[i - 1], 4))       /*��ǰ��¼����ǰһ����¼�ܷ����*/
			stu[i].rank = stu[i - 1].rank;    /*��ǰ��¼���ε�����ǰһ����¼����*/
		else
			stu[i].rank = i + 1;           /*�����ʱ��ǰ��¼���ε����±��+1*/
	}
}
/*�������ܣ������ſ���ߡ���͡�ƽ����
���������� ��1����ʽ����m��һά����3�ſΣ��ڶ�ά������ߡ���͡�ƽ���֣���2���β��ǽṹ��ָ�룬��3���β��Ǽ�¼����
��������ֵ���޷���ֵ
*/
void calcuMark(double m[3][3], Student stu[], int n)
{
	int i, j;
	for (i = 0;i < 3;i++)                    /*�����ſε���߷�*/
	{
		m[i][0] = stu[0].score[i];
		for (j = 1;j < n;j++)
			if (m[i][0] < stu[j].score[i])
				m[i][0] = stu[j].score[i];
	}
	for (i = 0;i < 3;i++)                    /*�����ſε���ͷ�*/
	{
		m[i][1] = stu[0].score[i];
		for (j = 1;j < n;j++)
			if (m[i][1] > stu[j].score[i])
				m[i][1] = stu[j].score[i];
	}
	for (i = 0;i < 3;i++)                    /*�����ſε�ƽ����*/
	{
		m[i][2] = stu[0].score[i];
		for (j = 1;j < n;j++)
			m[i][2] += stu[j].score[i];
		m[i][2] /= n;
	}
}
/*�������ܣ���condition�涨��������С��������
����������3���βηֱ��ǽṹ��ָ�롢��¼�������������ݵ�����
��������ֵ���޷���ֵ
*/
void sortStu(Student* stu, int n, int condition)
{
	int i, j, minpos;                     /*minpos�汾����СԪ�����ڵ��±�*/
	Student t;
	for (i = 0;i < n - 1;i++)                 /*����ѭ����n-1��*/
	{
		minpos = i;
		for (j = i + 1;j < n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(stu[minpos], stu[j], condition))
				minpos = j;
		if (i != minpos)                 /*��֤������СԪ�ص����±�i��λ��*/
		{
			t = stu[i];
			stu[i] = stu[minpos];
			stu[minpos] = t;
		}
	}
}
/*�������ܣ���condition�涨����������ָ����¼�Ƿ����
����������5���βηֱ��ǽṹ��ָ�롢��¼�����������ҵļ�¼���������������ҵ��Ķ��Ԫ�ض�Ӧ�±�����ŵ�����f
��������ֵ�����ҵ��ļ�¼����
*/
int searchStu(Student* stu, int n, Student s, int condition, int* f[])
{
	int i, j = 0, find = 0;
	for (i = 0;i < n;i++)                         /*�����ҵ�Ԫ��Ϊs*/
		if (equal(stu[i], s, condition))
		{
			f[j++] = i;                        /*�ҵ��˽����±��f������*/
			find++;	                       /*ͳ���ҵ���Ԫ�ظ���*/
		}
	return find;                              /*����find��ֵΪ0��ʾû�ҵ�*/
}
/*�������ܣ���ṹ����������ѧ�ŵ�������һ����¼
����������3���βηֱ��ǽṹ��ָ�롢ԭ���ļ�¼������������ļ�¼
��������ֵ��������ʵ�ʼ�¼����
*/
int insertStu(Student* stu, int n, Student s)
{
	int i;
	sortStu(stu, n, 1);                          /*�Ȱ�ѧ������*/
	for (i = 0;i < n;i++)
		if (equal(stu[i], s, 1))                   /*ѧ����ͬ���ܲ��룬��֤Ψһ*/
		{
			printf("this record exist,can not insert again!\n");
			return n;
		}
	for (i = n - 1;i >= 0;i--)                        /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(stu[i], s, 1))                  /*��s���ڵ�ǰԪ�����˳�ѭ��*/
			break;
		stu[i + 1] = stu[i];                       /*����Ԫ��stu[i]����һ��λ��*/
	}
	stu[i + 1] = s;                              /*���±�i+1������Ԫ��s*/
	n++;                                   /*Ԫ�ظ�������1*/
	return n;                                /*��������Ԫ�ظ���*/
}
/*�������ܣ��ӽṹ��������ɾ��ָ��ѧ�ŵ�һ����¼
����������3���βηֱ��ǽṹ��ָ�롢ԭ���ļ�¼��������ɾ���ļ�¼
��������ֵ��ɾ�����ʵ�ʼ�¼����
*/
int deleteStu(Student* stu, int n, Student s)
{
	int i, j;
	for (i = 0;i < n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(stu[i], s, 1))   break;            /*���ҵ����Ԫ�����˳�ѭ��*/
	if (i == n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");     /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j = i; j < n - 1; j++)            /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/
		stu[j] = stu[j + 1];                       /*ͨ������ɾ���±�Ϊi��Ԫ��*/
	n--;                                    /*Ԫ�ظ�������1*/
	return n;                                /*��������Ԫ�ظ���*/
}
