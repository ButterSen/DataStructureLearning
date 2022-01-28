# 树与二叉树学习笔记

- [树与二叉树学习笔记](#树与二叉树学习笔记)
  - [树的各种基本概念](#树的各种基本概念)
    - [1、树的定义](#1树的定义)
    - [2、树的表示方法](#2树的表示方法)
    - [3、树的基本术语](#3树的基本术语)
      - [（1）结点的度与树的度](#1结点的度与树的度)
      - [（2）分支结点与叶子结点](#2分支结点与叶子结点)
      - [（3）路径与路径长度](#3路径与路径长度)
      - [（4）孩子结点、双亲结点和兄弟结点](#4孩子结点双亲结点和兄弟结点)

## 树的各种基本概念
### 1、树的定义
树是由n个结点（元素）组成的有限集合（记为T）。如果n=0，它是一棵空树，这是树的特例；如果n>0，这n个结点中存在（有仅存在）一个结点为树的根节点，简称根节点，其余结点可分为m(m>0)个互不相交的有限集$T_1、T_2、...、T_m$，其中每一个子集本身又是一棵符合本定义的树，称为根节点的子树。
树的定义是递归的，因为在树的定义当中又用到了树的定义。它刻画了树的固有特性，即一棵树由若干棵子树构成，而子树又是由更小的子树构成，所以树特别适合表示元素之间的层次关系。
### 2、树的表示方法
树形表示法、文氏图表示法、凹入表示法、括号表示法。
### 3、树的基本术语
#### （1）结点的度与树的度
树中某个结点的子树的个数称为该结点的度。树中度的最大值称为树的度，通常度为m的树称为m次树。
#### （2）分支结点与叶子结点
度不为0的结点称为非终端结点，又称为分支结点。度为0的结点称为终端结点或者说是叶子结点。在分支节点中，每个结点的分支数就是该结点的度，如度为1的结点，其分支数为1，称为单分支结点；对于度为2的结点，其分支数为2，称为双分支结点，以此类推。
#### （3）路径与路径长度
对于任意两个结点$k_i$和$k_j$，若树中存在一个结点序列$k_ik_{i1}k_{i2}...k_{in},k_j$，使得序列中除$k_i$外的任一结点都是其前一个结点的后继结点，则该结点序列为由$k_i$到$k_j$的一条路径，用路径所通过的结点序列($k_ik_{i1}k_{i2}...k_{in},k_j$)可表示这条路径。路径的长度等于路径所通过的分支线的数目。
#### （4）孩子结点、双亲结点和兄弟结点
在一棵树中，每个结点的后继称作该结点的孩子结点。相应地，该结点称为该孩子结点的双亲结点（父结点）。具有同意双亲的孩子结点称为兄弟结点。