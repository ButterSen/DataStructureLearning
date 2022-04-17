#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：从两个递增有序链表中找出公共元素并插入到新链表中
算法思想：采用尾插法进行插入，两个链表进行比较，
小的那一方进行后移操作，直到有一个链表为空
*/
bool FindPublicB2L(LNode* head1,LNode* head2,LNode* head3);
int main(){
    LNode* head1 = (LNode*)malloc(sizeof(LNode));
    LNode* head2 = (LNode*)malloc(sizeof(LNode));
    LNode* head3 = (LNode*)malloc(sizeof(LNode));
    head3->next = NULL;
    generateLinkedListWithHeadNode(head1,10,20,0,10);
    generateLinkedListWithHeadNode(head2,20,30,0,10);
    SortLinkedList(head1);
    SortLinkedList(head2);
    printLinkedList(head1);
    printLinkedList(head2);
    FindPublicB2L(head1,head2,head3);
    printLinkedList(head3);
}
bool FindPublicB2L(LNode* head1,LNode* head2,LNode* head3){
    LNode* p = head1->next;
    LNode* q = head2->next;
    LNode* r = head3;
    while(p!=NULL&&q!=NULL){
        if(p->data==q->data){
            LNode* rs = (LNode*)malloc(sizeof(LNode));
            rs->data = p->data;
            rs->next = NULL;
            r->next = rs;
            r = r->next;
            p = p->next;
            q = q->next;
        }else if(p->data>q->data)q=q->next;
        else p = p->next;
    }
}