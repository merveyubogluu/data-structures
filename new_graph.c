#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int dest;
    struct node *next;
}node_t;

typedef struct adjecy_list{
    node_t *head;
}adjecy_list_t;

typedef struct graph{
    int number_of_vertices;
    adjecy_list_t * list;
}graph_t;

typedef struct queue{
    int size;
    int capacity;
    node_t *front;
    node_t *rear;
}queue_t;

node_t * create_node(int dest){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}



graph_t *create_graph(int n){
    graph_t *graph = malloc(sizeof(graph_t));

    graph->list = malloc(sizeof(node_t)*n);
    graph->number_of_vertices = n;

    for(int i=0;i<n;i++){
        graph->list[i].head = NULL;

    }
    return graph;


}

void add_edge(graph_t *graph, int src, int dest){
    node_t * new_node = create_node(dest);
    new_node->next = graph->list[src].head;
    graph->list[src].head = new_node;

    new_node = create_node(src);
    new_node->next = graph->list[dest].head;
    graph->list[dest].head = new_node;
}

void print_graph(graph_t * graph){
    for(int i = 0;i<graph->number_of_vertices;i++){
        node_t *temp = graph->list[i].head;
        while(temp != NULL){
            printf(" (%d -> %d)   ",i, temp->dest);
            temp = temp->next;
        }

        printf("\n");
    }
}

int deqeueu(queue_t *q);

void enqueue(queue_t *q, int dest)
{
    node_t *new_node = create_node(dest);
    if (q->rear == NULL)
    {
        q->rear = new_node;
        q->front = new_node;
    }

    else if(q->size == q->capacity)
    {
        dest = deqeueu(q);
        q->rear->next = new_node;
        q->rear = new_node;
    }
    else{
        q->rear->next = new_node;
        q->rear = new_node;

    }
    q->size++;
}

int deqeueu(queue_t *q)
{
    int dest;

    node_t * temp = q->front;

    if(q->front == NULL)
    {
        printf("Queue is empty!");
        return -1;
    }

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    dest = temp->dest;
    free(temp);

    q->size--;

    return dest;
}

int is_queue_empty(queue_t *q){
    if(q->size == 0)
        return 1;
    return 0;
}

queue_t* create_queue(int capacity){
    queue_t *q = malloc(sizeof(queue_t));
    q->size = 0;
    q->capacity = capacity;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void bfs(graph_t *graph, int start_vertex)
{
    int visited[graph->number_of_vertices];

    for(int i = 0;i<graph->number_of_vertices;i++){
        visited[i] = 0;
    }
    int current_vertex;
    queue_t *q = create_queue(10);

    enqueue(q, start_vertex);
    visited[start_vertex] = 1;

    while(is_queue_empty){
        current_vertex = deqeueu(q);
        printf("Visited: %d\n", current_vertex);

        node_t *temp = graph->list[current_vertex].head;

        while(temp != NULL){
            int adjVertex = temp->dest;

            if(visited[adjVertex] == 0){
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}




void main(){
    graph_t *new_graph;

    new_graph = create_graph(5);

    add_edge(new_graph,0,1);
    add_edge(new_graph,0,2);
    add_edge(new_graph,1,2);
    add_edge(new_graph,1,3);
    add_edge(new_graph,3,0);
    add_edge(new_graph,3,4);

    print_graph(new_graph);

    bfs(new_graph, 1);

    return;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}