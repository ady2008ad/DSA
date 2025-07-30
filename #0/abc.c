#include <stdio.h>

int main()
{
    int arr[100];
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of the array:", i);
        scanf("%d", &arr[i]);
    }

    // Adding an element at start.
    size++;
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = 10;

    //Adding an element at end;
    arr[size++]=20;


    //Adding an element at index 3.
    size++;
    for(int i=size-1;i>3;i--){
        arr[i]=arr[i-1];
    }
    arr[3]=30;


    for (int i = 0; i < size; i++)
    {
        printf("Element %d of array is %d.\n", i, arr[i]);
    }

    return 0;
}