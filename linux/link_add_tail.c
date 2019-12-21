#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int age;
    struct student *next;
} Student, *PStudent;

int main(){
    Student *p;
    p = (PStudent)malloc(sizeof(Student));
    p->next = NULL;
    p->age = 23;

    while(NULL != p->next ){
        p = p->next;
    }
    if(p == NULL){
        printf("p is null\n");
    }
    else{
     printf("age  is %d\n", p->age);
    }


    return 0;
}
