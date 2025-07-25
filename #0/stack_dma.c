#include <stdio.h>
#include <stdlib.h>

int *stack;
int top=-1;
int size;

void createStack(int ini_size){
    size=ini_size;
    stack=(int*)malloc(size*sizeof(int));
    if(!stack){
        printf("Memory allocation failed");
        exit(1);
    }
}

void push(int val){
    if(top==size-1){
        printf("Stack Overfow!\n");
    }
    else{
        top=top+1;
        stack[top]=val;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is empty!\n");
    }
    else{
        printf("%d is removed from the stack.\n",stack[top]);
        top=top-1;
    }
}

void display(){
    printf("Stack elements: ");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

int main(){
    createStack(5);
    push(10);
    push(20);
    push(30);
    pop();
    display();

    free(stack);
    
    return 0;
}