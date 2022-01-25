#include <stdio.h>
#include "stack.h"

void initStack(stack* st){
    //代表此时栈为空
    st->top == -1;
}
int stackEmpty(stack* st){
    return st->top<0;
}
int push(stack* st,double* num){
    if(st->top==maxSize-1){
        printf("It's out of stack maxSize\n");
        return -1;
    }
    st->top++;
    st->data[st->top][0] = num[0];
    st->data[st->top][1] = num[1];
    return 0;
}
double* pop(stack* st){
    if(stackEmpty(st)){
        printf("stack already empty\n");
        return NULL;
    }else{
        double ans[2];
        ans[0] = st->data[st->top][0];
        ans[1] = st->data[st->top--][1];
        return ans;
    }
}
double* getTop(stack* st){
    if(stackEmpty(st)){
        printf("stack already empty\n");
        return -1;
    }else{
        double ans[2];
        ans[0] = st->data[st->top][0];
        ans[1] = st->data[st->top][1];
        return ans;
    }
}