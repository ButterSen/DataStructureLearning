#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：删除带头结点的链表中的最小值
算法思想：初始化min为int型的最大值
保留上一结点p和当前结点q，初始时p为头结点，q = p->next
使用minP记录最小结点的上一结点,初始时minP = p;
若q不为空，则将q值和min作比较，若q值大于min值，q=q->next;
若q值小于min值，minP = p,q=q->next
循环结束后，释放minP->next = minP->next->next；
*/
void deleteMin(LNode* head);
int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    deleteMin(head);
    printLinkedList(head);
}
void deleteMin(LNode* head){
    int min = INT_MAX;
    LNode* p = head;
    LNode* q = p->next;
    LNode* minP = p;
    while(q!=NULL){
        if(q->data>min)q=q->next;
        else{
            minP = p;q=q->next;
        }
    }
    minP->next = minP->next->next;
}