/*************************************************************************
    > File Name: pagesize.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 20时58分04秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("page size = %d\n", getpagesize());
    }
