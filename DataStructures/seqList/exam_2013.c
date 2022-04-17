#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：寻找主元素，寻找出现次数大于一半的元素，
若存在则输出该元素，若不存在则输出-1
算法思想：
来介绍一种算法复杂度为n的算法：从前向后扫描出可能称为主元素的元素，然后重新进行计数，分析该元素是否为主元素
算法具体分为两步：
1.首先将遇到的数存储在变量a中，进行计数，初值为1；
若下一个数仍为该数，则对计数值加1，不然减一，如果计数值为0，则抛弃将当前数作为记录数
2.对于第一步得到的a再进行一次循环，进行计数，判断该数是否是主元素

算法复杂度为n^2得不偿失：创建大小为n/2的数组，将两个连续且相等的元素的值记录其中，若不存在这样的元素则寻找失败
若存在，再进行一次循环，跟符合条件的元素进行比较，若相等则加1，
最后统计是否有大于出现次数n/2的数，若有则输出该数

*/
int findMainElemStandard(int*,int);
int findMainElem(int*,int);
int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    InitList(seq);
    GenerateRandomList(seq,10,10,0,5);
    //QuickSort(seq);
    PrintList(seq);
    printf("%d",findMainElemStandard(seq->data,seq->length));
}
int findMainElemStandard(int* arr,int n){
    int a = arr[0],count = 0;//存放当前记录数
    for(int i = 1;i<n;i++){
        if(a == arr[i]){
            count++;
        }else count--;
        if(count == 0){
            count = 1;
            a = arr[i];
        }
    }
    count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == a){
            count++;
        }
    }
    if(count<=n/2)return -1;
    else return a;
}
int findMainElem(int* arr,int n){
    int* t = (int*)malloc(sizeof(int)*n/2);
    int* sum = (int*)malloc(sizeof(int)*n/2);
    for(int i = 0;i<n/2;i++)sum[i] = 0;
    int index = 0;
    for(int i = 0;i<n-1;i++){
        if(arr[i] = arr[i+1]){
            t[index++] = arr[i++];
        }
    }
    if(index==0){printf("没有主元素");return -1;}
    for(int i = 0;i<n;i++){
        for(int j = 0;j<index;j++){
            if(t[j] == arr[i]){
                sum[j]++;
            }
        }
    }
    for(int i = 0;i<index;i++){
        if(sum[i]>n/2){
            return t[i];
        }
    }
    return -1;
}