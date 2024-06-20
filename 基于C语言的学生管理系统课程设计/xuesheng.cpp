#include "student.h"
#include <stdio.h>
#include <string.h>
/*函数功能：从键盘读入学生的初始数据值
函数参数： 两个形式参数分别为结构体指针和预设记录条数
函数返回值：从键盘上实际读入的记录条数
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
		stu[i].total = 0;                /*总分需要计算求得，初值置为0*/
		printf("Input three courses of the student:\n");
		for (j = 0;j < 3;j++)
			scanf("%d", &stu[i].score[j]);
		stu[i].rank = 0;                 /*名次要根据总分计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}
/*函数功能：输出所有学生记录的值
函数参数： 两个形式参数分别为结构体指针和记录条数
函数返回值：无返回值
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
/*函数功能：判断两个Student记录是否相等
函数参数： 3个形式参数分别为待比较的两个结构体变量、比较条件
函数返回值：比较的结果，相等返回1，不相等返回0
*/
int equal(Student s1, Student s2, int condition)
{
	if (condition == 1)           /*如果参数condition的值为1，则比较学号*/
		return s1.num == s2.num;
	else if (condition == 2)       /*如果参数condition的值为2，则比较姓名*/
	{
		if (strcmp(s1.name, s2.name) == 0)
			return 1;
		else return 0;
	}
	else if (condition == 3)      /*如果参数condition的值为3，则比较名次*/
		return s1.rank == s2.rank;
	else if (condition == 4)      /*如果参数condition的值为4，则比较总分*/
		return s1.total == s2.total;
	else return 1;             /*其余情况返回1*/
}
/*函数功能：比较两个Student记录的大小
函数参数： 3个形式参数分别为待比较的两个结构体变量、比较条件
函数返回值：比较的结果，第1个记录大于第2个则返回1，否则返回0
*/
int larger(Student s1, Student s2, int condition)
{
	if (condition == 1)                   /*若condition的值为1，则比较学号*/
		return s1.num > s2.num;
	else if (condition == 2)               /*若condition的值为2，则比较总分*/
		return s1.total > s2.total;
	else return 1;                      /*其余情况返回1*/
}
/*函数功能：数组的元素逆置
函数参数： 两个形式参数分别为结构体指针和记录条数
函数返回值：无返回值
*/
void reverse(Student* stu, int n)
{
	int i;
	Student temp;
	for (i = 0;i < n / 2;i++)                  /*循环次数为元素数量的一半*/
	{
		temp = stu[i];
		stu[i] = stu[n - 1 - i];
		stu[n - 1 - i] = temp;
	}
}
/*函数功能：计算所有学生的总分
函数参数： 两个形式参数分别为结构体指针和记录条数
函数返回值：无返回值
*/
void calcuTotal(Student* stu, int n)
{
	int i, j;
	for (i = 0;i < n;i++)                   /*外层循环控制所有学生记录*/
	{
		stu[i].total = 0;
		for (j = 0;j < 3;j++)               /*内层循环控制三门功课*/
			stu[i].total += stu[i].score[j];
	}
}
/*函数功能：根据总分计算排名，同分同名次
函数参数： 两个形式参数分别为结构体指针和记录条数
函数返回值：无返回值
*/
void calcuRank(Student* stu, int n)
{
	int i;
	sortStu(stu, n, 2);                   /*调用sortStu算法按总分由小到大排序*/
	reverse(stu, n);                    /*再逆置，则按总分由大到小排序了*/
	stu[0].rank = 1;                    /*第一条记录的名次一定是1*/
	for (i = 1;i < n;i++)                  /*从第二条记录一直到最后一条循环*/
	{
		if (equal(stu[i], stu[i - 1], 4))       /*当前记录与其前一条记录总分相等*/
			stu[i].rank = stu[i - 1].rank;    /*当前记录名次等于其前一条记录名次*/
		else
			stu[i].rank = i + 1;           /*不相等时当前记录名次等于下标号+1*/
	}
}
/*函数功能：求三门课最高、最低、平均分
函数参数： 第1个形式参数m第一维代表3门课，第二维代表最高、最低、平均分，第2个形参是结构体指针，第3个形参是记录条数
函数返回值：无返回值
*/
void calcuMark(double m[3][3], Student stu[], int n)
{
	int i, j;
	for (i = 0;i < 3;i++)                    /*求三门课的最高分*/
	{
		m[i][0] = stu[0].score[i];
		for (j = 1;j < n;j++)
			if (m[i][0] < stu[j].score[i])
				m[i][0] = stu[j].score[i];
	}
	for (i = 0;i < 3;i++)                    /*求三门课的最低分*/
	{
		m[i][1] = stu[0].score[i];
		for (j = 1;j < n;j++)
			if (m[i][1] > stu[j].score[i])
				m[i][1] = stu[j].score[i];
	}
	for (i = 0;i < 3;i++)                    /*求三门课的平均分*/
	{
		m[i][2] = stu[0].score[i];
		for (j = 1;j < n;j++)
			m[i][2] += stu[j].score[i];
		m[i][2] /= n;
	}
}
/*函数功能：按condition规定的条件由小到大排序
函数参数：3个形参分别是结构体指针、记录条数、排序依据的条件
函数返回值：无返回值
*/
void sortStu(Student* stu, int n, int condition)
{
	int i, j, minpos;                     /*minpos存本趟最小元素所在的下标*/
	Student t;
	for (i = 0;i < n - 1;i++)                 /*控制循环的n-1趟*/
	{
		minpos = i;
		for (j = i + 1;j < n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(stu[minpos], stu[j], condition))
				minpos = j;
		if (i != minpos)                 /*保证本趟最小元素到达下标i的位置*/
		{
			t = stu[i];
			stu[i] = stu[minpos];
			stu[minpos] = t;
		}
	}
}
/*函数功能：按condition规定的条件查找指定记录是否存在
函数参数：5个形参分别是结构体指针、记录条数、待查找的记录、查找条件、查找到的多个元素对应下标所存放的数组f
函数返回值：查找到的记录条数
*/
int searchStu(Student* stu, int n, Student s, int condition, int* f[])
{
	int i, j = 0, find = 0;
	for (i = 0;i < n;i++)                         /*待查找的元素为s*/
		if (equal(stu[i], s, condition))
		{
			f[j++] = i;                        /*找到了将其下标放f数组中*/
			find++;	                       /*统计找到的元素个数*/
		}
	return find;                              /*返回find，值为0表示没找到*/
}
/*函数功能：向结构体数组中依学号递增插入一条记录
函数参数：3个形参分别是结构体指针、原来的记录条数、待插入的记录
函数返回值：插入后的实际记录条数
*/
int insertStu(Student* stu, int n, Student s)
{
	int i;
	sortStu(stu, n, 1);                          /*先按学号排序*/
	for (i = 0;i < n;i++)
		if (equal(stu[i], s, 1))                   /*学号相同不能插入，保证唯一*/
		{
			printf("this record exist,can not insert again!\n");
			return n;
		}
	for (i = n - 1;i >= 0;i--)                        /*按学号从小到大有序*/
	{
		if (!larger(stu[i], s, 1))                  /*若s大于当前元素则退出循环*/
			break;
		stu[i + 1] = stu[i];                       /*否则元素stu[i]后移一个位置*/
	}
	stu[i + 1] = s;                              /*在下标i+1处插入元素s*/
	n++;                                   /*元素个数增加1*/
	return n;                                /*返回现有元素个数*/
}
/*函数功能：从结构体数组中删除指定学号的一条记录
函数参数：3个形参分别是结构体指针、原来的记录条数、待删除的记录
函数返回值：删除后的实际记录条数
*/
int deleteStu(Student* stu, int n, Student s)
{
	int i, j;
	for (i = 0;i < n;i++)                           /*寻找待删除的元素*/
		if (equal(stu[i], s, 1))   break;            /*若找到相等元素则退出循环*/
	if (i == n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");     /*给出提示信息然后返回*/
		return n;
	}
	for (j = i; j < n - 1; j++)            /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/
		stu[j] = stu[j + 1];                       /*通过覆盖删除下标为i的元素*/
	n--;                                    /*元素个数减少1*/
	return n;                                /*返回现有元素个数*/
}
