#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"seqList.h"
/*
题目要求：删除最小值元素，并由函数返回；
空出的位置由最后一个元素填补；
若顺序表为空，则显示错误信息并退出

这道题有些小问题，就是如果只有一个元素的话，怎么用最后一个元素填补
不过也可以说得通；
*/
bool DeleteMin(seqList*,int*);
int main(){
    seqList* seq = (seqList*)malloc(sizeof(seqList));
    int e;
    InitList(seq);
    GenerateRandomList(seq,50,100,0,100);
    PrintList(seq);
    DeleteMin(seq,&e);
    PrintList(seq);
    return 0;
}
bool DeleteMin(seqList* seq,int* e){
    if(Empty(seq)){
        printf("顺序表为空\n");
        return false;
    }
    int min = seq->data[0],minIndex = 0;
    for(int i = 1;i<seq->length;i++){
        if(min>seq->data[i]){
            min = seq->data[i];
            minIndex = i;
        }
    }
    *e = min;
    seq->data[minIndex] = seq->data[seq->length-- - 1];
    return true;
}