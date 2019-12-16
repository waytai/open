#include <stdio.h> 
int max(int x, int y)
{  
    return x > y ? x : y;
} 


typedef int (*m)(int, int);

int main(void){  
    /* p 是函数指针 */ 
    //int (* p)(int, int) = & max; // &可以省略  
    int (* p)(int, int) = max; // &可以省略  
    int (* q)(int, int) = &max; // &可以省略  
    m mm = max;
    printf("%d\n", p(3,4));
    printf("%d\n", q(3,4));
    printf("%d\n", mm(3,4));
    printf("%p\n",p);
    printf("%p\n",*p);
    printf("%p\n",q);
    printf("%p\n",*q);
    printf("%p\n",mm);
    printf("%p\n",*mm);
    return 0;
}

//#include <stdio.h> 
//int max(int x, int y){  
//return x > y ? x : y;
//} 
//int main(void){  
///* p 是函数指针 */ 
//int (* p)(int, int) = & max; // &可以省略  
//int a, b, c, d;  
//printf("请输入三个数字:");  
//scanf("%d %d %d", & a, & b, & c);   /* 与直接调用函数等价，d = max(max(a, b), c) */ 
//d = p(p(a, b), c);   
//printf("最大的数字是: %d\n", d);   
//return 0;
//}
