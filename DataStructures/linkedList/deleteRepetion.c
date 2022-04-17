#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：删除有序链表中的重复元素
算法思想：记录两个指针，先前指针与当前指针，两个即用于比较又用于删除
*/
bool DeleteRepetion(LNode* head);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,30,40,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    SortLinkedList(head);
    printLinkedList(head);
    DeleteRepetion(head);
    printLinkedList(head);
}
bool DeleteRepetion(LNode* head){
    LNode* pre = head;
    LNode* p = head->next;
    if(p!=NULL){pre=pre->next;p=p->next;}
    while(p!=NULL){
        if(pre->data == p->data){
            pre->next = p->next;
            p = pre->next;
        }else{
            pre = pre->next;
            p = p->next;
        }
    }
}