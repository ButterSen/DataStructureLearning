#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：设计一个高效算法，将seq中所有元素逆置,要求算法的空间复杂度为O(1)
算法思想：将首尾成对交换
*/
bool ReverseSeqList(seqList*);
int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GGenerateRandomList(seq,50,100,0,100);
    PrintList(seq);
    ReverseSeqList(seq);
    PrintList(seq);
}
bool ReverseSeqList(seqList* seq){
    if(Empty(seq)){
        return false;
    }
    int temp = 0;
    for(int i = 0;i<seq->length/2;i++){
        temp = seq->data[i];
        seq->data[i] = seq->data[seq->length-i-1];
        seq->data[seq->length-i-1] = temp;
    }
    return true;
}