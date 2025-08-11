#include <iostream>
using namespace std;
int* add(int p1[], int p2[], int max_degree){
    int *res = new int[max_degree+1];
    for(int i=0;i<=max_degree;i++){
       res[i] = p1[i] + p2[i];
    }
    return res;
}
void display(int p1[], int max_degree){
    for(int i=max_degree;i>=0;i--){
        if(i==0){
            cout<<p1[i]<<"x^"<<i;
        }
        else{

            cout<<p1[i]<<"x^"<<i<<"+";
        }
    }
    cout<<endl;
}
int main(){
    int p1[100];
    int p2[100];
    int max_degree=2;
    cout<<"Enter fist polynomial:"<<endl<<endl;
    for(int i=0;i<=max_degree;i++){
        cout<<"Enter the coffecient of x^"<<i<<": ";
        cin>>p1[i];
    }
    cout<<"Enter second polynomial:"<<endl<<endl;
    for(int i=0;i<=max_degree;i++){
        cout<<"Enter the coffecient of x^"<<i<<": ";
        cin>>p2[i];
    }
    // for(int i=0;i<=max_degree;i++){
    //     p1[i]=p1[i]+p2[i];
    // }
    int *res=add(p1,p2,max_degree);

    // for(int i=0;i<=max_degree;i++){
    //     cout<<p1[i]<<"x^"<<i<<"+";
    // }
    // cout<<"\b"<<endl;
    display(p1,max_degree);
    display(p2,max_degree);

    display(res,max_degree);

    

    return 0;

}