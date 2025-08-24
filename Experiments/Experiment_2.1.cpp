//WAP to implement a Stack using One-Dimensional Array.
#include <stdio.h>

int size=5;
int stack[5];
int top=-1;

int isFull(){
    return (top==size-1);
}

int isEmpty(){
    return (top==-1);
}

void push(int val){
    if(isFull()){
        printf("Stack is full.\n\n");
    }
    else{
        top=top+1;
        stack[top]=val;
        printf("%d is added to the stack.\n\n",val);
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is Empty.\n\n");
    }
    else{
        int v=stack[top];
        top=top-1;
        printf("%d is removed form the stack.\n\n",v);
    }
}

void peek(){
    printf("The top value of the stack is %d.\n\n",stack[top]);
}

void display(){
    printf("Stack= ");
    for(int i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
    printf("\n\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}