#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5 //定义队列的最大容量

//定义循环队列的结构体
typedef struct{
    int items[MAX_SIZE];
    int front;
    int rear;
}Circularqueue;

//初始化队列
void initQueue(Circularqueue *q){
    q->front=-1;
    q->rear=-1;
}

//检查队列是否为空
int isEmpty(Circularqueue *q){
    return (q->front==-1);
}

//检查队列是否为满
int isFull(Circularqueue *q){
    return (q->rear+1)%MAX_SIZE==q->front;
}

//插入元素到队列
void enqueue(Circularqueue *q,int value){
    if(isFull(q)){
        printf("Queue is full.Cannot enqueue %d\n",value);
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->rear+1)%MAX_SIZE;
    q->items[q->rear]=value;
    printf("Enqueue %d to queue\n",value);
}

//删除队列中的元素
int dequeue(Circularqueue *q){
    if(isEmpty(q)){
        printf("Queue is empty.Cannot dequeue\n");
        return -1;
    }
    int value=q->items[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        q->front=(q->front+1)%MAX_SIZE;
    }
    printf("Dequeue %d from queue\n",value);
    return value;
}

//打印队列
void printQueue(Circularqueue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i=q->front;
    while(i!=q->rear){
        printf("%d\n",q->items[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("%d\n",q->items[q->rear]);
}

int main(){
    Circularqueue q;
    initQueue(&q);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);

    enqueue(&q,60);
    enqueue(&q,70);

    printQueue(&q);
    return 0;
}