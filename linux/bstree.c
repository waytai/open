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


BSTree bstree_search(BSTree x, int k){
    if(x == NULL||x->key == k){
        return x;
    }
    if(x < x->left){
        bstree_search(x->left, k);
    }
    else{
        bstree_search(x->right, k);
    }
}

BSTree bstree_search_parent(BSTree x, int k){
    BSTree parent;
    while(1){
        if(k > x->key){
            x = x->right;
        }
        else if(k < x->key){
            x = x->left;
        }
        else if(k == x->key){
            return k;
        }

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


void delete_bstree(BSTree tree, int k){
    BSTree z;
    z = bstree_search(tree, k);
    if(z->left == NULL, z->right ==NULL){
        free(z);
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
