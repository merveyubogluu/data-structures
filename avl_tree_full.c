#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    int height;
    struct node *left, *right;
    struct node *next;
}node_t;

int get_height(node_t *node){

    if(node == NULL)
        return 0;

    return node->height;
}

void calculate_height(node_t * node){
    int new_height = 0;

    if(node == NULL){
        return;
    }

    if(get_height(node->left)>get_height(node->right)){
        new_height = get_height(node->left)+1;
    }
    else
        new_height = get_height(node->right)+1;

    node->height = new_height;

}

node_t *create_node(int val){
    node_t * new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int get_balance(node_t * node){
    if(node ==NULL)
        return 0;
    
    return get_height(node->left)-get_height(node->right);
}

void right_rotate(node_t **y_ref){
    node_t *x = (*y_ref)->left;
    node_t *T2 = x->right;

    (*y_ref)->left = T2;
    x->right = (*y_ref);

    calculate_height((*y_ref));
    calculate_height((x));

    (*y_ref) = x;
}

void left_rotate(node_t **x_ref){
    node_t *y = (*x_ref)->right;
    node_t *T2 = y->left;

    (*x_ref)->right = T2;
    y->left = (*x_ref);

    calculate_height((*x_ref));
    calculate_height((y));

    (*x_ref) = y;
}

void insert(node_t **node_ref,int val){

    int balance = 0;

    if (*node_ref == NULL){
        *node_ref = create_node(val);
        return;
    }
    
    if(val <= (*node_ref)->val){
        insert(&((*node_ref)->left), val);
    }
    else if(val > (*node_ref)->val){
        insert(&((*node_ref)->right), val);
    }
    calculate_height(*node_ref);
    balance = get_balance(*node_ref);
    printf("node key is: %d, height: %d, balance: %d\n",(*node_ref)->val,(*node_ref)->height, balance);

    if(balance>1){
        //left
        if(get_balance((*node_ref)->left) >= 0)
        {
            //right rotate curent
            right_rotate(node_ref);
        }
        else
        {
            //left rotate left node
            //right rotate current
            left_rotate(&((*node_ref)->left));
            right_rotate(node_ref);
        }
    }

    if(balance < -1){
        //right        
        
        if(get_balance((*node_ref)->right) <= 0)
        {
            //left rotate curent
            left_rotate(node_ref);
        }
        else
        {
            //right rotate right node
            //left rotate current
            right_rotate(&((*node_ref)->right));
            left_rotate(node_ref);
        }
    }

}

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


int main(){
    node_t * root = NULL;

    for(int i =0; i<20;i++){
        insert(&root, i);
    }

    inorder(root);
    return 0;
}