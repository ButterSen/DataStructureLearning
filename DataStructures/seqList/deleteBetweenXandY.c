#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：删除关键值为s和t之间的所有元素
算法思想：与删除单个元素相同，进行计数并前移
*/
bool DeleteBetweenXandY(seqList*,int,int);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,50,100,0,10);
    PrintList(seq);
    DeleteBetweenXandY(seq,0,5);
    PrintList(seq);
}
bool DeleteBetweenXandY(seqList* seq,int s,int t){
    if(Empty(seq)){
        printf("顺序表为空");
        return false;
    }else if(s>t){
        printf("s大于t不合法");
        return true;
    }
    int n = 0;
    for(int i = 0;i<seq->length;i++){
        if(seq->data[i]<=t&&seq->data[i]>=s){
            n++;
            continue;
        }
        seq->data[i-n] = seq->data[i];
    }
    seq->length -= n;
    return true;
}
