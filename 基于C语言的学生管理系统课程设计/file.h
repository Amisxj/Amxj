/*��file.h�ļ����������£�*/
#ifndef _FILE                   /*�������룬��ֹ�ظ������Ĵ���*/
#define _FILE
#include "student.h"        
int createFile(Student* stu);       /*������ʼ�������ļ�*/
int readFile(Student* stu);        /*���ļ��е����ݶ������ڽṹ������stu��*/
void saveFile(Student* stu, int n);   /*���ṹ�����������д���ļ�*/
#endif	
