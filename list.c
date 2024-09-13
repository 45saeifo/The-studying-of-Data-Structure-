#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* next;
} Node;
 
// 创建节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error! Unable to create a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// 插入节点
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
 
// 删除节点
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next != NULL && temp->next->data == data) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}
 
// 打印链表
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
 
int main() {
    Node* head = NULL;
 
    // 插入节点
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 12);
 
    // 打印链表
    printf("Original list: ");
    printList(head);
 
    // 删除节点
    deleteNode(&head, 7);
 
    // 打印链表
    printf("List after deleting node 7: ");
    printList(head);
 
    // 清理链表
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
 
    return 0;
}