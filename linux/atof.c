/*************************************************************************
    > File Name: atof.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 20时50分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *a = "-100.23";
    char *b = "100e-2";
    float c;
    c = atof(a) + atof(b);
    printf("%f\n",c);
    return 0;
    }
