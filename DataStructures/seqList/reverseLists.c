#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：将一维数组中存放两个线性表a1,a2,..,an和b1,b2,...,bm位置互换为b1,b2,...,bm和a1,a2,...,an
算法思想：先将数组整体翻转，然后在分别在线性表a和线性表b中翻转
*/
bool ReverseList(seqList*,int);
//翻转线性表下标从a到b的部分
bool Reverse(seqList*,int a,int b);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,10,11,0,100);
    QuickSort(seq);
    PrintList(seq);
    ReverseList(seq,5);
    PrintList(seq);
}

bool ReverseList(seqList* seq,int n){
    if(Empty(seq)||n>seq->length)return false;
    Reverse(seq,0,seq->length-1);
    Reverse(seq,0,seq->length-n-2);
    Reverse(seq,seq->length-n-1,seq->length-1);
    return true;
}

bool Reverse(seqList* seq,int a,int b){
    if(a>=b||Empty(seq))return false;
    int temp = 0;
    for(int i = a;i<(b-a)/2+a;i++){
        temp = seq->data[i];
        seq->data[i] = seq->data[b-i+a];
        seq->data[b+a-i] = temp;
    }
    return true;
}
