#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tree_size = 100;

typedef struct node{
    int val;
    struct node *left, *right;
    struct node *next;
}node_t;

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
    srand(time(NULL));

    for(int i =0; i<tree_size;i++){
        insert(&root, rand()%10);
    }

    return 0;
}