#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：
算法思想：
*/
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
}