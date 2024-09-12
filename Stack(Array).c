#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10//define a max size.

typedef struct{
    int items[MAX_SIZE];
    int top;
}Stack;

//building a Stack.
Stack* createStack(){
    Stack* S=(Stack*)malloc(sizeof(Stack));
    S->top=-1;
    return S;
}

//judge if is a full Stack.
bool isFull(Stack *S){
    return S->top==MAX_SIZE-1;
}

//judge if is a empty Stack.
bool isEmpty(Stack *S){
    return S->top==-1;
}

//push a element into Stack.
void push(Stack *S,int element){
    if(isFull(S)){
        printf("The Stack is full.Cannot push %d into it\n",element);
        return;
    }
    S->items[++S->top]=element;
    printf("%d push to Stack.",element);
}

//pop a element out Stack.
int pop(Stack *S){
    if(isEmpty(S)){
        printf("The Stack is empty,Cannot pop element\n");
        return -1;
    }
    return S->items[S->top--];
}

//watch the top element inStack
int peek(Stack *S){
    if(isEmpty(S)){
        printf("Cannot watch the top element because the Stack is empty.");
        return -1;
    }
    return S->items[S->top];
}
int main(){
    Stack *My_Stack=createStack();
    
    for(int i=0;i<5;i++){
        int number;
        scanf("%d",&number);
        push(My_Stack,number);
    }
    printf("The top element is %d.\n",peek(My_Stack));
    for(int i=0;i<5;i++){
        printf("%d\n",pop(My_Stack));
    }
    pop(My_Stack);
    return 0;
}
