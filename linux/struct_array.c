#include <stdlib.h>
#include <stdio.h>
typedef struct Alist{
    int a;
} ALIST[20];

int main(){
    ALIST a;
    for(int i=0; i<20; i++){
        a[i].a = i;
    }

    for(int i=0; i<20; i++){
        printf("%d\n", a[i].a);
    }

    return 0;
}

