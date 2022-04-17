#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：
算法思想：初始计算三元组的距离，记为min并记录三元组情况，每次增加三元组中最小的元素，
若小于min则更新最小值并重新记录三元组情况
*/
bool findMinTrible(int*,int,int*,int,int*,int,int*);


int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,50,100,0,100);
    //QuickSort(seq);
    PrintList(seq);
    PrintList(seq);
}

bool findMinTrible(int* s1,int n1,int* s2,int n2,int* s3,int n3,int* res){
    int i = 0,j = 0,k = 0;
    while(s1[i]<=0)i++;
    while(s2[j]<=0)j++;
    while(s3[k]<=0)k++;
    int min = abs(s1[i]-s2[j])+abs(s1[i]-s3[k])+abs(s2[j]-s3[k]);
    res[0] = s1[i];res[1] = s2[j];res[2] = s3[k];
    while(i<n1||j<n2||k<n3){
        if(i<n1&&s1[i]<=s2[j]&&s1[i]<=s3[k]){i++;}
        if(j<n2&&s2[j]<=s3[k]&&s2[j]<=s1[i]){j++;}
        if(k<n3&&s3[k]<=s1[i]&&s3[k]<=s2[j]){k++;}
        if(min > abs(s1[i]-s2[j])+abs(s1[i]-s3[k])+abs(s2[j]-s3[k])){
            min = abs(s1[i]-s2[j])+abs(s1[i]-s3[k])+abs(s2[j]-s3[k]);
            res[0] = s1[i];res[1] = s2[j];res[2] = s3[k];
        }
    }
}
