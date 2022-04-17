#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：就地逆置带头结点链表
算法思想：使用头插法进行逆置，
将头结点之后的链表第一个节点摘下插入到链表的头结点之后
使用q来暂存待插入链表的第一个结点
*/
void reverseList(LNode* head);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    reverseList(head);
    printLinkedList(head);
}
void reverseList(LNode* head){
    LNode* q = head->next;
    head->next = NULL;
    while(q!=NULL){
        LNode* p = q;
        q = q->next;
        p->next = head->next;
        head->next = p;
    }
}