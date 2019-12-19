#include <stdlib.h>
#include <malloc.h>
static int *arr = NULL;
static int count = 0;

int create_queue(int sz){
    arr = (int *)malloc(sz*sizeof(int));
    count = 0;
    return 0;
}


int destroy_array_queue(){
    if(arr){
    free(arr);
    arr = NULL;
    }
    return 0;
}

void add_queue(int val){
    arr[count++] = val;
}

int pop(){
    int ret = arr[0];
    int len = count;
    for(int i =1; i < len; i++){
        arr[i-1] = arr[i];
    }
    count--;
    return ret;
}

int size(){
    return count;
}

int is_empty(){

    if(count == 0)
        return 1;
    else
        return 0;
}

void print_arr(){
    for(int i = 0;i < count; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main(){
    create_queue(20);
    add_queue(34);
    add_queue(22);
    add_queue(42);
    print_arr();
    printf("========\n");
    pop();
    print_arr();
    printf("%d\n",count);
    return 0;
}
