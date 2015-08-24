/*************************************************************************
    > File Name: memset.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 21时07分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *s;
    s = malloc(sizeof(char)*30);
    printf("sizeof s is %d\n", sizeof(s));
    memset(s, 'A', 30);
    printf("%s\n", s);
    return 0;
    }
