#include <stdio.h>
int q[100];
int front=-1;
int rear=-1;
int size=5;

int isFull(){
    if((rear+1)%size==front){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front==-1){
        return 1;
    }
    return 0;
}

void enqueue(int v){
    if(isFull()){
        printf("Queue is full!\n");
        return ;
    }
    if(front==-1){
        front=0;
    }
    rear=(rear+1)%size;
    q[rear]=v;
}

void dequeue(){
    int ele;
    if(isEmpty()){
        printf("Queue is Empty\n");
        return ;
    }
    if(front==rear){    //Only one element
        front=rear=-1;
        return ;
    }
    ele=q[front];
    front=(front+1)%size;
    printf("%d is removed!\n",ele);
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d   ",q[i]);
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
    enqueue(40);
    display();
    return 0;
}