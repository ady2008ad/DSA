// WAP on a 32-bit compiler to understand the concept of array storage, size of a word. Find the address of element and verify it with the theoretical value. Program may be written for arrays up to 4-dimensions.
#include <iostream>
using namespace std;

int main()
{
    int arr1[5], arr2[2][3], arr3[2][2][2];
    cout << "Word size = " << sizeof(int) << " bytes\n\n";

    cout << "arr1[3] address = " << &arr1[3]<< ", theoretical = " << (int *)arr1 + 3 << "\n";

    cout << "arr2[1][2] address = " << &arr2[1][2]<< ", theoretical = " << (int *)arr2 + (1 * 3 + 2) << "\n";

    cout << "arr3[1][1][0] address = " << &arr3[1][1][0]<< ", theoretical = " << (int *)arr3 + (1 * 2 * 2 + 1 * 2 + 0) << "\n";

    return 0;
}