#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define STACK_SIZE 10

typedef struct node{
    int val;
    struct node *next;
}node_t;

typedef struct stack{
    int size;
    int capacity;
    node_t *root;
}stack_t;

node_t *node_create(int val)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

stack_t *stack_create(int capacity)
{
    stack_t *new_stack = malloc(sizeof(stack_t));
    new_stack->size = 0;
    new_stack->capacity = capacity;
    new_stack->root = NULL;
    return new_stack;
}

//If stack is empty returns 1
int stack_isEmpty(stack_t *s)
{
    if(s->size == 0)
        return 1;
    return 0;
}

//If stack is full return 1
int stack_isFull(stack_t *s)
{
    if(s->size == s->capacity)
        return 1;
    return 0;
}


//This function adds new value to stack
//If successful returns 0 else returns -1
int stack_push(stack_t *s, int val)
{
    node_t *new_node;
    if(stack_isFull(s))
    {
        printf("Stack Overflow !!!\n");
        return -1;
    }

    if(stack_isEmpty(s))
    {
        s->root = node_create(val);
        s->size++;
    }
    else
    {
        new_node = node_create(val);
        new_node->next = s->root;
        s->root = new_node;
        s->size++;
    }
    return 0;
}

//This function pops the top node and returns the value
//If successful returns 0 else returns -1
int stack_pop(stack_t *s, int *val)
{
    node_t *temp = s->root;

    if(stack_isEmpty(s))
    {
        printf("Stack is Empty !!!\n");
        return -1;
    }

    *val = temp->val;
    s->root = temp->next;
    free(temp);
    s->size--;
    return 0;
}

//This function lists the stack
void stack_print(stack_t *s)
{
    puts("Stack Print");
    for(node_t *temp = s->root; temp!=NULL; temp=temp->next)
    {
        printf("%d\n", temp->val);
    }
}

int main()
{
    srand(time(NULL));
    stack_t *main_stack = stack_create(STACK_SIZE);

    for(int i = 0; i<STACK_SIZE+2; i++)
    {
        if( stack_push(main_stack, rand() % 100) )
            break;
    }

    stack_print(main_stack);

    int val;
    for(int i = 0; i<STACK_SIZE+2; i++)
    {
        if( stack_pop(main_stack, &val) )
            break;
        printf("%d is popped \n", val);
    }

    return 0;
}
