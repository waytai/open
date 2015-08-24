/*************************************************************************
    > File Name: system.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月22日 星期六 22时35分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("running the system\n");
    system("ps -ax");
    printf("done\n");
    exit(0);
    return 0;
    }
