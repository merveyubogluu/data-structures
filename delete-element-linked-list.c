#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n * next;
}node;

void bastir(node * r){
    while(r != NULL){
        printf("%d ", r->x);
        r = r->next;
    }
}

void ekle( node *r,int x){
    while(r->next != NULL){
        r=r->next;
    }
    r->next = (node*) malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL; 
}

node * ekleSirali(node * r, int x){
    // linked list bossa
    if (r == NULL){
        r = (node *) malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r;
    }

    // ilk elemandan kucuk durumu
    if(r->x > x){
        // root degisiyor
        node *temp = (node *) malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        r = temp;
        return temp;
    }

    node *iter = r;
    while(iter->next != NULL && iter->next->x <x){
        iter = iter->next;
    }

    node * temp = (node *) malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;

}

void sil(node * r, int x){

    node *iter = r;

    if(r == NULL){
        return;
    }

    if(r->x == x){
        if(r->next == NULL){
            r = iter;
            iter = NULL;
            return;
        }
        else if(r->next->next == NULL){
            r->x = r->next->x;
            r->next = r->next->next;
            return;
        }    
        
        r->x = r->next->x;
        r->next = r->next->next;
        return;
    }

    while(iter->next !=NULL && iter->next->x != x){
        iter = iter->next;
    }
    
    if(iter->next->next == NULL){
        iter->next = NULL;
        return;
    }

    iter->next = iter->next->next;
    return;
}

int main(){
    node * root;
    root = NULL;

    root = ekleSirali(root, 400);
    root = ekleSirali(root, 40);
    root = ekleSirali(root, 5);
    root = ekleSirali(root, 450);
    root = ekleSirali(root, 50);
    bastir(root);
    printf("\n");
    sil(root,50);
    bastir(root);
    printf("\n");
    sil(root,450);
    bastir(root);
    printf("\n");
    sil(root,5);
    bastir(root);
    printf("\n");
    sil(root,40);
    bastir(root);
    printf("\n");
    sil(root,400);
    bastir(root);
    return 0;
}
