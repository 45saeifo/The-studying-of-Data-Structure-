#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
typedef int STDataTYpe;
typedef struct Stack{
    STDataTYpe *_a;
    int _top;
    int _capacity;
}stack;

//初始化栈
void stackInit(stack *pst){
    assert(pst);
    pst->_a=(STDataTYpe*)malloc(sizeof(STDataTYpe)*4);//动态分配栈的初始容量为4的数组
    pst->_top=0;
    pst->_capacity=4;
}

//销毁栈
void stackDestroy(stack *pst){
    assert(pst);
    free(pst->_a);
    pst->_a=NULL;
    pst->_top=pst->_capacity=0;
}

//入栈函数
void stackPush(stack *pst,STDataTYpe x){
    assert(pst);
    if(pst->_top==pst->_capacity){
        pst->_capacity*=2;
        STDataTYpe *tmp=(STDataTYpe*)realloc(pst->_a,sizeof(STDataTYpe)*(pst->_capacity));
        if(tmp==NULL){
            printf("realloc fail\n");
            exit(-1);
        }
        pst->_a=tmp;
    }
    pst->_a[pst->_top]=x;
    pst->_top++;
}

//出栈函数
void stackPop(stack *pst){
    assert(pst);
    assert(pst->_top>0);
    pst->_top--;
}

//获取栈的大小
int stackSize(stack *pst){
    assert(pst);
    return pst->_top;
}

//判断栈是否为空
int stackEmpty(stack *pst){
    assert(pst);
    return pst->_top==0?1:0;
}

//获取栈顶函数
STDataTYpe stackTop(stack *pst){
    assert(pst);
    assert(pst->_top>0);//确保栈为非空
    return pst->_a[pst->_top-1];
}
int main(){
    stack *My_Stack;
    stackInit(My_Stack);
    for(int i=0;i<7;i++){
        STDataTYpe number;
        stackPush(My_Stack,number);
        printf("The element is %d",number);
        printf("\n");
        scanf("%d",&number);
    }
    printf("%d",stackTop(My_Stack));
    for(int i=0;i<7;i++){
        stackPop(My_Stack);
    }
    stackDestroy(My_Stack);
    return 0;
}