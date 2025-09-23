#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]); 
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(a[j]);
        j++;
    }
    for (int k = low; k <= high; k++)
    {
        a[k] = temp[k - low];
    }
}

void mergeSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {18, 13, 17, 15, 19, 20};
    display(v);

    mergeSort(v, 0, v.size() - 1);
    display(v);
    return 0;
}