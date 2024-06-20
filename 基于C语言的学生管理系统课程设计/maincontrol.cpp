#include<stdio.h>
#include"file.h"
#include"student.h"
#include "menu.h"
#include "mainControl.h"
/*函数功能：打印学生信息的表头
函数参数：无形参
函数返回值：无返回值
*/
void printHead()
{
	printf("%8s%10s%8s%6s%6s%8s%6s%6s\n", "学号", "姓名", "性别", "数学",
		"英语", "计算机", "总分", "名次");
}
/*函数功能：基本信息管理,按唯一学号插入、删除、修改
函数参数：两个形参分别为结构体指针和记录条数
函数返回值：某种操作结束之后实际的记录条数
*/
int baseManage(Student* stu, int n)
{
	int choice, t, find[NUM];
	Student s;
	do
	{
		menuBase();                     /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);	            /*读入选项*/
		switch (choice)
		{
		case 1: readStu(&s, 1);       /*读入一条待插入的学生记录*/
			n = insertStu(stu, n, s);   /*调用函数插入学生记录*/
			break;
		case 2:  printf("Input the number deleted\n");
			scanf("%ld", &s.num);  /*读入一个待删除的学生学号*/
			n = deleteStu(stu, n, s);   /*调用函数删除该学号学生记录*/
			break;
		case 3:  printf("Input the number modified\n");
			scanf("%ld", &s.num);  /*读入一个待修改的学生学号*/
			t = searchStu(stu, n, s, 1, find); /*调用函数查找该学号记录*/
			if (t)                 /*如果该学号的记录存在*/
			{
				readStu(&s, 1);    /*读入一条完整的学生记录信息*/
				stu[find[0]] = s;    /*刚读入的记录赋给需改的记录*/
			}
			else                 /*如果该学号的记录不存在提示*/
				printf("this student is not in,can not be modified.\n");
			break;
		case 0: break;
		}
	} while (choice);
	return n;                              /*返回实际记录条数*/
}
/*函数功能：学生成绩管理，包括求总分及排名
函数参数：两个形参分别为结构体指针和记录条数
函数返回值：无返回值
*/
void scoreManage(Student* stu, int n)
{
	int choice;
	do
	{
		menuScore();                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);	               /*读入二级选项*/
		switch (choice)
		{
		case 1:   calcuTotal(stu, n);break;   /*求所有学生的总分*/
		case 2:  calcuRank(stu, n); break;  /*根据所有学生的总分排名次*/			case 0:   break;
		}
	} while (choice);
}
/*函数功能：打印分数
函数参数：第1个形参是输出分数的提示信息串，第2个形参表示3门课最高、最低、平均分的数组，
第3个形参代表选项，0、1、2对应最高、最低、平均分
函数返回值：无返回值
*/
void printMarkCourse(char* s, double m[3][3], int k)
{
	int i;
	printf(s);                              /*s是输出分数的提示信息*/
	for (i = 0;i < 3;i++)                        /*i控制哪一门课*/
		printf("%10.2lf", m[i][k]);
	printf("\n");
}
/*函数功能：考试成绩统计，求3门课的最高、最低、平均值
函数参数：两个形参分别为结构体指针和记录条数
函数返回值：无返回值
*/
void countManage(Student* stu, int n)
{
	int choice;
	double mark[3][3];
	do
	{
		menuCount();                     /*显示对应的二级菜单*/
		calcuMark(mark, stu, n);              /*求3门课的最高、最低、平均值*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   printMarkCourse("三门课的最高分分别是:\n", mark, 0);
			break;
		case 2:   printMarkCourse("三门课的最低分分别是:\n", mark, 1);
			break;
		case 3:   printMarkCourse("三门课的平均分分别是:\n", mark, 2);
			break;
		case 0:   break;
		}
	} while (choice);
}
/*函数功能：根据条件查询
函数参数：两个形参分别为结构体指针和记录条数
函数返回值：无返回值
*/
void searchManage(Student* stu, int n)
{
	int i, choice, findnum, f[NUM];
	Student s;
	do
	{
		menuSearch();                       /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:   printf("Input a student\'s num will be searched:\n");
			scanf("%ld", &s.num);    /*输入待查询学生的学号*/
			break;
		case 2:   printf("Input a student\'s name will be searched:\n");
			scanf("%s", s.name);	    /*输入待查询学生的姓名*/
			break;
		case 3:   printf("Input a rank will be searched:\n");
			scanf("%d", &s.rank);     /*输入待查询学生的名次*/
			break;
		case 0:   break;
		}
		if (choice >= 1 && choice <= 3)
		{
			findnum = searchStu(stu, n, s, choice, f);   /*符合条件元素的下标存于f*/
			if (findnum)				        /*如果查找成功*/
			{
				printHead();                 /*打印表头*/
				for (i = 0;i < findnum;i++)        /*循环控制f数组的下标*/
					printStu(&stu[f[i]], 1);       /*每次输出一条记录*/
			}
			else
				printf("this record does not exist!\n"); /*查找不到输出提示信息*/
		}
	} while (choice);
}
/*函数功能：主控模块，选择一级菜单功能执行
函数参数：两个形参分别为结构体指针和记录条数
函数返回值：返回记录条数
*/
int runMain(Student* stu, int n, int choice)
{
	switch (choice)
	{
	case 1: printHead();             /* 1. 显示基本信息*/
		sortStu(stu, n, 1);        /*按学号由小到大的顺序排序记录*/
		printStu(stu, n);         /*按学号由小到大顺序输出所有记录*/
		break;
	case 2: n = baseManage(stu, n);    /* 2. 基本信息管理*/
		break;
	case 3: scoreManage(stu, n);     /* 3. 学生成绩管理*/
		break;
	case 4: countManage(stu, n);     /* 4. 考试成绩统计*/
		break;
	case 5: searchManage(stu, n);     /* 5. 根据条件查询*/
		break;
	case 0:  break;
	}
	return n;
}
/*函数功能：主函数，负责读取或建立文件，然后根据一级菜单的提示调用runMain执行各功能，最后先按学号排序后将结果保存文件
函数参数：无
函数返回值：返回1
*/
int main()                          /*主函数，读取文件，根据一级菜单选择*/
{
	Student stu[NUM];              /*定义实参一维数组存储学生记录*/
	int choice, n;
	n = readFile(stu);                 /*首先读取文件，记录条数返回赋值给n*/
	if (!n)                         /*如果原来的文件为空*/
		n = createFile(stu);           /*则首先要建立文件，从键盘上读入记录*/
	do
	{
		menu();                    /*显示主菜单*/
		printf("Please input your choice: ");
		scanf("%d", &choice);
		if (choice >= 0 && choice <= 5)
			n = runMain(stu, n, choice);   /*选择一级菜单对应的功能*/
		else
			printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu, n, 1);                 /*存入文件前按学号由小到大排序*/
	saveFile(stu, n);                  /*将结果存入文件*/
	return 0;
}
