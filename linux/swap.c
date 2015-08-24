/*************************************************************************
    > File Name: swap.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月15日 星期六 15时07分40秒
 ************************************************************************/

#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; 
}

int main()
{
    int one=1,two=2;
    swap(&one, &two);
    printf("one is %d\n", one);
    printf("two is %d\n", two);
    return 0;
}

