#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;
bool generateLinkedListWithHeadNode(LNode*,int,int,int,int);
bool generateLinkedListWithNoHead(LNode*,int,int,int,int);
//有头节点链表输出
bool printLinkedList(LNode*);
//无头结点链表输出
bool printLinkedListN(LNode*);
void SortLinkedList(LNode* head);
bool EmptyLinkedList(LNode*);
bool EmptyLinkedListN(LNode*);
bool generateLinkedListWithHeadNode(LNode* head,int minLen,int maxLen,int minNum,int maxNum){
    srand((unsigned)time(0));
    int length = (int)(((double)rand()/(double)RAND_MAX)*(maxLen-minLen)+minLen);
    // head = (LNode*)malloc(sizeof(LNode));
    LNode* p = head;
    p->data = length;
    for(int i = 0;i<length;i++){
        p->next=(LNode*)malloc(sizeof(LNode));
        p->next->data = (int)(((double)rand()/(double)RAND_MAX)*(maxNum-minNum)+minNum);
        p = p->next;
        p->next = NULL;
    }
    return true;
}
bool generateLinkedListWithNoHead(LNode* head,int minLen,int maxLen,int minNum,int maxNum){
    srand((unsigned)time(0));
    int length = (int)((double)rand()/(double)INT_MAX*(double)(maxLen-minLen)+minLen);
    LNode* p = head;
    for(int i = 0;i<length;i++){
        p=(LNode*)malloc(sizeof(LNode));
        p->data = (int)((double)rand()/(double)INT_MAX*(double)(maxNum-minNum)+minNum);
        p=p->next;
        p->next = NULL;
    }
    return true;
}
bool EmptyLinkedList(LNode* head){
    return head->next==NULL;
}
bool EmptyLinkedListN(LNode* head){
    return head == NULL;
}
bool printLinkedList(LNode* head){
    if(EmptyLinkedList(head))return false;
    LNode* p = head->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
bool printLinkedListN(LNode* head){
    if(EmptyLinkedListN(head))return false;
    LNode* p;
    while(p!=NULL){
        printf("%d",p->data);
        p = p->next;
    }
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
