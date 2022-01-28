#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "stack.h"
#include "queue.h"
/*
  本代码段设计用来实现各类排序算法
  使用数据结构来减少输入参数等
*/
#define maxSize 100 //the max length of seqlist
typedef struct{
    double data[maxSize];
    int length;
}sqlist;
/***********线性表基本函数**************/
void initSqlist(sqlist* sl);
int createListByArray(sqlist* sl,double array[],int n);
void slPrint(sqlist* sl);
int isOrderly(sqlist* sl);

/************随机数组生成***************/
double* generateRandomArray(int len,int min,int max);


/************线性表各类排序算法**********/
//直接插入排序
int directInsertSort(sqlist *sl);
//折半插入排序
int binInsertSort(sqlist* sl);
//希尔排序
int shellSort(sqlist* sl);
//简单选择排序
int simpleChooseSort(sqlist* sl);
//堆选择排序
int heapChooseSort(sqlist* sl);
//堆的筛选算法，筛选算法运行的前提条件，左右子树已经是大顶堆
int sift(double* num,int low,int high);
//冒泡排序
int bubbleSort(sqlist* sl);//沉入水底
int bubbleSort2(sqlist* sl);//浮出水面
//快速排序
int quickSort(sqlist* sl);
int quicksort(sqlist* sl,int s,int t);
int partition(double* data,int s,int t);
//二路归并排序
int mergeSort(sqlist* sl);
int mergePass(double*,int,int);
int merge(double*,int,int,int);
//三路归并排序
int mergeSort3(sqlist* sl);
int merge3(double*,int,int,int,int);
//基数排序算法
int radixSort(sqlist*);

/*************算法设计题目***************/
/*1.简单选择排序的变种：
题目条件：递增排序，从无序区中挑选最大的元素放入有序区
*/
int simpleChooseSort2(sqlist* sl);
/*2.与简单选择排序类似的算法：计数排序(改进了不能处理数组中存在相同数的情况)
算法描述：将所要排数组的排序结果存储在另一张表中，
对于所要排的关键字，找出数组中比该关键字小的个数c，
则c就为另一张表中该关键字的下标

简单算法进行了n^2次比较，而简单排序算法进行了1+2+3+4+5+...+n次比较
相对而言简单排序算法更加好

*/
int countSort(sqlist* sl);
/*3.基于小根堆的堆排序算法
*/
int heapChooseSort2(sqlist* sl);
int siftMin(double* num,int low,int high);
/*4.快速排序可以输出前m个元素(1<=m<n)，前m个元素可以顺序不同
*/



int main(){
    sqlist *sl = (sqlist*)malloc(sizeof(sqlist));
    initSqlist(sl);
    srand((unsigned)time(0));
    unsigned int isRight = 1;
    //double array[] = {9,32,4,31,44,10,9,5,4,6,1,89,11,4,62,64};
    slPrint(sl);
    for(int i = 0;i<100;i++){
        double* ans = generateRandomArray(16,0,100); 
        createListByArray(sl,ans,16);
        //directInsertSort(sl);
        //shellSort(sl);
        //simpleChooseSort(sl);
        //heapChooseSort(sl);
        //simpleChooseSort2(sl);
        //countSort(sl);//计数算法有巨大的缺陷在于无法处理关键值相同情况
        //heapChooseSort2(sl);
        //bubbleSort(sl);
        //quickSort(sl);
        //mergeSort3(sl);
        radixSort(sl);
        //slPrint(sl);
        if(!isOrderly(sl)){
            slPrint(sl);
            isRight = 0;
        }
    }
    if(isRight){
        printf("Correct Sort");
        }
        else{printf("Wrong Sort");}
    return 0;
}
void initSqlist(sqlist* sl){
    sl->length = 0;
}
int createListByArray(sqlist* sl,double array[],int n){
    for(int i = 0;i<n;i++){
        sl->data[i] = array[i];
    }
    sl->length = n;//C语言在函数调用参数里面无法直接获得数组的长度
    return 0;
}
void slPrint(sqlist* sl){
    for(int i = 0;i<sl->length;i++){
        printf("%lf ",sl->data[i]);
    }
    printf("\n");
}

