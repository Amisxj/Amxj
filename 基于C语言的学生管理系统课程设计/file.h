/*③file.h文件的内容如下：*/
#ifndef _FILE                   /*条件编译，防止重复包含的错误*/
#define _FILE
#include "student.h"        
int createFile(Student* stu);       /*建立初始的数据文件*/
int readFile(Student* stu);        /*将文件中的内容读出置于结构体数组stu中*/
void saveFile(Student* stu, int n);   /*将结构体数组的内容写入文件*/
#endif	
