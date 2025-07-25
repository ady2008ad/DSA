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
    int a,b;

    start:
    printf("Enter 1 to push a value to stack\nEnter 2 to pop a value from the stack\nEnter 3 to peek a value from the stack\nEnter 4 to see the full stack\nEnter 5 to exit program\n ");

    scanf("%d",&a);

    switch(a){
        case 1:
        printf("Enter the value you want to push: ");
        scanf("%d",&b);
        push(b);
        break;

        case 2:
        pop();
        break;

        case 3:
        peek();
        break;

        case 4:
        display();
        break;

        case 5:
        goto end;
    }

    goto start;

    end:
    return 0;
}