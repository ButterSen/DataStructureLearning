#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
  本代码段设计用来实现线性表的功能以及相关算法
  本代码顺序表的逻辑下标从1开始，但其他排序之类算法与下标无关
*/
#define maxSize 100 //the max length of seqlist
typedef struct{
    double data[maxSize];
    int length;
}sqlist;
/***********线性表基本函数**************/
void initSqlist(sqlist* sl);
double getElem(sqlist* sl,int i);
int insertElem(sqlist* sl,int i,double in);
int addElem(sqlist* sl,double in);
int deleteElem(sqlist* sl,int i);
int locateElem(sqlist* sl,double elem);
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
        countSort(sl);//计数算法有巨大的缺陷在于无法处理关键值相同情况
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
double getElem(sqlist* sl,int i){
    if(i<1||i>sl->length+1){//注意这块i要大于length+1，主要考虑最后插入的情况
        return __SIZEOF_DOUBLE__;
    }else{
        return (sl->data[i-1]);
    }
}
int insertElem(sqlist* sl,int i,double in){
    if(i<1||i>sl->length+1){
        return -1; //数组越界
    }
    else{
        int t = 0;
        //对数组的后length - i + 1元素进行平移
        while(sl->length-i-t>0){
            sl->data[sl->length-t] = sl->data[sl->length-t-1];
            t++;
        }
        sl->data[i-1] = in;
        sl->length++;
        return 0;
    }
}
int addElem(sqlist *sl,double in){
    return insertElem(sl,sl->length+1,in);
}
int deleteElem(sqlist* sl,int i){
    if(i<1||i>sl->length){//这里不用使i>length+1
        return -1;//数组越界
    }
    else{
        int t = 0;
        while(sl->length-i-t>0){
            sl->data[i-1+t] = sl->data[i+t];
            t++;
        }
        sl->length--;
        return 0;
    }
}
int locateElem(sqlist*sl,double elem){
    int i = 0;
    for(i = 0;i<sl->length;i++){
        if(elem==sl->data[i]){
            return i+1;
        }
    }
    return 0;//不要忘记查询不到所要返回的结果
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

}
int siftMin(double* data,int low,int high){
    
}