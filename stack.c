#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n * next;
}node;

void bastir(node * r){
    while(r != NULL){
        printf(" %d ", r->data);
        r = r->next;
    }
}

int pop(node * root){
    if(root == NULL){
        printf("stack bos");
        return -1;
    }
    node * iter = root;
    if(iter->next == NULL){
        int rvalue= root->data;
        free(root);
        return rvalue;
    }
    while(iter->next->next != NULL){
        iter = iter->next;
    }
    node * temp = iter->next;
    int rvalue = temp->data;
    iter->next = NULL;
    free(temp);
    return rvalue;
}

node * push(node * root, int a){
    if(root==NULL){
        root = (node *) malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        return root;
    }
    node * iter = root;
    while(iter->next != NULL){
        iter = iter->next;
    }
    node * temp = (node * ) malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;
    return root;
}

int main(){
    node * s = NULL;

    

    for(int i=0; i<15;i++){
        s = push(s,i);
    }
    bastir(s);
    printf("\n");
    for(int i=0; i<15;i++){
        printf(" %d ",pop(s));
    }
}