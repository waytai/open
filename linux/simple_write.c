/*************************************************************************
    > File Name: simple_write.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月18日 星期二 21时57分51秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    if(write(1, "here is some data\n", 18) != 18)
        write(2,"there is not 18 character\n",27);
    exit(0);
    }
