#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：两个序列的中位数定义为两个序列所含全部元素的升序序列的中位数，
中位数定义为序列上L/2上取整处的元素
要求找出两个等长升序序列的中位数
算法思想：先将两个数的中位数作比较，大的那一方从中位数x比较小的那一方的后继元素e
（1）若大于则x不是中位数再从自己的前继元素y比较元素e，若小于等于则该数x就是中位数，算法结束；
（2）若y大于e，则比较e的后继元素按(1)处理，若y小于等于e则e就是中位数，算法结束；
*/
int findMiddleNum(int*,int*,int);


int main(){
    seqList* seq1 = (seqList*)malloc(sizeof(seqList));
    seqList* seq2 = (seqList*)malloc(sizeof(seqList));
    InitList(seq1);
    InitList(seq2);
    GenerateRandomList(seq1,5,5,0,20);
    GenerateRandomList(seq2,5,5,10,20);
    QuickSort(seq1);
    QuickSort(seq2);
    PrintList(seq1);
    PrintList(seq2);
    printf("%d",findMiddleNum(seq1->data,seq2->data,seq1->length));
}
int findMiddleNum(int* arr1,int* arr2,int n){
    int middle = (n-1)/2;
    int* arrMax = arr1[middle]>arr2[middle]?arr1:arr2;
    int* arrMin = arr1[middle]>arr2[middle]?arr2:arr1;
    int i = middle,j = middle+1;
    while(true){
        if(arrMax[i]<=arrMin[j]){
            return arrMax[i];
        }else if(arrMax[i-1]<=arrMin[j]){
            return arrMin[j];
        }else{
            i--;j++;
        }
    }
}