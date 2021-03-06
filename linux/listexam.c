#include <stdlib.h>
#include<stdio.h>

typedef struct Lnode{
    int data;
    struct Lnode *next;
} LND, *lnd;

lnd malloclist(lnd l){
    l = (lnd)malloc(sizeof(LND));
    return l;
}


int initlist(lnd l, int n){
    l->data = n;
    l->next = NULL;
    lnd p;
    for(int i =n; i>0; --i){
        p = (lnd)malloc(sizeof(LND));
        p->data = i;
        p->next = l->next;
        l->next = p;
    }
    return 0;
}

int len_list(lnd l){
    int len;
    while(l){
        l = l->next;
        ++len;
    }
    return len;
}

int insert_list_ele(lnd l, int n, int e){
    lnd p;
    p = (lnd)malloc(sizeof(LND));
    p->data = e;
    p->next = NULL;
    while(n--){
        l = l->next;
    }
    p->next = l->next;
    l->next = p;
    return 0;
}

int delete_list_ele(lnd l, int n){
    lnd p,q;
    while(--n){
        l = l->next;
    }
    q = l;
    p = l->next;
    q->next = p->next;
    free(p);
    return 0;
}

lnd destory_list(lnd l){
    lnd p;
    while(l){
        p = l->next;
        free(l);
        l = p;
    }
    return l;
}

lnd clear_list(lnd l){
    lnd p,q;
    p = l->next;
    while(p!=NULL){
        q = p ->next;
        free(p);
        p = q;
    }
    l->next =NULL;
    return l;

}


int print_list(lnd l){
    while(l){
    printf("%d\n", l->data);
    l = l->next;
    }
    return 0;
}

int main(){
    lnd lst;
    lst = malloclist(lst);
    initlist(lst, 4);
    printf("len list is %d\n", len_list(lst));
    print_list(lst);
    printf("插入数据后:\n");
    insert_list_ele(lst, 2, 89);
    print_list(lst);
    printf("删除数据后\n");
    delete_list_ele(lst, 2);
    print_list(lst);

    printf("清空后数据\n");
    lnd em = clear_list(lst);
    print_list(em);
}

