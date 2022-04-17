#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#define maxSize 1000
typedef struct seqList{
    int data[maxSize];
    int length;
}seqList;
//初始化表。构造一个空的线性表
bool InitList(seqList*);
//返回表长
int Length(seqList*);
//按值查找操作，在表中查找具有指定关键字值的元素
int LocateElem(seqList*,int);
//按位查找操作。获取表中第i个位置的元素的值
int GetElem(seqList*,int);
//插入操作，在表中第i个位置上插入指定元素
bool ListInsert(seqList*,int,int);
//删除操作，删除表中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(seqList*,int,int*);
//输出操作，按照前后顺序输出线性表L的所有值
void PrintList(seqList*);
//判空操作，若表为空，则返回真
bool Empty(seqList*);
//销毁操作，销毁线性表，并删除线性表所占用的空间
void DestroyList(seqList*);

//生成一个随机顺序表
bool GenerateRandomList(seqList*,int,int,int,int);
//快排
bool QuickSort(seqList*);
void Quicksort(seqList*,int,int);
int partition(int*,int,int);
// int main(){
//     seqList* seq;
//     seq = (seqList*)malloc(sizeof(seqList));
//     InitList(seq);
//     GenerateRandomList(seq);
    
// }

bool InitList(seqList* seq){
    seq->length=0;
    return true;
}
int Length(seqList* seq){
    return seq->length;
}
int LocateElem(seqList* seq,int e){
    //简单的线性查找
    for(int i = 0;i<seq->length;i++){
        if(seq->data[i]==e){
            return i+1;
        }
    }
    printf("查找失败");
    return 0;
}
int GetElem(seqList* seq,int i){
    if(i<1||i>seq->length){printf("下标越界");return 0;}
    return seq->data[i+1];
}
bool ListInsert(seqList* seq,int i,int e){
    if(i<1||i>seq->length+1){
        return false;
    }
    for(int j = seq->length-1;j>=i-1;j--){
        seq->data[j+1] = seq->data[j];
    }
    seq->data[i-1] = e;
    seq->length++;
    return true;
}
bool ListDelete(seqList* seq,int i,int* e){
    if(i<1||i>seq->length){
        return false;
    }
    *e = seq->data[i-1];
    for(int j = i;j<seq->length;j--){
        seq->data[j-1] = seq->data[j]; 
    }
    seq->length--;
    return true;
}
void PrintList(seqList* seq){
    for(int i = 0;i<seq->length;i++){
        printf("%d ",seq->data[i]);
    }
    printf("\n");
}
bool Empty(seqList* seq){
    return seq->length == 0;
}
void DestroyList(seqList* seq){
    free(seq);
}
bool GenerateRandomList(seqList* seq,int minLen,int maxLen,int minNum,int maxNum){
    srand((unsigned)time(0));
    int length = (int)(((double)rand()/(double)RAND_MAX)*(maxLen-minLen)+minLen);
    for(int i = 0;i<length;i++){
        ListInsert(seq,i+1,(int)((double)rand()/(double)RAND_MAX*(maxNum-minNum)+minNum));
    }
    return true;
}
bool QuickSort(seqList* seq){
    Quicksort(seq,0,seq->length-1);
}
void Quicksort(seqList* sl,int s,int t){
    if(s<t){
    int bench = partition(sl->data,s,t);
    Quicksort(sl,s,bench-1);
    Quicksort(sl,bench+1,t);
    }
}
int partition(int* data,int s,int t){
    int i =s,j=t;
    int tmp = data[s];
    while(i!=j){
        //添加j>i这一条件非常关键，代表了能够进行扫描的范围
        while(j>i&&data[j]>=tmp){
            j--;
        }
        data[i] = data[j];
        while(i<j&&data[i]<=tmp){
            i++;
        }
        data[j] = data[i];
    }
    data[i] = tmp;
    return i;
}