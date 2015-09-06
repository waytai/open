/*************************************************************************
    > File Name: fac.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年09月06日 星期日 14时36分30秒
 ************************************************************************/

#include<stdio.h>

int fac(unsigned int i)
{

    if(i == 0)
    {
        return 1;
    }
    return i*fac(i-1);
}

int main()
{
    int res;
    res = fac(6);
    printf("%d\n", res);
}







