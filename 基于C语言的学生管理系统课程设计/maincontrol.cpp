#include<stdio.h>
#include"file.h"
#include"student.h"
#include "menu.h"
#include "mainControl.h"
/*�������ܣ���ӡѧ����Ϣ�ı�ͷ
�������������β�
��������ֵ���޷���ֵ
*/
void printHead()
{
	printf("%8s%10s%8s%6s%6s%8s%6s%6s\n", "ѧ��", "����", "�Ա�", "��ѧ",
		"Ӣ��", "�����", "�ܷ�", "����");
}
/*�������ܣ�������Ϣ����,��Ψһѧ�Ų��롢ɾ�����޸�
���������������βηֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ��ĳ�ֲ�������֮��ʵ�ʵļ�¼����
*/
int baseManage(Student* stu, int n)
{
	int choice, t, find[NUM];
	Student s;
	do
	{
		menuBase();                     /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);	            /*����ѡ��*/
		switch (choice)
		{
		case 1: readStu(&s, 1);       /*����һ���������ѧ����¼*/
			n = insertStu(stu, n, s);   /*���ú�������ѧ����¼*/
			break;
		case 2:  printf("Input the number deleted\n");
			scanf("%ld", &s.num);  /*����һ����ɾ����ѧ��ѧ��*/
			n = deleteStu(stu, n, s);   /*���ú���ɾ����ѧ��ѧ����¼*/
			break;
		case 3:  printf("Input the number modified\n");
			scanf("%ld", &s.num);  /*����һ�����޸ĵ�ѧ��ѧ��*/
			t = searchStu(stu, n, s, 1, find); /*���ú������Ҹ�ѧ�ż�¼*/
			if (t)                 /*�����ѧ�ŵļ�¼����*/
			{
				readStu(&s, 1);    /*����һ��������ѧ����¼��Ϣ*/
				stu[find[0]] = s;    /*�ն���ļ�¼������ĵļ�¼*/
			}
			else                 /*�����ѧ�ŵļ�¼��������ʾ*/
				printf("this student is not in,can not be modified.\n");
			break;
		case 0: break;
		}
	} while (choice);
	return n;                              /*����ʵ�ʼ�¼����*/
}
/*�������ܣ�ѧ���ɼ������������ּܷ�����
���������������βηֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void scoreManage(Student* stu, int n)
{
	int choice;
	do
	{
		menuScore();                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);	               /*�������ѡ��*/
		switch (choice)
		{
		case 1:   calcuTotal(stu, n);break;   /*������ѧ�����ܷ�*/
		case 2:  calcuRank(stu, n); break;  /*��������ѧ�����ܷ�������*/			case 0:   break;
		}
	} while (choice);
}
/*�������ܣ���ӡ����
������������1���β��������������ʾ��Ϣ������2���βα�ʾ3�ſ���ߡ���͡�ƽ���ֵ����飬
��3���βδ���ѡ�0��1��2��Ӧ��ߡ���͡�ƽ����
��������ֵ���޷���ֵ
*/
void printMarkCourse(char* s, double m[3][3], int k)
{
	int i;
	printf(s);                              /*s�������������ʾ��Ϣ*/
	for (i = 0;i < 3;i++)                        /*i������һ�ſ�*/
		printf("%10.2lf", m[i][k]);
	printf("\n");
}
/*�������ܣ����Գɼ�ͳ�ƣ���3�ſε���ߡ���͡�ƽ��ֵ
���������������βηֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void countManage(Student* stu, int n)
{
	int choice;
	double mark[3][3];
	do
	{
		menuCount();                     /*��ʾ��Ӧ�Ķ����˵�*/
		calcuMark(mark, stu, n);              /*��3�ſε���ߡ���͡�ƽ��ֵ*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   printMarkCourse("���ſε���߷ֱַ���:\n", mark, 0);
			break;
		case 2:   printMarkCourse("���ſε���ͷֱַ���:\n", mark, 1);
			break;
		case 3:   printMarkCourse("���ſε�ƽ���ֱַ���:\n", mark, 2);
			break;
		case 0:   break;
		}
	} while (choice);
}
/*�������ܣ�����������ѯ
���������������βηֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ���޷���ֵ
*/
void searchManage(Student* stu, int n)
{
	int i, choice, findnum, f[NUM];
	Student s;
	do
	{
		menuSearch();                       /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   printf("Input a student\'s num will be searched:\n");
			scanf("%ld", &s.num);    /*�������ѯѧ����ѧ��*/
			break;
		case 2:   printf("Input a student\'s name will be searched:\n");
			scanf("%s", s.name);	    /*�������ѯѧ��������*/
			break;
		case 3:   printf("Input a rank will be searched:\n");
			scanf("%d", &s.rank);     /*�������ѯѧ��������*/
			break;
		case 0:   break;
		}
		if (choice >= 1 && choice <= 3)
		{
			findnum = searchStu(stu, n, s, choice, f);   /*��������Ԫ�ص��±����f*/
			if (findnum)				        /*������ҳɹ�*/
			{
				printHead();                 /*��ӡ��ͷ*/
				for (i = 0;i < findnum;i++)        /*ѭ������f������±�*/
					printStu(&stu[f[i]], 1);       /*ÿ�����һ����¼*/
			}
			else
				printf("this record does not exist!\n"); /*���Ҳ��������ʾ��Ϣ*/
		}
	} while (choice);
}
/*�������ܣ�����ģ�飬ѡ��һ���˵�����ִ��
���������������βηֱ�Ϊ�ṹ��ָ��ͼ�¼����
��������ֵ�����ؼ�¼����
*/
int runMain(Student* stu, int n, int choice)
{
	switch (choice)
	{
	case 1: printHead();             /* 1. ��ʾ������Ϣ*/
		sortStu(stu, n, 1);        /*��ѧ����С�����˳�������¼*/
		printStu(stu, n);         /*��ѧ����С����˳��������м�¼*/
		break;
	case 2: n = baseManage(stu, n);    /* 2. ������Ϣ����*/
		break;
	case 3: scoreManage(stu, n);     /* 3. ѧ���ɼ�����*/
		break;
	case 4: countManage(stu, n);     /* 4. ���Գɼ�ͳ��*/
		break;
	case 5: searchManage(stu, n);     /* 5. ����������ѯ*/
		break;
	case 0:  break;
	}
	return n;
}
/*�������ܣ��������������ȡ�����ļ���Ȼ�����һ���˵�����ʾ����runMainִ�и����ܣ�����Ȱ�ѧ������󽫽�������ļ�
������������
��������ֵ������1
*/
int main()                          /*����������ȡ�ļ�������һ���˵�ѡ��*/
{
	Student stu[NUM];              /*����ʵ��һά����洢ѧ����¼*/
	int choice, n;
	n = readFile(stu);                 /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	if (!n)                         /*���ԭ�����ļ�Ϊ��*/
		n = createFile(stu);           /*������Ҫ�����ļ����Ӽ����϶����¼*/
	do
	{
		menu();                    /*��ʾ���˵�*/
		printf("Please input your choice: ");
		scanf("%d", &choice);
		if (choice >= 0 && choice <= 5)
			n = runMain(stu, n, choice);   /*ѡ��һ���˵���Ӧ�Ĺ���*/
		else
			printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu, n, 1);                 /*�����ļ�ǰ��ѧ����С��������*/
	saveFile(stu, n);                  /*����������ļ�*/
	return 0;
}
