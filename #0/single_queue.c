#include <stdio.h>
int q[100];
int size=5;
int front=-1;
int rear=-1;
int isFull(){
    if(rear==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front==-1||front>rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int value){
    if(isFull()){
        printf("Overfull\n");
    }
    else{
        if(front==-1){
            front=rear=0;
        }
        else{
            rear=rear+1;
        }
        q[rear]=value;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow\n");
    }
    else{
        int ele=q[front];
        front=front+1;
        printf("%d deleted.\n",ele);
    }
}

void display(){
    int i;
    printf("\n\n");
    if(isEmpty()){
        printf("Queue is Empty.\n");
    }
    else{
        i=front;
        while(1){
            printf("%d  ",q[i]);
            if(i==rear){
                break;
            }
            i=i+1;
        }
    }
}

int main(){

    enque(5);
    enque(10);
    enque(15);
    display();
    dequeue();
    display();

    return 0;
}