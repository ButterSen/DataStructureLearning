#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
/*
题目要求：要求判断链表2是否是链表1的连续子序列
算法思想：由于采用的是链表结构，所以还是采用BF暴力算法
*/
bool BF(LNode*,LNode*);
int main(){
    LNode* head1 = (LNode*)malloc(sizeof(LNode));
    LNode* head2 = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head1,10,20,0,10);
    printLinkedList(head1);
    Sleep(1000);
    generateLinkedListWithHeadNode(head2,2,2,0,10);
    printLinkedList(head2);
    printf("%d",BF(head1,head2));
}
bool BF(LNode* head1,LNode* head2){
    LNode* p = head1->next;
    LNode* q = head2->next;
    LNode* p1 = head1->next;
    while(p!=NULL){
        p1 = p;
        q = head2->next;
        while(q!=NULL&&p1->data == q->data){
            q = q->next;
            if(q==NULL)return true;
            if(p1!=NULL){
                p1 = p1->next;
            }else return false;
        }
        p = p->next;
    }
    return false;
}