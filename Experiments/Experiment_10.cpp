#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector <int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
void InsertionSort(vector <int>& a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
}
void SelectionSort(vector <int>& a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}
void display(vector <int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector <int> v={23,1,10,5,2};
    display(v);
    int n;
    cout<<"Enter 1 to sort using Bubble Sort, 2 to sort using Insertion Sort and 3 to sort using Selection Sort:";
    cin>>n;
    switch(n){
        case 1:
        BubbleSort(v);
        display(v);
        break;
        case 2:
        InsertionSort(v);
        display(v);
        break;
        case 3:
        SelectionSort(v);
        display(v);
        break;
        default:
        cout<<"Invalid Input"<<endl;
        break;
    }
    return 0;

}