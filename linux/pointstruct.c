#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct student {
	int age;
	char sex;
	char name[30];
} ST, *st;
 
void inputstudent(st ps)//对结构体变量输入时必须传地址
{
	ps->age = 10;
	strcpy(ps->name, "张三");
	ps->sex = 'f';
}
 
void outputstudent(st ps)//对结构体变量输出时，可传地址也可传内容，但为了减少内存耗费，提高运行速度，建议使用传值
{
	printf("%d %c %s\n", ps->age, ps->sex, ps->name);
}
int main()
{
	st stt;
    stt = (ST*)malloc(sizeof(ST));
	inputstudent(stt);
	outputstudent(stt);
	return 0;
}

