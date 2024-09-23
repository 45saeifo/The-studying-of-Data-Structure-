/*
    time:2024/9/23
    my_email:3078295834@qq.com
    some details:
    In string structure,we can use static way to build this string.But it leads us can not change the size of our string.
    It is a good thing that string do not need us to use Linklist beacuse string's basic operation is a all-way.

*/
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

//定义静态串
typedef struct{
    char ch[MAX_SIZE];
    int len;
}String;

//初始化字符串
void initString(String *S,const char *str){
    strncpy(S->ch,str,MAX_SIZE); //将转入的字符串拷贝到S->ch
    S->ch[MAX_SIZE-1]='\0';
    S->len=strlen(S->ch);
}

//获取字串
int Substring(String *sub,String S,int pos,int len){
    if(pos<0||pos>=S.len||pos+len>S.len||len<0){
        printf("Error!!\n");
        return -1;
    }
    strncpy(sub->ch,S.ch+pos,len);
    sub->ch[len]='\0';
    sub->len=len;
    return 1;
}

//字符串比较
int Compare(String S1,String S2){
    return strcmp(S1.ch,S2.ch);
}

//字符串拼接
int Contact(String S1,String S2,String *result){
    if(S1.len+S2.len>MAX_SIZE){
        printf("Out of Size.Cannot contact them\n");
        return -1;
    }
    strcpy(result->ch,S1.ch);
    strcat(result->ch,S2.ch);
    result->len=S1.len+S2.len;
    return 1;
}

//查找子串(我们详细的在BF.c与KMP.c中有讲解)

//打印字符串
void printString(String S){
    printf("%s\n",S.ch);
}

int main(){
    String S1,S2,S3;
    initString(&S1,"Hello,how are you!");
    initString(&S2,"I am the King of the world!");
    if(Contact(S1,S2,&S3)){
        printf("The result is:\n");
        printString(S3);
    }else{
        printf("Out of the Size!!\n");
    }


    Substring(&S3,S1,2,5);
    printString(S3);


    return 0;
}