#include<stdio.h>
#include<stdlib.h>

typedef struct BSTreeNode{
    int key;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    //struct BSTreeNode *parent;

} Node, *BSTree;

static int arr[] = {1, 5, 4, 3, 2, 6};
#define TBL_SIZE(a) ((sizeof(a)/sizeof(a[0])))

//BSTree create_bstree_node(int key,BSTree parent, BSTree left, BSTree right){
BSTree create_bstree_node(int key, BSTree left, BSTree right){
    Node *p;
    if((p =(BSTree)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    //p->parent = parent;
}

void preoder_tree(BSTree tree){
    if(tree != NULL){
        printf("%d ", tree->key);
        preoder_tree(tree->left);
        preoder_tree(tree->right);
    }

}

void insert_bstree_test(BSTree tree, int key_value){
    Node *x, *y;
    x = tree;
    y = (Node*)malloc(sizeof(Node));
    y->key = key_value;
    y->left = y->right = NULL;
    int flag;
    while(x->left != NULL && x->right != NULL){
        if(key_value > x->key){
            x = x->right;
            flag = 0;
        }
        else{
            x = x->left;
            flag = 1;
        }
    }

    if(flag){
        x->left->key = key_value;
    }
    else{
    x->right->key = key_value;
    }

    x->left = x->right = NULL;
}

void insert_bstree(BSTree tree, int key_value){
    //if(tree->key == 0){
    //    tree->key = key_value;
    //}
    Node *parent, *head, *p;
    head = tree;
    p = (Node*)malloc(sizeof(Node));
    p->key = key_value;
    p->left = p->right = NULL;
    while(head){
        parent = head;
        if(key_value > head->key){
            head = head->right;
        }
        else
            head = head->left;
    }

    if(key_value < parent->key){
        parent->left = p;
    }
    else
        parent->right = p;
}



int main(){
    int tree_len;
    BSTree root =  NULL;
    tree_len = TBL_SIZE(arr);
    root = (Node*)malloc(sizeof(Node));
    root->key = arr[0];
    root->left = NULL;
    root->right= NULL;

    for(int i =1;i<tree_len;i++){
       // insert_bstree(root, arr[i]);
       insert_bstree_test(root, arr[i]);
    }

    printf("====\n");
    preoder_tree(root);
    return 0;
}
