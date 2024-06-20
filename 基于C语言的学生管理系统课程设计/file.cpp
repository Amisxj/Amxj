#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "file.h"
/*函数功能：将文件中内容读出置于数组中
函数参数：形参是结构体指针
函数返回值：从文件中读出的实际记录条数
*/
int readFile(Student* stu)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("c:\\student.dat", "rb")) == NULL)   /*以读方式打开指定文件*/
	{
		printf("file does not exist,create it first:\n");   /*若打开失败输出提示信息*/
		return 0;                               /*然后返回0*/
	}
	fread(&stu[i], sizeStu, 1, fp);                   /*读出第一条记录*/
	while (!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
		fread(&stu[i], sizeStu, 1, fp);               /*再读出下一条记录*/
	}
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}
/*函数功能：将结构体数组内容写入文件
函数参数：两个形参分别是结构体指针、实际记录条数
函数返回值：无返回值
*/
void saveFile(Student* stu, int n)
{
	FILE* fp;
	if ((fp = fopen("c:\\student.dat", "wb")) == NULL) /*以写方式打开指定文件*/
	{
		printf("can not open file !\n");            /*若打开失败，输出提示信息*/
		exit(0);                              /*然后退出*/
	}
	fwrite(stu, sizeStu, n, fp);                     /*一次性向文件写入n条记录*/
	fclose(fp);                               /*关闭文件*/
}
/*函数功能：建立初始的数据文件
函数参数：形参分别为结构体指针
函数返回值：返回写入文件的记录条数
*/
int  createFile(Student* stu)
{
	FILE* fp;
	int n;
	if ((fp = fopen("c:\\student.dat", "wb")) == NULL) /*指定文件名，以写方式打开*/
	{
		printf("can not open file !\n");            /*若打开失败，输出提示信息*/
		exit(0);                              /*然后退出*/
	}
	printf("input students\' information:\n");
	n = readStu(stu, NUM);                    /*调用student.h中的函数读数据*/
	fwrite(stu, sizeStu, n, fp);                   /*将读入的所有记录全写入文件*/
	fclose(fp);                              /*关闭文件*/
	return n;                               /*返回记录条数*/
}
