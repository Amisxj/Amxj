#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "file.h"
/*�������ܣ����ļ������ݶ�������������
�����������β��ǽṹ��ָ��
��������ֵ�����ļ��ж�����ʵ�ʼ�¼����
*/
int readFile(Student* stu)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("c:\\student.dat", "rb")) == NULL)   /*�Զ���ʽ��ָ���ļ�*/
	{
		printf("file does not exist,create it first:\n");   /*����ʧ�������ʾ��Ϣ*/
		return 0;                               /*Ȼ�󷵻�0*/
	}
	fread(&stu[i], sizeStu, 1, fp);                   /*������һ����¼*/
	while (!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
		fread(&stu[i], sizeStu, 1, fp);               /*�ٶ�����һ����¼*/
	}
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}
/*�������ܣ����ṹ����������д���ļ�
���������������βηֱ��ǽṹ��ָ�롢ʵ�ʼ�¼����
��������ֵ���޷���ֵ
*/
void saveFile(Student* stu, int n)
{
	FILE* fp;
	if ((fp = fopen("c:\\student.dat", "wb")) == NULL) /*��д��ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");            /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                              /*Ȼ���˳�*/
	}
	fwrite(stu, sizeStu, n, fp);                     /*һ�������ļ�д��n����¼*/
	fclose(fp);                               /*�ر��ļ�*/
}
/*�������ܣ�������ʼ�������ļ�
�����������βηֱ�Ϊ�ṹ��ָ��
��������ֵ������д���ļ��ļ�¼����
*/
int  createFile(Student* stu)
{
	FILE* fp;
	int n;
	if ((fp = fopen("c:\\student.dat", "wb")) == NULL) /*ָ���ļ�������д��ʽ��*/
	{
		printf("can not open file !\n");            /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                              /*Ȼ���˳�*/
	}
	printf("input students\' information:\n");
	n = readStu(stu, NUM);                    /*����student.h�еĺ���������*/
	fwrite(stu, sizeStu, n, fp);                   /*����������м�¼ȫд���ļ�*/
	fclose(fp);                              /*�ر��ļ�*/
	return n;                               /*���ؼ�¼����*/
}
