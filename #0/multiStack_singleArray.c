//Multistack using single array.

#include <stdio.h>
int arr[10];
int max_size=10;
int n=3;    //number of stacks
int top[3]={-1};
int next[] = {1,2,3,4,5,6,7,8,9};
int freeslot=0;

void push(int val, int m){     // m-> stack number
    int index=freeslot;
    freeslot=next[index];
    arr[index]=val;
    next[index]=top[m-1];
    top[m-1]=index;
}

void pop(int m){
    
}




int main() {
	for(int i=0; i< 99;i++){
		
	}
	return 0;
}