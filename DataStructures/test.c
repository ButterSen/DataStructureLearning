#include<stdio.h>
void changeElem(int*);
int main(){
    int e;
    e = 5;
    changeElem(&e);
    printf("%d",rand());
}
void changeElem(int* e){
    int temp = 3;
    *e = temp;
}