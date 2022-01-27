# 排序算法相关笔记

作者：ButterSen

- [排序算法相关笔记](#排序算法相关笔记)
  - [插入排序](#插入排序)
    - [直接插入排序](#直接插入排序)
    - [折半插入排序算法](#折半插入排序算法)
    - [2分希尔排序](#2分希尔排序)
  - [选择排序](#选择排序)
    - [简单选择排序](#简单选择排序)
    - [基于大根堆的堆排序算法](#基于大根堆的堆排序算法)
      - [*基于小根堆的递增排序*](#基于小根堆的递增排序)
  - [交换排序算法](#交换排序算法)
    - [冒泡排序](#冒泡排序)
    - [快速排序](#快速排序)
  - [归并排序](#归并排序)

## 插入排序

插入排序的基本思想是每一趟将一个待排序的元素按其关键字值的大小插入到已有序的子表中的适当位置，知道全部插入完成。

**稳定性定义**
   如果待排序的表中存在多个关键字相同的元素，采用某种排序方法排序后这些具有相同关键字的元素之间的相对次序始终保持不变，则称这种排序方法是稳定的；
反之，若具有相同关键字的元素之间的相对次序发生变化，则称这种排序方法是不稳定的。

### 直接插入排序

直接插入排序的思想是依次将每一个元素插入到有序子表当中，假设元素存放在R[0,n-1]中，R[0,i-1]是已排好的子表（简称为有序区，初始时有序区只有一个元素R[0]），R[i,n-1]是未排序的子表（简称为无序区）。插入排序的过程中将无序区的一个元素有序插入到有序区中，直至无序区为空。

**C语言代码实现：**

```C
int directInsertSort(sqlist*sl){
    double tmp;
    for(int i = 1;i<sl->length;i++){
        if(sl->data[i]<sl->data[i-1]){    //反序 这里优化了代码方法，首先通过判断插入元素与有序组最大的元素相比较
           tmp = sl->data[i];   //如果大于，则不用再插入，前i位数组直接为有序组，反之，需要插入，按照比大小的方式进行排序
           int j = i-1;                   //j指向有序组最后的元素
           while(tmp<sl->data[j]&&j>=0){  //不能忽略j>=0，防止数组越界
               sl->data[j+1] = sl->data[j];a
               j--;
           }
           sl->data[j+1] = tmp;
        }
    }
}
```

### 折半插入排序算法

折半插入排序算法相当于直接插入排序算法优化的部分在于在有序插入时所采取折半查询的方法

**C语言代码实现：**

```C
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
    }
}
```

### 2分希尔排序

希尔(shell)排序有称为缩小增量排序，其基本思想是把元素按下标的一定增量d(或步长)分组，再对每组元素采用直接插入排序的方法进行排序，然后随着增量逐渐减小，所分成的组包含的元素越来越多，到d值减小到1时，整个数据合成为一组，对该组进行直接插入排序，得到整个有序序列。
**C语言代码实现如下:**

```C
int shellSort(sqlist* sl){
    //元素按下标一定增量进行分组，再对每个分组元素采用直接插入排序进行排序
    //首先要想如何进行分组
    int d = sl->length/2;
    while(d>0){
        //sl->length - d为循环次数
        for(int i = d;i<sl->length;i++){
            int tmp = sl->data[i],j = i;
            while(j>=d&&sl->data[j-d]>tmp){//反序
                sl->data[j] = sl->data[j-d];
                j-=d;
            }
            sl->data[j] = tmp;
        }
        d=d/2;
    }
}
```

值得注意的是无论是几分的希尔排序，最后一次排序的d都必须为1才能保证排序有效

## 选择排序

选择排序的基本思想是每步从待排序元素中选出关键字最小的元素，顺序放在已排序的元素序列的最后，直到排完为止。

### 简单选择排序

简单选择排序的思想是将数组分为有序区和无序区（类似于插入排序，只不过这里的有序区也相对于**全局有序**），初始时有序区为空，无序区为原数组，从无序区中选取最小的元素放在有序区的末尾，知道无序区为空为止。
**C语言代码实现**

```C
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
```

### 基于大根堆的堆排序算法

堆的定义：堆是一个顺序存储的完全二叉树，其中每个结点的关键字都不小于其孩子结点的关键字，这样的堆称为**大根堆**。
如果堆中每个结点的关键字都不大于孩子结点的关键字，这样的堆称为**小根堆**。

（完全二叉树的定义：若二叉树的深度为h，除第h层以外，其他h-1层的结点数都达到了最大个数，并且第h层所有节点都连续集中在最左边）

堆排序的基本思想是首先按照**大根堆的定义将初始序列R[0..n]调整为堆（这个过程称为初始建堆），先交换R[0]和R[n]**（将最大元素R[0]归位，放到排序序列的最后）；

**然后将R[0..n-1]调整为堆，再交换R[0]和R[n-1]**；如此反复，直到只有一个元素，它就是最小元素。

堆排序要多次调用筛选算法。筛选算法的前提是将R[low..high]序列看成是一颗以R[low]为根节点的完全二叉树，其**左子树和右子树均为大根堆，只有根节点不满足大根堆条件**。

依据上述点我们对初始序列进行建堆时也得一步一步来，先从最低分支节点进行建堆；

有了筛选算法与堆排序算法的基本思想，我们就可以设计出堆排序算法；

**C语言代码实现**

*筛选算法*

```C
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
```

*堆选择算法*

```C
int heapChooseSort(sqlist* sl){
    for(int i = (sl->length-1)/2;i>=0;i--){
        sift(sl->data,i,sl->length-1);//先将整个序列变换成大顶堆
    }
    slPrint(sl);
    //在当时进行编程的时候对于for循环j值的终止条件有误判的点，以前书写的是j>1，还是在编程上对于每一部分实现的意图与真实过程出现了自己的失误，说明了自身编程能力还有待提高
    for(int j = sl->length-1;j>0;j--){
        double tmp = sl->data[0];
        sl->data[0] = sl->data[j];
        sl->data[j] = tmp;
        //以上的目的在于要把大顶堆的根节点与第j个元素进行替换
        //而下面的意义在于将大顶堆前j-1个元素重新进行建堆
        sift(sl->data,0,j-1);
    }
}
```

#### *基于小根堆的递增排序*  

```C
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
```

## 交换排序算法

交换排序的基本方法是两两比较待排元素的关键字，交换不满足次序要求的那些偶对，直到全部满足要求为止。

### 冒泡排序

冒泡排序的思想很简单，通过无序区中相邻元素关键字间的比较和位置上的交换，是关键字最小的元素如气泡一般逐渐往上“漂浮”直至“水面”（也可以是最大的元素沉入水底，基本思想是一样的）。
| 时间复杂度     |     |      | 空间复杂度 | 稳定性 | 复杂性 |
|--------|--------|------|-------|-----|-----|
| 平均情况   | 最坏情况   | 最好情况 |       |     |     |
| O(n^2) | O(n^2) | O(n) | O(1)  | 稳定  | 简单  |

**C语言代码实现**

*沉入水底*

```C
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
```

*浮出水面*

```C
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
```

### 快速排序

   要了解快速排序算法，最重要的是要了解**快速排序的思想**！不然对于快速排序算法实现就无法掌握得很好。

**快速排序的基本思想：**

快速排序是由冒泡算法改进而得的，它的基本思想是在待排序的n个元素中选出一个元素作为基准（通常取第一个元素），把基准放入最终位置后，整个数据区间被基准分割成两个子区间，所有关键字比基准小的放置在前子区间中，所有比基准大的放置在后子区间中，并把基准排在这两个子区间的中间，这个过程称作一趟快速排序或者划分；然后对所有两个子区间重复相同过程，直至每个子区间内的数量只有0个或1个。

划分的过程采用从两头向中间扫描的办法，**同时交换与基准元素逆序的元素**，具体做法是设置两个指示器i和j,他们的初值分别指向无序区中第一个和最后一个元素。假设无序区中的元素为R[s..t]，则i的初值为s,j的初值为t,首先将基准R[s]赋给临时变量tmp,然后将tmp值与R[j]值作比较，若小于则j--，若大于则将R[j]移到R[i]处；然后令i自前往后扫描，然后将tmp值与R[i]作比较，若大于则i++,若小于则将R[i]移到R[j]处；如此重复直到i=j,最终将tmp赋给R[i]。

**C语言代码实现**

*使用递归实现*

```C
int quickSort(sqlist* sl){
    quicksort(sl,0,sl->length-1);
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
```

*使用栈代替递归*
```C
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
```
## 归并排序
归并排序的基本思想是将$R[0..n-1]$看成n个长度为1的有序表，将相邻有序表成对归并，得到n/2个长度为2的有序表；再将这些有序表成对归并，得到n/4个长度为4的有序表；如此反复进行下去，最后得到一个长度为n的有序表。

由于归并是在相邻两个有序表中进行的，因此，上述排序方法也叫**二路归并排序**。如果归并操作在相邻的多个有序表中进行，则叫**多路归并排序**。

将两个有序表归并为一个有序表的算法为merge。设两个有序表$R[low..mid],R[mid+1..high]$归并后存放在$R[low..high]$中，为了简便，称$R[low..mid]$为第一段，称$R[mid+1..high]$为第二段，每次从两个段中取出一个元素进行关键字的比较，将较小者放入R1中，最后将各段中余下的部分直接复制到R1中。这样得到的R1是一个有序表，再将其复制回R中。

merge实现了一次归并，我们需要函数mergePass去解决一趟归并问题。在某趟归并中，设各子表的长度为length（最后一个子表的长度可能小于length），则归并前共$\lceil{n/length}\rceil$个有序的子表，分别为$R[0..length-1]、R[length..2length-1]、...、R[(\lceil{n/length}\rceil)*length..n-1]。$

调用merge将相邻的一对子表进行归并时，必须对表的个数可能是奇数以及最后一个表的长度小于length这两种特殊情况进行特殊处理。若子表个数为奇数，则最后一个表无须和其他子表进行归并（即本趟轮空）；若子表个数为偶数，则要注意到最后一对子表中后一个子表的区间上界是n-1。

**C语言代码实现**
```C
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
```
*三路归并(合成三个有序表)*
```C
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
```



