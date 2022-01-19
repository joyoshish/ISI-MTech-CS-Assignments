#include <stdio.h>
#include <stdlib.h>


typedef struct listNode
{
    int data;
    struct listNode *next;
}SLLNode;

typedef struct QueueLL
{
    SLLNode *front;
    SLLNode *rear;
}Queue;

Queue *Create ()
{
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = NULL;
    return Q;
}

int isEmptyQueue (Queue *Q)
{
    return (Q->front == NULL);
}

void Enqueue (Queue *Q, int data)
{
    SLLNode *newNode;
    newNode = (SLLNode*)malloc(sizeof(SLLNode));
    newNode->data = data;
    newNode->next = NULL;
    if (Q->rear)
    {
        Q->rear->next = newNode;
    }
    Q->rear = newNode;
    if (Q->front == NULL)
    {
        Q->front = Q->rear;
    }
}

void Dequeue (Queue *Q)
{
    int data;
    SLLNode *temp;
    if (isEmptyQueue(Q))
    {
        printf ("Empty Queue!\n");
    }
    else
    {
        temp = Q->front;
        data = temp->data;
        Q->front = Q->front->next;
        free (temp);
        printf ("%d dequeued from Queue!\n", data);
    }
}

void deleteQueue (Queue *Q)
{
    SLLNode *temp;
    while (Q->front)
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free (temp);
    }
    free (Q);
}

void Display (Queue *Q)
{
    SLLNode *temp = Q->front;
    while (temp)
    {
        printf ("%d\t", temp->data);
        temp = temp->next;
    }
    printf ("\n");
}
