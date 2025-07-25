// Program to reverse a list.
#include <stdio.h>
void declare_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of the array:", i);
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int size)
{
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int arr[size];
    declare_array(arr, size);
    int i = 0, j = size - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    display_array(arr, size);

    return 0;
}