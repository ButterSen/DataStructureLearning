#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：递增输出链表中的所有元素并释放存储空间
算法思想：采用选择排序算法
*/
void PrintInOrder(LNode* head);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    PrintInOrder(head);
}
void PrintInOrder(LNode* head){
    LNode* p,*minNode,*preMin;
    while(head->next!=NULL){
        p = head->next;
        preMin = head;
        minNode = p;
        while(p->next!=NULL){
            if(minNode->data>p->next->data){
                minNode = p->next;
                preMin = p;
            }
            p = p->next;
        }
        printf("%d ",minNode->data);
        preMin->next = minNode->next;
        free(minNode);
    }
}