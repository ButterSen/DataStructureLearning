#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：编写算法，将一个链表拆分成两个链表，要求看题目吧懒得写
算法思想：一个才有头插法，一个采用尾插法
*/
bool DivideList(LNode*,LNode*,LNode*);
int main(){
    LNode* head1 = (LNode*)malloc(sizeof(LNode));
    LNode* head2 = (LNode*)malloc(sizeof(LNode));
    head2->next = NULL;
    LNode* head3 = (LNode*)malloc(sizeof(LNode));
    head3->next = NULL;
    generateLinkedListWithHeadNode(head1,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head1);
    DivideList(head1,head2,head3);
    printLinkedList(head2);
    printLinkedList(head3);
}
bool DivideList(LNode* head1,LNode* head2,LNode* head3){
    LNode* p = head1;
    LNode* q = head2;
    LNode* r = head3;
    int count = 0;
    while(p->next!=NULL){
        LNode* p2 = p->next;
        count++;
        if(count%2!=0){
            q->next = p->next;
            q = q->next;
            p = p->next;
        }else{
            p->next = p->next->next;
            p2->next = r->next;
            r->next = p2;
        }
    }
    q->next = NULL;
}