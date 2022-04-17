#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：找出两个链表的公共结点
算法思想：可知两者如果有公共结点，则最后一段结点肯定是相同的，
先求出两结点的长度差，再让长的那一个链表先向后走长度差个单位，
然后两个链表同时遍历，直到遇到相同的结点
*/
LNode* FindPublicList(LNode* head1,LNode* head2);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
}
LNode* FindPublicList(LNode* head1,LNode* head2){
    int length1 = 0,length2 = 0;
    LNode* p = head1->next;
    LNode* q = head2->next;
    while(p!=NULL){
        p = p->next;
        length1++;
    }
    while(q!=NULL){
        q = q->next;
        length2++;
    }
    p = head1;q = head2;
    if(length1>length2)for(int i = 0;i<length1-length2;i++)p = p->next;
    else for(int i = 0;i<length1-length2;i++)q = q->next;
    while(p!=NULL||p!=q){
            p=p->next;
            q=q->next;
    }
    return p;
}