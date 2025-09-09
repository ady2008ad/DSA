#include <iostream>
#include <vector>
using namespace std;
void sort(vector <int>& a){
    int n=a.size();
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
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