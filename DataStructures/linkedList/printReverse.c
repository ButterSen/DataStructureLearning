#include"linkedList.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
/*
题目要求：带头节点，从尾向头反向输出
算法思想：利用递归的思想，进行输出，以结点为参数
若结点的下一结点不为空，以下一结点为参数进行递归
然后该结点的下一结点data值
若结点的下一结点为空，返回；
*/
void printReverse(LNode* ln);

int main(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    generateLinkedListWithHeadNode(head,10,20,0,10);
    // generateLinkedListWithNoHead(head,10,20,0,10);
    printLinkedList(head);
    printReverse(head);
}
void printReverse(LNode* ln){
    if(ln->next!=NULL){
        printReverse(ln->next);
        printf("%d ",ln->next->data);
    }
}
