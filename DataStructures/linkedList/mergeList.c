#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：合并两个有序的单链表
算法思想：采用尾插
*/
int main(){
    LNode* head1 = (LNode*)malloc(sizeof(LNode));
    LNode* head2 = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head1,10,20,0,10);
    generateLinkedListWithNoHead(head2,10,20,0,10);
    printLinkedList(head1);
    printLinkedList(head2);
}