#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：从有序表中删除s和t值之间的元素
算法思想：选择找到第一个值为s的下标和最后一个值为t的下标，计算差n，并将t后面的元素进行前移n位
*/
int DeleteBetweenXandYinOrder(seqList*,int,int);
int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    for(int i = 0;i<10;i++){
        ListInsert(seq,i+1,i);
    }
    PrintList(seq);
    DeleteBetweenXandYinOrder(seq,0,5);
    PrintList(seq);
}
int DeleteBetweenXandYinOrder(seqList* seq,int s,int t){
    if(Empty(seq)){printf("顺序表为空");return 0;}
    if(s>t){printf("输入s与t不合法");return 0;}
    bool flag = true;
    int a = 0,b = seq->length-1;
    for(int i = 0;i<seq->length;i++){
        if(flag==true&&seq->data[i] == s){
            a = i;
            flag = false;
        }
        if(seq->data[i] == t){
            b = i;
        }
    }
    for(int i = a;i<seq->length-b;i++){
        seq->data[i] = seq->data[i+b-a+1];
    }
    seq->length -= b - a + 1;
    return true;
}
