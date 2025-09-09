#include <iostream>
#include <vector>
using namespace std;
void sort(vector <int>& a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
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
    sort(v);
    display(v);
    return 0;

}