int isOrderly(sqlist* sl){
    for(int i = 1;i<sl->length;i++){
        if(sl->data[i-1]>sl->data[i]){
            return 0;
        }
    }
    return 1;
}

double* generateRandomArray(int len,int min,int max){
    double* ans = (double*)malloc(sizeof(double)*len);
    for(int i =0;i<len;i++){
        ans[i] =(int)((((double)rand())/(double)RAND_MAX)*(max-min)+min);
    }
    return ans;
}
int directInsertSort(sqlist*sl){
    double tmp;
    for(int i = 1;i<sl->length;i++){
        if(sl->data[i]<sl->data[i-1]){    //反序 这里优化了代码方法，首先通过判断插入元素与有序组最大的元素相比较
           tmp = sl->data[i];             //如果大于，则不用再插入，前i位数组直接为有序组，反之，需要插入，按照比大小的方式进行排序
           int j = i-1;                   //j指向有序组最后的元素
           while(tmp<sl->data[j]&&j>=0){  //不能忽略j>=0，防止数组越界
               sl->data[j+1] = sl->data[j];
               j--;
           }
           sl->data[j+1] = tmp;
        }
    }
}
int binInsertSort(sqlist* sl){
    for(int i = 1;i<sl->length;i++){
        if(sl->data[i-1]>sl->data[i]){//反序
            double tmp = sl->data[i];
            int low=0,high=i-1,mid=(low+high)/2;
            while(low<=high){
                mid = (low+high)/2;
                if(tmp<sl->data[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            for(int j = i;j>high+1;j--){
                sl->data[j] = sl->data[j-1];
            }
            sl->data[high+1] = tmp;
        }
        slPrint(sl);
    }
}
int shellSort(sqlist* sl){
    //元素按下标一定增量进行分组，再对每个分组元素采用直接插入排序进行排序
    //首先要想如何进行分组
    int d = sl->length/2;
    while(d>0){
        for(int i = d;i<sl->length;i++){//d为循环过后有序组个数,i为当前循环组号
            int tmp = sl->data[i],j = i;
            while(j>=d&&sl->data[j-d]>tmp){//反序
                sl->data[j] = sl->data[j-d];
                j-=d;
            }
            sl->data[j] = tmp;
        }
        d=d/2;
        slPrint(sl);
    }
}
int simpleChooseSort(sqlist* sl){
    for(int i = 0;i<sl->length-1;i++){
        int min = sl->data[i];
        int index = i;//注意下标初始值
        for(int j = i+1;j<sl->length;j++){
            if(sl->data[j]<min){
                min = sl->data[j];
                index = j;
            }
        }
        sl->data[index] = sl->data[i];
        sl->data[i] = min;
    }
}
int heapChooseSort(sqlist* sl){
    for(int i = (sl->length-1)/2;i>=0;i--){
        sift(sl->data,i,sl->length-1);//先将整个序列变换成大顶堆
    }
    //slPrint(sl);
    for(int j = sl->length-1;j>0;j--){
        double tmp = sl->data[0];
        sl->data[0] = sl->data[j];
        sl->data[j] = tmp;
        //以上的目的在于要把大顶堆的根节点与第j个元素进行替换
        //而下面的意义在于将大顶堆前j-1个元素重新进行建堆
        sift(sl->data,0,j-1);
    }
}
int sift(double* array,int low,int high){
    //在顺序表中，假设树从0开始编号，若双亲结点的序号为i,
    //其左孩子结点的序号为2*i+1,右孩子结点的序号为2*i+2
    int i = low;
    int j = 2*i+1;
    double tmp = array[i];
    while(j<=high){
        if(j<high&&array[2*i+1]<array[2*i+2]){//注意添加j<high条件不然可能会导致数组越界
            j = 2*i+2;//选出子节点值最大的子节点
        }
        if(array[j]>tmp){
            array[i] = array[j];
            i = j;//i在这里表示的是当前父节点,j表示的是当前子节点
            j = 2*i+1;//一定要更新i和j的值，更新j给while循环判断
                      //当时忘了，还是编程能力不强
        }else{
            break;
        }
    }
    array[i] = tmp;
}

int bubbleSort(sqlist* sl){
    for(int i = 0;i<sl->length-1;i++){
        for(int j = 0;j<sl->length-i-1;j++){
            if(sl->data[j]>sl->data[j+1]){
                double tmp = sl->data[j];
                sl->data[j] = sl->data[j+1];
                sl->data[j+1] = tmp;
            }
        }
    }
}

int bubbleSort2(sqlist* sl){
    for(int i = 0;i<sl->length-1;i++){
        for(int j = sl->length-1;j>i;j--){
            if(sl->data[j]<sl->data[j-1]){
                double tmp = sl->data[j];
                sl->data[j] = sl->data[j-1];
                sl->data[j-1] = tmp;
            }
        }
    }
}

int quickSort(sqlist* sl){
    //quicksort(sl,0,sl->length-1);
    stack* st = (stack*)malloc(sizeof(stack));
    initStack(st);
    double start[2];
    start[0] = 0;start[1] = sl->length-1;
    push(st,start);
    while(!stackEmpty(st)){
        double* bround = pop(st);
        double bentch = partition(sl->data,bround[0],bround[1]);
        if(bentch>bround[0]+1){
            double* bround1 = (double*)malloc(sizeof(double)*2);
            bround1[0] = bround[0];
            bround1[1] = bentch - 1;
            push(st,bround1);
        }
        if(bentch<bround[1]-1){
            double* bround2 = (double*)malloc(sizeof(double)*2);
            bround2[0] = bentch+1;
            bround2[1] = bround[1];
            push(st,bround2); 
        }
    }
}

int quicksort(sqlist* sl,int s,int t){
    if(s<t){
    int bench = partition(sl->data,s,t);
    quicksort(sl,s,bench-1);
    quicksort(sl,bench+1,t);
    }
}
int partition(double* data,int s,int t){
    int i =s,j=t;
    double tmp = data[s];
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

int mergeSort(sqlist* sl){
    for(int i = 1;i<sl->length;i=i*2){
        mergePass(sl->data,i,sl->length);
    }
}
int mergePass(double* data,int length,int n){
    int i = 0;
    for(i = 0;i+2*length-1<n;i=i+2*length){
        merge(data,i,i+length-1,i+2*length-1);
    }
    //解决子表个数为奇数问题
    if(i+length-1<n){
        merge(data,i,i+length-1,n-1);
    }
}
//输入参数:两个需要合并的数组以及两个数组长度
int merge(double* data,int low,int mid,int high){
    double* newData = (double*)malloc(sizeof(double)*(high-low+1));
    int i=low,j=mid+1,index = 0;
    while(i<=mid&&j<=high){
        //data_1[i]小则放入新数组中
        if(data[i]<=data[j]){
            newData[index++] = data[i++];
        }else{
            newData[index++] = data[j++];
        }
    }
    while(i<=mid){
        newData[index++] = data[i++];
    }
    while(j<=high){
        newData[index++] = data[j++];
    }
    for(int k = 0,i = low;i<=high;i++,k++){
        data[i] = newData[k];
    }
}

int mergeSort3(sqlist* sl){
    int len = 1,i=0;
    for(len = 1;len<=sl->length;len=len*3){
    for(i = 0;i+3*len-1<sl->length;i=i+3*len){
        merge3(sl->data,i,i+len-1,i+2*len-1,i+3*len-1);
    }
    if(i+2*len-1<sl->length){
        merge3(sl->data,i,i+len-1,i+2*len-1,sl->length-1);
    }else if(i+len-1<sl->length){
        merge3(sl->data,i,i+len-1,sl->length-1,sl->length-1);
    }
    }

}

int merge3(double* data,int a,int b,int c,int d){
    double* newData = (double*)malloc(sizeof(double)*(d-a+1));
    int i = a,j = b + 1,k = c + 1,l = d,index = 0;
    while(1){
        int m;
        double min = __DBL_MAX__;
        if(i<=b){min = data[i];m=0;}
        if(j<=c&&data[j]<min){min = data[j];m=1;}
        if(k<=d&&data[k]<min){min = data[k];m=2;}
        // min = i<=b?(data[i],m=0):__DBL_MAX__;
        // min = j<=c?(data[j]<min?(data[j],m=1):min):min;
        // min = k<=d?(data[k]<min?(data[k],m=2):min):min;
        if(min == __DBL_MAX__){break;}
        switch(m){
            case 0:i++;break;
            case 1:j++;break;
            case 2:k++;break;
        }
        newData[index++] = min;
    }
    for(int n = a;n<=d;n++){
        data[n] = newData[n-a];
    }
}

int radixSort(sqlist* sl){
    //线性表中最多的元素，基数的最大取值，关键字位数的最大取值
    queue* q[MAXR];
    for(int i = 0;i<MAXR;i++){
        q[i] = (queue*)malloc(sizeof(queue));
        initQueue(q[i]);
    }
    for(int i = 0;i<MAXD;i++){
        //收集过程
        for(int j = 0;j<sl->length;j++){
            //计算出应该加入哪个队列当中
            int index=(int)(sl->data[j]/(int)pow(10,i))%(int)pow(10,i+1);
            inQueue(q[index],sl->data[j]);
        }
        int num = 0;
        //分配过程
        for(int j = 0;j<MAXR;j++){
            while(!queueEmpty(q[j])){
                sl->data[num++] = outQueue(q[j]);
            }
        }
    }
}

int simpleChooseSort2(sqlist* sl){
    //与前面设计的简单排序唯一的区别是从无序区中选出的是最大的元素
    for(int i = sl->length-1;i>0;i--){//对于R[0,i]的无序区循环
        double max = sl->data[i];
        int index = i;
        for(int j = 0;j<=i;j++){
            if(sl->data[j]>max){
                max = sl->data[j];
                index = j;
            }
        }
        sl->data[index] = sl->data[i];
        sl->data[i] =  max;
    }
}

int countSort(sqlist* sl){
    double newData[sl->length];
    for(int i =0;i<sl->length;i++){//对于表中第i个元素
        int count = 0,sameCount = 0;
        for(int j = 0;j<sl->length;j++){
            if(sl->data[i]>sl->data[j]){
                count++;
            }else if(sl->data[i] = sl->data[j]){
                sameCount++;
            }
        }
        for(int j = 0;j<sameCount;j++)
        newData[count+j] = sl->data[i];
    }
    for(int i = 0;i<sl->length;i++){
        sl->data[i] = newData[i];
    }
}

int heapChooseSort2(sqlist* sl){
    //初始建堆
    for(int i = (sl->length-1)/2;i>=0;i--){
        siftMin(sl->data,i,sl->length-1);
    }
    double newData[sl->length];
    for(int i = sl->length-1;i>0;i--){
        newData[sl->length-1-i] = sl->data[0];
        sl->data[0] = sl->data[i];
        sl->data[i] = newData[sl->length-i-1];
        siftMin(sl->data,0,i-1);
    }
    newData[sl->length-1] = sl->data[0]; 
    for(int i = 0;i<sl->length;i++){
        sl->data[i] = newData[i];
    }
}
int siftMin(double* data,int low,int high){
    int i = low;
    int j = 2*i+1;//i是父节点，j是子节点
    double tmp = data[i];
    while(j<=high){
        if(j<high&&data[j]>data[j+1]){
            j++;//取最小
        }
        if(data[j]<tmp){
            data[i] = data[j];
            i = j;
            j = 2*i+1;
        }else{
            break;
        }
    }
    data[i] = tmp;
}