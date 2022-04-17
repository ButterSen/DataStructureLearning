#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：找出数组中未出现的最小正整数
算法思想：在没有1的情况下，数组中最小的正整数就是1，
再有1的情况下，数组中最小的正整数就是1,2,...,m
易得m是小于等于数组大小n的，故可以创建一个大小等于n+1的数组，
用来记录出现的大于等于0小于等于n的正整数，其中未记录的最小数就是
最小正整数
*/
int findUnshownMinInt(int* arr,int n);
int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,10,10,0,10);
    //QuickSort(seq);
    PrintList(seq);
    printf("%d",findUnshownMinInt(seq->data,seq->length));
}
int findUnshownMinInt(int* arr,int n){
    int* arrMin;
    arrMin = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++)arr[i] = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<1||arr[i]>n){
            arrMin[arr[i]-1] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        if(arrMin[i]==0){
            return i+1;
        }
    }
}
