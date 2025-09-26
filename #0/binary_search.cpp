#include <iostream>
using namespace std;
int BS(vector <int> v,int x){
    int low=0;
    int high=v.size()-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(v[mid]==x){hghjghjghjghj
            return mid;
        }
        else if(v[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector <int> v={0,1,2,3,4,5,6,7,8,9};
    cout<<BS(v,8)<<endl;
    return 0;
}