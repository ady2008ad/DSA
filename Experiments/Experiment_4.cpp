//WAP to perform Sparse Matrix Representation and operations using Arrays.
#include <iostream>
using namespace std;

int main(){
    int row, col;
    cout<<"Enter number of rows:";
    cin>>row;
    cout<<"Enter number of columns:";
    cin>>col;
    
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter element ["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
        }
    }
    int non_zero=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                non_zero++;
            }
        }
    }
    int sparse[non_zero+1][3];
    sparse[0][0]=row;
    sparse[0][1]=col;
    sparse[0][2]=non_zero;
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=arr[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<non_zero+1;i++){
        for(int j=0;j<3;j++){
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}