#include <stdlib.h>
#include <stdio.h>
int test(int *p){
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%d\n", p[1]);
    return 0;
}

int test2(int p[]){
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%d\n", p[1]);
    return 0;
}

int main(){
    int a[5] = {5, 6, 7, 8, 9};
    test(a);
    test2(a);
    return 0;
}


