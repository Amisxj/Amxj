#ifndef _STUDENT                /*�������룬��ֹ�ظ������Ĵ���*/
#define _STUDENT
#define NUM 3                  /*����ѧ����������������ʵ����Ҫ�޸�ֵ*/
struct Student                      /*ѧ����¼�����ṹ�����͵Ķ���*/
{
    long num;                /*ѧ��*/
    char name[20];         /*����*/
    char sex[10];             /*�Ա�*/
    int score[3];              /*3�ſγɼ�*/
    int total;                   /*�ܷ�*/
    int rank;                    /*����*/
};
typedef struct Student Student;           /*�������͵ı���Student*/
#define sizeStu sizeof(Student)           /*һ��ѧ����¼����Ҫ���ڴ�ռ��С*/
int readStu(Student* stu, int n);            /*����ѧ����¼��ѧ��Ϊ0�����ֹͣ*/
void printStu(Student* stu, int n);        /*��Ļ�������ѧ����¼��ֵ*/
int equal(Student s1, Student s2, int condition); /*����condition�ж�s1��s2��ȷ�*/
int larger(Student s1, Student s2, int condition);/*����condition�Ƚ�s1��s2�Ĵ�С*/
void reverse(Student* stu, int n);            /*ѧ����¼����Ԫ������*/
void calcuTotal(Student* stu, int n);         /*��������ѧ�����ܷ�*/
void calcuRank(Student* stu, int n);         /*�����ּܷ���ѧ��������������*/
void calcuMark(double m[3][3], Student* stu, int n);  /*��3�ſε�������ƽ����*/
void sortStu(Student* stu, int n, int condition);  /*����������ѡ�񷨴�С��������*/
int searchStu(Student* stu, int n, Student s, int condition, int* f);  /*����������������*/
/*����s��ȵĸ�Ԫ�أ�ÿһ����s���Ԫ�ص��±�����f������*/
int insertStu(Student* stu, int n, Student s);     /*�������в���һ��Ԫ�ذ�ѧ������*/
int deleteStu(Student* stu, int n, Student s);    /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
#endif
