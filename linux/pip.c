/*************************************************************************
    > File Name: pip.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月22日 星期六 22时40分56秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
    pid_t pid;
    char *messges;
    int n;

    printf("fork program start\n");
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork erro\n");
            exit(1);
        case 0:
            messges = "this is child\n";
            n = 5;
            break;
        default:
            messges  = "this is parent\n";
            n = 3;
            break;
        }
        for(; n > 0; n--)
        {
            puts(messges);
            sleep(1);
            }
    exit(0);
    }
