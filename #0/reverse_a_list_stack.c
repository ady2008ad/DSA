#include <stdio.h>
int stack[10];
int top=-1;
int size=10;

void declare_array(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("Enter element %d of the array:", i);
        scanf("%d", &arr[i]);
    }
}

void display_array(int arr[], int s)
{
    printf("\n\n");
    for (int i = 0; i < s; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void push(int value){
    if(top==size-1){
        printf("Stack Overflow!\n");
        return;
    }
    else{
        stack[++top]=value;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
    }
    else{
        return stack[top--];
    }
}

int main(){
    int s;
    printf("Enter the size of the array:");
    scanf("%d", &s);
    int arr[s];
    declare_array(arr, s);
    display_array(arr,s);

    for(int i=0;i<s;i++){
        push(arr[i]);
    }

    for(int i=0;i<s;i++){
        arr[i]=pop();
    }

    display_array(arr,s);

    return 0;
}