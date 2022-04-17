#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：要求在有序表中查找关键值为x的元素，
若找到，将其与后继元素互换位置，若找不到则将其插入表中仍使表有序
算法思想：
*/
bool BinSearch(seqList*,int);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,5,10,0,10);
    QuickSort(seq);
    PrintList(seq);
    BinSearch(seq,5);
    PrintList(seq);
}
bool BinSearch(seqList* seq,int e){
    if(Empty(seq))return false;
    int left = 0,right = seq->length-1,mid = 0;
    while(left<=right){
        mid = (left+right)/2;
        if(seq->data[mid]==e){
            int tmp = seq->data[mid];
            seq->data[mid] = seq->data[mid+1];
            seq->data[mid+1] = tmp;
            return true;
        }
        if(seq->data[mid]>e){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    ListInsert(seq,mid+2,e);
}
