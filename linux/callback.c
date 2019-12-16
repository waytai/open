#include <stdlib.h> 
 #include <stdio.h> 
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(int))
{  
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue(i);
} 

// 获取随机值
int getNextRandomValue(int a)
{  
    return a*a;
    //return rand();
} 

int main(void){  
    int myarray[10];  
    populate_array(myarray, 10, getNextRandomValue);  
    for(int i = 0; i < 10; i++) {    
     printf("%d ", myarray[i]);
      }  
    printf("\n");  
    return 0;
}
