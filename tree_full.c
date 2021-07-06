#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    struct node *left, *right;
    struct node *next;
}node_t;

void preorder(node_t * ptr){
    if(ptr){
        printf("%d ",ptr->val);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(node_t * ptr){
    if(ptr){
        inorder(ptr->left);
        printf("%d ",ptr->val);
        inorder(ptr->right);
    }
}

void postorder(node_t * ptr){
    if(ptr){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->val);
    }
}

node_t *create_node(int val){
    node_t * new_node = malloc(sizeof(node_t));

    new_node->val = val;

    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(node_t **node_ref,int val){
    if (*node_ref == NULL){
        *node_ref = create_node(val);
        return;
    }
    else if(val <= (*node_ref)->val){
        insert(&((*node_ref)->left), val);
    }
    else if(val > (*node_ref)->val){
        insert(&((*node_ref)->right), val);
    }
}

int main(){
    node_t * root = NULL;

    for(int i =0; i<20;i++){
        insert(&root, i);
    }

    postorder(root);
    return 0;
}