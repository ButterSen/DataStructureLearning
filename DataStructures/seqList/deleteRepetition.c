#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：从有序顺序表删除线性表中重复的元素
算法思想：记录所有重复的数量进行前移，记录重复方法，记录最后一次循环到的值
*/

bool DeleteRepetition(seqList* seq);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,5,50,0,10);
    QuickSort(seq);
    PrintList(seq);
    DeleteRepetition(seq);
    PrintList(seq);
}
bool DeleteRepetition(seqList* seq){
    if(Empty(seq)){return false;}
    int temp = seq->data[0],n=0;
    for(int i = 1;i<seq->length;i++){
        if(seq->data[i] == temp){
            n++;
            continue;
        }
        temp = seq->data[i];
        seq->data[i-n] = seq->data[i];
    }
    seq->length -= n;
    return true;
}
