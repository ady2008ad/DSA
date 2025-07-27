#include <stdio.h>
int s1[10];
int s2[10];
int top1=-1;
int top2=-1;
int size1=10;
int size2=10;

void push1(int value){
    if(top1==size1-1){
        printf("Stack Overflow!\n");
        return;
    }
    else{
        s1[++top1]=value;
    }
}

void push2(int value){
    if(top2==size2-1){
        printf("Stack Overflow!\n");
        return;
    }
    else{
        s2[++top2]=value;
    }
}

int pop1(){
    if(top1==-1){
        printf("Stack Underflow!\n");
        return -1;
    }
    else{
        return s1[top1--];
    }
}

int pop2(){
    if(top2==-1){
        printf("Stack Underflow!\n");

        return -1;
    }
    else{
        return s2[top2--];
    }
}

void enqueue(int val){
    push1(val);
}

void dequeue(){
    if(top1==-1){
        printf("Queue is Empty!\n");
    }
    while(top1!=-1){
        push2(pop1());
    }
    int v=pop2();
    printf("%d is removed!\n",v);
    while(top2!=-1){
        push1(pop2());
    }
}

void display(){
    for (int i=0;i<=top1;i++){
        printf("%d  ",s1[i]);
    }
    printf("\n");
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();



    return 0;
}