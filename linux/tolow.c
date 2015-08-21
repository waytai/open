/*************************************************************************
    > File Name: tolow.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 21时01分43秒
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
int main()
{
    char s[] = "aBcDefg";
    int i;
    printf("before tolower():%s\n", s);
    for(i=0; i<sizeof(s);i++)
    {
        s[i] = tolower(s[i]);
        }
    printf("after tolower():%s\n", s);
    return 0;
    }
