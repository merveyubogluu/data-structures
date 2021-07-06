#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n * next;
}node;


int yazdir(node * r){
    if(r == NULL){
        return 0;
    }
    node * iter = r;
    printf("%d ",r->x);
    iter = iter->next;
    while(iter != r){
        printf("%d ",iter->x);
        iter = iter->next;
    }
}

node * sil(node *r , int x){
    if(r->next == r){
        printf("List is empty!");
        node * iter = NULL;
        return iter;
    }
    node * iter = r;
    if(iter->x == x){
        node * temp = (node* ) malloc(sizeof(node));
        temp = iter->next;
        while(iter->next != r){
            iter=iter->next;
        }
        iter->next = temp;
        return temp;
    }
    while(iter->next->x != x){
        iter = iter->next;
    }
    iter->next= iter->next->next;
    return iter;
}

int main(){
    node * root = (node *) malloc(sizeof(node));
    root->x = 0;
    root->next = (node *) malloc(sizeof(node));
    root->next->x = 1;
    root->next->next = (node *) malloc(sizeof(node));
    root->next->next->x = 2;
    root->next->next->next = root;
    yazdir(root);
    printf("\n");
    root = sil(root, 2);
    yazdir(root);
    printf("\n");
    root = sil(root, 0);
    yazdir(root);
    printf("\n");
    root = sil(root, 1);
    yazdir(root);
    return 0;
}