#include<stdio.h>
#define MAXITEM 16
#define MAXR 10
#define MAXD 8
typedef struct
{
    double data[MAXITEM];
    int front,rear;
}queue;

int initQueue(queue* q){
    q->front= 0;
    q->rear = 0;
}

int queueEmpty(queue* q){
    return q->front == q->rear;
}

int inQueue(queue* q,double insert){
    if((q->rear+1)%MAXITEM == q->front){
        return -1;
    }
    q->rear = (q->rear+1)%MAXITEM;
    q->data[q->rear] = insert;
}

double outQueue(queue* q){
    if(queueEmpty(q)){return -1;}
    q->front = (q->front+1)%MAXITEM;
    return q->data[q->front];
}
