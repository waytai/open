#include <stdio.h>
typedef char (*PTR_TO_ARR)[30];
typedef int (*PTR_TO_FUNC)(int, int);
typedef void (*PTR_TO_SWAP)(int *a, int *b);
int max(int a, int b){
    return a>b ? a : b;
}

void find_max(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
char str[3][30] = {
    "http://c.biancheng.net",
    "C语言中文网",
    "C-Language"
};
int main(){
    PTR_TO_ARR parr = str;
    PTR_TO_FUNC pfunc = max;
    PTR_TO_SWAP pfund = find_max;
    int i;
   
    printf("max: %d\n", (*pfunc)(10, 20));
    for(i=0; i<3; i++){
        printf("str[%d]: %s\n", i, *(parr+i));
    }

    int e = 30, f = 40;
    (*pfund)(&e, &f);
    printf("%d\n", e);
    printf("%d\n", f);
    return 0;
}
