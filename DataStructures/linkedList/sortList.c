#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：设计一个算法使带头结点的链表递增有序
算法思想：使用选择排序对链表进行排序，
使用结点p记录上一次得到的最大结点，初始p为NULL
使用q记录第一个结点,qpre记录q的上一个结点
若q的下一结点不为p，则将q的值与q的下一结点进行比较
若大于则进行互换位置，若小于则q=q->next
直到头结点的下一个结点为p，即p为第一个结点
*/
void SortLinkedList(LNode* head);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    SortLinkedList(head);
    printLinkedList(head);
}
void SortLinkedList(LNode* head){
    LNode* p = NULL;
    LNode* q = head->next;
    LNode* qpre = head;
    while(head->next!=p){
        while(q->next!=p){
            if(q->data>q->next->data){
                qpre->next = q->next;
                q->next = q->next->next;
                qpre->next->next = q;
                qpre = qpre->next;
            }else{
                qpre = q;
                q = q->next;
            }
        }
        p = q;
        q = head->next;
        qpre = head;
    }
}