#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：时间复杂度为n，空间复杂度为1，删除所有关键字值为x的元素
算法思想：使用一个值n记录当前有多少个x，若有x则加一，若不为x则将该元素向前移动n个位置
*/

bool DeleteX(seqList*,int);

int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,50,100,0,10);
    PrintList(seq);
    printf("%d\n",seq->length);
    DeleteX(seq,0);
    PrintList(seq);
    printf("%d",seq->length);
}
bool DeleteX(seqList* seq,int e){
    if(Empty(seq)){
        return false;
    }
    int n = 0;//记录当前e的个数
    for(int i = 0;i<seq->length;i++){
        if(seq->data[i]==e){
            n++;
            continue;
        }
        seq->data[i-n] = seq->data[i];
    }
    seq->length-=n;
}
