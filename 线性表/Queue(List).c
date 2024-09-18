#include<stdio.h>
#include<stdlib.h>

//定义节点结构体
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//定义队列
typedef struct{
    Node *front;
    Node *rear;
}ListQueue;

//初始化队列
void initQueue(ListQueue *q){
    q->front=NULL;
    q->rear=NULL;
}

//检查队列是否为空
int isEmpty(ListQueue *q){
    return (q->front==NULL);
}

//插入队列
void enqueue(ListQueue *q,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memony aflocation failed!\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    if(isEmpty(q)){
        q->front=newNode;
    }else{
        q->rear->next=newNode;
    }
    q->rear=newNode;
    printf("Enqueue %d to queue\n",value);
}

//出队
int dequeue(ListQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty.Cannot dequeue\n");
        return -1;
    }
    Node *temp=q->front;
    int value=temp->data;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    printf("Dequeue %d from queue\n",value);
    return value;
}

//打印队列
void printqueue(ListQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    Node *current=q->front;
    printf("Queue elements:");
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

int main(){
    ListQueue q;
    initQueue(&q);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    printqueue(&q);

    dequeue(&q);
    dequeue(&q);

    printqueue(&q);

    enqueue(&q,40);
    enqueue(&q,50);
    
    printqueue(&q);
    return 0;
}