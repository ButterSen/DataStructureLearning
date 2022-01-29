#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
//本程序时用来实现二叉树的各种算法
typedef struct node{
    char data;
    struct node* lchild;
    struct node* rchild;
}BTNode;

typedef struct{
    BTNode* btNodes[MaxSize];
    int top;
}BTNodeStack;
/*************二叉树结点栈的基本操作****************/
int initBTNodeStack(BTNodeStack*);
BTNode* popBTNode(BTNodeStack*);
BTNode* getTopBTNode(BTNodeStack*);
int pushBTNode(BTNodeStack*,BTNode*);
int btnStackEmpty(BTNodeStack*);

BTNode* createBTNode(char);
BTNode* createBTreeByParentheses(char*);
void preOrderRecursive(BTNode*);

int main(){
    char* str = "A(B(D(,G)),C(E,F))";
    BTNode* root = createBTreeByParentheses(str);
    preOrderRecursive(root);
    return 0;    
}

int initBTNodeStack(BTNodeStack* btns){
    btns->top=-1;
    return 0;
}
int pushBTNode(BTNodeStack* btns,BTNode* btn){
    btns->top++;
    btns->btNodes[btns->top] = btn;
    return 0;
}
BTNode* popBTNode(BTNodeStack* btns){
    return btns->btNodes[btns->top--];
}
BTNode* getTopBTNode(BTNodeStack* btns){
    return btns->btNodes[btns->top];
}
int btnStackEmpty(BTNodeStack* btns){
    return btns->top==-1;
}

BTNode* createBTNode(char c){
    BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
    ret->data = c;
    ret->lchild = NULL;
    ret->rchild = NULL;
    return ret; 
}

BTNode* createBTreeByParentheses(char* str){
    //k用于标识下一个孩子结点是左孩子结点还是右孩子结点
    //算法缺陷：无法判断给出的是否是标准字符串
    int k = 0,i = 1;
    BTNodeStack* btns = (BTNodeStack*)malloc(sizeof(BTNodeStack));
    initBTNodeStack(btns);
    BTNode* tmp,*root;
    char ch=str[0];
    if(ch!='\0'){tmp = root = createBTNode(ch);}
    else{return NULL;}
    while(ch!='\0'){
        switch(ch){
            case '(':pushBTNode(btns,tmp);k=1;break;
            case ')':popBTNode(btns);break;
            case ',':k=2;break;
            default:
            //左孩子结点
            if(k==1){
                tmp = createBTNode(ch);
                getTopBTNode(btns)->lchild = tmp; 
            }else if(k==2){
                tmp = createBTNode(ch);
                getTopBTNode(btns)->rchild = tmp;
            }
            break;
        }
        ch = str[i++];
    }
    return root;
}

void preOrderRecursive(BTNode* root){
    if(root != NULL){
    printf("%c",root->data);
    preOrderRecursive(root->lchild);
    preOrderRecursive(root->rchild);
    }
}