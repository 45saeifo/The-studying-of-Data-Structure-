#include <stdio.h>
#include <stdlib.h>

typedef struct DuLinkList
{
    int data;
    struct DuLinkList *next;
} DuLinkList;


void revelist(DuLinkList *head)//进行逆序
{
    DuLinkList *l,*m;
    l = head->next->next;//L指向了第二个数据
    m = l->next;//再用另外一个指针指向L的下一个数据，防止数据丢失了。
    head->next->next = NULL;//让第一个数据指向NULL，作为了最后那个数据。
    while(m != NULL)
    {
        l->next = head->next;
        head->next = l;
        l = m;
        m = m->next;
    }//由于L指向最后那个数据的时候循环结束，所以后面要再调整一次
    l->next = head->next;
    head->next = l;
}


int main()
{
    DuLinkList *l,*p,*head;
    int i;
    l = (DuLinkList *)malloc(sizeof(DuLinkList));//建立的头结点。
    l->data = -1;
    head = l;//头指针指向头结点。
    for (i = 0; i<10; i++)
    {
        p = (DuLinkList *)malloc(sizeof(DuLinkList));//建立新的结点
        p->data = i;//输入数据。
        l->next = p;
        p->next = NULL;
        l = p;
    }
    revelist(head);
    p = head->next;
    while(p != NULL)//输出结果
    {
        printf("%d ",p->data);
        p = p->next;
    }
    return 0;
}
