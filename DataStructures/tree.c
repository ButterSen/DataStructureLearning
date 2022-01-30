#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

/*************二叉树的基本算法*********************/
BTNode* createBTNode(char);
BTNode* createBTreeByParentheses(char*);
BTNode* transArrayToBTree(char*);
BTNode* createRandomBTree();
void preOrderRecursive(BTNode*);
BTNode* findX(BTNode*,char);
BTNode* findXVS(BTNode*,char);
void destoryBTree(BTNode*);
void destoryBTreeVS(BTNode*);
int getBTreeHeight(BTNode*);
int getBTreeHeightVS(BTNode*);

int main(){
    srand((unsigned)time(0));
    // char* str1 = "A(B(D(,G)),C(E,F))";
    // BTNode* root1 = createBTreeByParentheses(str1);
    // char* str2 = " ABCD#EF#G";
    // BTNode* root2 = transArrayToBTree(str2);
    // preOrderRecursive(root1);
    // preOrderRecursive(root2);
    // printf("\n");
    int i = 1;
    while(i++<100){
    BTNode* root = createRandomBTree();
    preOrderRecursive(root);
    printf("\n");
    
    // printf("%d",getBTreeHeight(root));
    // printf("\n");

    // char c = 'H';
    // BTNode* tmp = findXVS(root,c);
    // if(tmp!=NULL)printf("%c",tmp->data);
    // else printf("\'%c\' not found",c);
    // printf("\n");
    }

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
    if(!btnStackEmpty(btns))
    return btns->btNodes[btns->top--];
    else return NULL;
}
BTNode* getTopBTNode(BTNodeStack* btns){
    if(!btnStackEmpty(btns))
    return btns->btNodes[btns->top];
    else return NULL;
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

BTNode* transArrayToBTree(char*  SBTree){
    //默认顺序表存储二叉树序号是从1开始的
    //空结点用'#'来表示
    if(SBTree==NULL||SBTree == "\0"){return NULL;}
    char ch = SBTree[1];
    //防止树为空或者根结点为空
    if(ch=='\0'||ch == '#'){return NULL;}
    BTNode* root = createBTNode(ch);
    BTNodeStack* btns = (BTNodeStack*)malloc(sizeof(BTNodeStack));
    initBTNodeStack(btns);
    pushBTNode(btns,root);
    int i = 2,len = 0;
    //计算长度的目的是防止在找寻子结点时越界
    while(ch!='\0'){len++;ch = SBTree[len+1];}
    ch = SBTree[i];
    while(1){
        if(i<=len){
            //未出界且左子结点
            if(i%2==0){
                if(ch!='#'){
                    BTNode* lchild = createBTNode(ch);
                    getTopBTNode(btns)->lchild = lchild;
                    pushBTNode(btns,lchild);
                    i = 2*i;
                }else{
                    //查询右子结点
                    i++;
                }
            }
            else{
                if(ch!='#'){
                    BTNode* rchild = createBTNode(ch);
                    getTopBTNode(btns)->rchild = rchild;
                    pushBTNode(btns,rchild);
                    i = 2*i;
                }else{
                    //如果右子结点为空，一直出栈直到左子节点
                    while(i%2==1&&!btnStackEmpty(btns)){
                        popBTNode(btns);
                        i/=2;
                    }
                    //如果最后是根结点
                    if(btnStackEmpty(btns)){return root;}
                    i++;
                }
            }
        }else{
            //若出界，则进行出栈，多增加一步操作是因为存在左子结点越界的情况
            i/=2;
            popBTNode(btns);
            while(i%2==1&&!btnStackEmpty(btns)){
                popBTNode(btns);
                i/=2;
            }
            //如果最后是根结点
            if(btnStackEmpty(btns)){return root;}
            i++;
        }
        ch = SBTree[i];
    }    
}

BTNode* createRandomBTree(){
    double test = (double)rand()/(double)INT_MAX;
    int len = (int)(((double)rand()/(double)RAND_MAX)*26);
    // printf("%d\n",len);
    char str[len+1];
    int prob = 20,random,index = 0;
    for(int i = 0;i<len;i++){
        str[i] = 't';
    }
    str[len] = '\0';
    if(len<2){return NULL;}
    for(int i = 1;i<len;i++){
        if(str[i/2]!='#'){
            random = (double)rand()/(double)RAND_MAX*prob;
            if(random<=prob-2){
                str[i] = 'A'+index;
                index++;
            }else{
                str[i] = '#';
            }
        }else{
            str[i] = '#';
        }
    }
    // printf("%s %d %d",str,index,len);
    return transArrayToBTree(str);
}

void preOrderRecursive(BTNode* root){
    if(root != NULL){
    printf("%c",root->data);
    preOrderRecursive(root->lchild);
    preOrderRecursive(root->rchild);
    }
}

BTNode* findX(BTNode* btn,char c){
    BTNode* p;
    if(btn==NULL){
        return NULL;
    }else if(btn->data==c){
        return btn;
    }else{
        p = findX(btn->lchild,c);
        if(p!=NULL) return p;
        else return findX(btn->rchild,c);
    }
}

BTNode* findXVS(BTNode* btn,char c){
    if(btn==NULL){return NULL;}
    BTNodeStack* btns = (BTNodeStack*)malloc(sizeof(BTNodeStack));
    initBTNodeStack(btns);
    pushBTNode(btns,btn);
    while(!btnStackEmpty(btns)){
        BTNode* tmp = popBTNode(btns);
        if(tmp->data==c){
            return tmp;
        }else{
            //入栈子结点
            if(tmp->lchild!=NULL){
                pushBTNode(btns,tmp->lchild);
            }
            if(tmp->rchild!=NULL){
                pushBTNode(btns,tmp->rchild);
            }
        }
    }
    return NULL;
}

void destoryBTree(BTNode* root){
    if(root!=NULL){
        destoryBTree(root->lchild);
        destoryBTree(root->rchild);
        free(root);
    }
}

void destoryBTreeVS(BTNode* root){
    BTNodeStack* btns = (BTNodeStack*)malloc(sizeof(BTNodeStack));
    initBTNodeStack(btns);
    if(root!=NULL){
        pushBTNode(btns,root);
    }
    while(!btnStackEmpty(btns)){
        BTNode* temp = popBTNode(btns);
        if(temp->lchild!=NULL){
            pushBTNode(btns,temp->lchild);
        }
        if(temp->rchild!=NULL){
            pushBTNode(btns,temp->rchild);
        }
        free(temp);
    }
}

int getBTreeHeight(BTNode* root){
    if(root==NULL){return 0;}
    else{
        return fmax(getBTreeHeight(root->lchild),getBTreeHeight(root->rchild))+1;
    }
}

int getBTreeHeightVS(BTNode* root){
    if(root!=NULL){
        
    }else{
        return 0;
    }
}

