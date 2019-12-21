#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct person{
    int age;
    char name[20];
    struct person *pre;
    struct person *next;

} Person, *PPerson;

void init_list(PPerson ps)
{
    ps->age = 0;
    strcpy(ps->name, "liu");
    ps->pre = ps;
    ps->next = ps;
}

void add_tail(PPerson new, PPerson pre, PPerson next){
    new->next = pre->next;
    pre->next = new;
    new->pre = pre;
    next->pre = new;
}


PPerson del_node(PPerson ps){
    PPerson pre, next;
    pre = ps->pre;
    next = ps->next;
    ps->pre->next = next;
    ps->next->pre = pre;
    free(ps);
    return pre;
}

void print_list(PPerson ps){
    PPerson p;
    printf("%d ", ps->age);
    printf("%s \n", ps->name);
    p = ps->next;
    while(p!=ps){
        printf("%d ", p->age);
        printf("%s ", p->name);
        p = p->next;
        printf("\n");
    }
    printf("\n");
}

void print_list2(PPerson ps){
    PPerson p;
    printf("===============\n");
    for(int i=0;i<100;i++){
        printf("%d ", p->age);
        printf("%s ", p->name);
        p = p->next;
        printf("\n");
    }
    printf("\n");
    }

int main(){
    PPerson ps1;
    PPerson pps;
    ps1 = (PPerson)malloc(sizeof(Person));
    init_list(ps1);
    printf("%d  ", ps1->age);
    printf("%s -----\n", ps1->name);

    for(int i=0; i<5; i++){
        pps = (PPerson)malloc(sizeof(Person));
        pps->age = (i+1)*10;
        sprintf(pps->name, "name%d", i+1);
        add_tail(pps, ps1->pre, ps1);
    }

    print_list(ps1);

    PPerson ps2 = del_node(ps1);
    print_list(ps2);
    //print_list2(ps2);
    return 0;
}


