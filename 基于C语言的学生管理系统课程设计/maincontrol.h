#ifndef _MAINCONTROL
#define _MAINCONTROL
void printHead();                   /*��ӡѧ����Ϣ�ı�ͷ*/
int baseManage(Student stu[], int n);     /*������Ϣ����,��Ψһѧ�Ų���ɾ���޸�*/
void scoreManage(Student stu[], int n);  /*ѧ���ɼ�����*/
void printMarkCourse(char* s, double m[3][3], int k);  /*��ӡ����ͨ�ú���*/
void countManage(Student stu[], int n);   /*���Գɼ�ͳ��*/
void searchManage(Student stu[], int n);   /*�ú�����ɸ���������ѯ����*/
int runMain(Student stu[], int n, int choice);  /*����ģ�飬ѡ��ִ����һ���˵�����*/
#endif
