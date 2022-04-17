#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：要求将一个数组进行循环左移p个位置
算法思想：将数组进行整体一次翻转，再分别在子区域进行两次翻转
*/
bool Circulate(int*,int,int);
bool Reverse(int*,int,int);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,0,30,0,100);
    //QuickSort(seq);
    PrintList(seq);
    Circulate(seq->data,seq->length,3);
    PrintList(seq);
}
bool Circulate(int* arr,int n,int p){
    Reverse(arr,0,n-1);
    Reverse(arr,0,n-p-1);
    Reverse(arr,n-p,n-1);
}
bool Reverse(int* arr,int left,int right){
    if(left>=right)return true;
    int temp = 0;
    for(int i = 0;i<(right-left)/2;i++){
        temp = arr[left+i];
        arr[left+i] = arr[right-i];
        arr[right-i] = temp;
    }
    return true;
}
