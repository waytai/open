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


BSTree insert_bstree_recursion(BSTree tree, int key_value){
    if(tree == NULL){
        tree = (Node*)malloc(sizeof(Node));
        tree->key = key_value;
        tree->left = tree->right = NULL;
        return tree;
    }
    if(key_value > tree->key){
        tree->right = insert_bstree_recursion(tree->right, key_value);
    }
    else{
        tree->left = insert_bstree_recursion(tree->left, key_value);
    }

}

void insert_bstree_test(BSTree tree, int key_value){
    Node *parent, *head, *p;
    head = tree;
    p = (Node*)malloc(sizeof(Node));
    p->key = key_value;
    p->left = p->right = NULL;
    while(head){
        parent = head;
        if(key_value > head->key){
            printf("insert right and value is %d\n", parent->key);
            head = head->right;
        }
        else{
            printf("insert left and value is %d\n", parent->key);
            head = head->left;
        }
    }
    printf("parent key is %d\n", parent->key);

    if(key_value < parent->key){
        parent->left= p;
    }
    else
        parent->right = p;
    //else{
    //    parent->right= p;
    //}
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


BSTree bstree_search(BSTree x, int k, BSTree p){
    if(x == NULL||x->key == k){
        return x;
    }
    p = x;
    if(x < x->left){
        bstree_search(x->left, k, p);
    }
    else{
        bstree_search(x->right, k, p);
    }
}



BSTree bstree_search_successor_parent(BSTree pnode, BSTree node){
    while(1){
        if(node->left == NULL){
            pnode = node;
            pnode = pnode->left;
        }
    }
    return pnode;
}


int delete_bstree(BSTree tree, int k){
    if (!tree){
        return 0;
    }

    BSTree z, parent;
    z = bstree_search(tree, k, parent);
    if(z->left == NULL, z->right ==NULL){
        parent->left = parent->right =NULL;
        free(z);
    }

    if(z->left == NULL && z->right != NULL){
        if(parent->left == z){
            parent->left = z->right;
        }
        else{
            parent->right = z->right;
        }
    }
    else if(z->right == NULL && z->left!= NULL){
        if(parent->left == z){
            parent->left = z->right;
        }
        else{
            parent->right = z->right;
        }
    }
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
       //insert_bstree(root, arr[i]);
       //insert_bstree_test(root, arr[i]);
       insert_bstree_recursion(root, arr[i]);
       printf("====\n");
    }

    //insert_bstree_test(root, 9);
    //preoder_tree(root);
    //printf("====\n");
    preoder_tree(root);
    return 0;
}
