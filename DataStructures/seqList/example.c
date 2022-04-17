#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：
算法思想：
*/

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,50,100,0,100);
    //QuickSort(seq);
    PrintList(seq);
    PrintList(seq);
}
