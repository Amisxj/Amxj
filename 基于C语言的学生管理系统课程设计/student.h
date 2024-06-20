#ifndef _STUDENT                /*条件编译，防止重复包含的错误*/
#define _STUDENT
#define NUM 3                  /*定义学生人数常量，根据实际需要修改值*/
struct Student                      /*学生记录所属结构体类型的定义*/
{
    long num;                /*学号*/
    char name[20];         /*姓名*/
    char sex[10];             /*性别*/
    int score[3];              /*3门课成绩*/
    int total;                   /*总分*/
    int rank;                    /*名次*/
};
typedef struct Student Student;           /*定义类型的别名Student*/
#define sizeStu sizeof(Student)           /*一个学生记录所需要的内存空间大小*/
int readStu(Student* stu, int n);            /*读入学生记录，学号为0或读满停止*/
void printStu(Student* stu, int n);        /*屏幕输出所有学生记录的值*/
int equal(Student s1, Student s2, int condition); /*根据condition判断s1与s2相等否*/
int larger(Student s1, Student s2, int condition);/*根据condition比较s1与s2的大小*/
void reverse(Student* stu, int n);            /*学生记录数组元素逆置*/
void calcuTotal(Student* stu, int n);         /*计算所有学生的总分*/
void calcuRank(Student* stu, int n);         /*根据总分计算学生的名次允许并列*/
void calcuMark(double m[3][3], Student* stu, int n);  /*求3门课的最高最低平均分*/
void sortStu(Student* stu, int n, int condition);  /*根据条件用选择法从小到大排序*/
int searchStu(Student* stu, int n, Student s, int condition, int* f);  /*根据条件查找数组*/
/*中与s相等的各元素，每一个与s相等元素的下标置于f数组中*/
int insertStu(Student* stu, int n, Student s);     /*向数组中插入一个元素按学号有序*/
int deleteStu(Student* stu, int n, Student s);    /*从数组中删除一个指定学号的元素*/
#endif
