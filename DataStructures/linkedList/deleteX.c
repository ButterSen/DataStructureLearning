#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：在带头结点的链表中，删除所有值为x的结点，并释放其空间
算法思想：以头指针head为函数参数，p = head
若p的next不等于空，将p->next的data值与x进行比较，若相等，则p->next = p->next->next，continue
若不相等，则p=p->next;
若p的next等于空，则算法结束
*/
bool DeleteX(LNode*,int);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    DeleteX(head,2);
    printLinkedList(head);
}
bool DeleteX(LNode* head,int e){
    LNode* p = head;
    while(p->next!=NULL){
        if(p->next->data==e){
            p->next = p->next->next;
            continue;
        }
        p = p->next;
    }
}