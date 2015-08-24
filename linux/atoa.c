/*************************************************************************
    > File Name: atoa.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 20时53分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *a = "-100.23";
    char *b = "100e-2";
    int c;
    c = atoi(a) + atoi(b);
    printf("%d\n",c);
    return 0;
    }
