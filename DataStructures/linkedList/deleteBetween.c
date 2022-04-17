#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：给定链表无序，删除给定两数之间的所有元素
算法思想：遇到删除就可以了
*/
bool deleteBetweenST(LNode* head,int s,int t);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    deleteBetweenST(head,0,5);
    printLinkedList(head);
}
bool deleteBetweenST(LNode* head,int s,int t){
    if(EmptyLinkedList(head)||s>t)return false;
    LNode* p = head->next;
    LNode* pre = head;
    while(p!=NULL){
        if(p->data>s&&p->data<t){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
}