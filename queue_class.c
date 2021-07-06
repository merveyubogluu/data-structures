#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node * next;
}node_t;

typedef struct queue{
    int size;
    int capacity;
    node_t *front;
    node_t *rear;
}queue_t;


node_t *create_node(char c){
    node_t * new_node = malloc(sizeof(node_t));
    new_node->c = c;
    new_node->next = NULL;
    return new_node;
}

queue_t* create_queue(int capacity){
    queue_t *q = malloc(sizeof(queue_t));
    q->size = 0;
    q->capacity = capacity;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int enqueue(queue_t *q, char c)
{
    node_t *new_node = create_node(c);
    if (q->rear == NULL)
    {
        q->rear = new_node;
        q->front = new_node;
        q->size++;
        return 0;
    }

    q->rear->next = new_node;
    q->rear = new_node;
    q->size++;
    return 0;

}

int deqeueu(queue_t *q, char *c)
{
    if(q->front == NULL)
        return -1;
    node_t * temp = q->front;
    *c = q->front->c;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return 0;
}

int main(){
    queue_t *main_queue =create_queue(10);
    char c;

    enqueue(main_queue, 'h');
    enqueue(main_queue, 'e');
    enqueue(main_queue, 'l');
    enqueue(main_queue, 'l');
    enqueue(main_queue, 'o');
    

    for(int i=0;i<20;i++)
    {
        if(deqeueu(main_queue,&c))
        {
            printf("Queue empty.\n");
            break;
        }
        printf("%c ",c);
    }

}
