#ifndef _MAINCONTROL
#define _MAINCONTROL
void printHead();                   /*打印学生信息的表头*/
int baseManage(Student stu[], int n);     /*基本信息管理,按唯一学号插入删除修改*/
void scoreManage(Student stu[], int n);  /*学生成绩管理*/
void printMarkCourse(char* s, double m[3][3], int k);  /*打印分数通用函数*/
void countManage(Student stu[], int n);   /*考试成绩统计*/
void searchManage(Student stu[], int n);   /*该函数完成根据条件查询功能*/
int runMain(Student stu[], int n, int choice);  /*主控模块，选择执行于一级菜单功能*/
#endif
