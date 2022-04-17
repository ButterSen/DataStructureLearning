#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：要求将两个有序表合成一个有序表，假设都是从小到大的有序表
算法思想：我的思想：创建一个新表,两原表比较，在这个新表上进行插入操作直到所有表结束
*/

int MergeOrderList(seqList*,seqList*,seqList*); 

int main(){
    seqList* seq1 = (seqList*)malloc(sizeof(seqList));
    seqList* seq2 = (seqList*)malloc(sizeof(seqList));
    seqList* seq3 = (seqList*)malloc(sizeof(seqList));
    InitList(seq1);
    InitList(seq2);
    InitList(seq3);
    GenerateRandomList(seq1,0,50,0,100);
    GenerateRandomList(seq2,0,50,10,30);
    QuickSort(seq1);
    QuickSort(seq2);
    PrintList(seq1);
    PrintList(seq2);
    MergeOrderList(seq3,seq1,seq2);
    PrintList(seq3);
}

int MergeOrderList(seqList* seq3,seqList* seq2,seqList* seq1){
    if(seq1->length+seq2->length>maxSize)return false;
    int i = 0,j = 0,k = 1;
    while(i<seq1->length&&j<seq2->length){
        if(seq1->data[i]>seq2->data[j]){
            ListInsert(seq3,k++,seq2->data[j++]);
        }else{
            ListInsert(seq3,k++,seq1->data[i++]);
        }
    }
    if(i<seq1->length){
        for(int t = k;i<seq1->length;){
            ListInsert(seq3,k++,seq1->data[i++]);
        }
    }
    if(j<seq2->length){
        for(int t = k;j<seq2->length;){
            ListInsert(seq3,k++,seq2->data[j++]);
        }
    }
    return true;
}
