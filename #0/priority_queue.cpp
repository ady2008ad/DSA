#include <iostream>
using namespace std;
class PQ{
    public:
    int data;
    int pv;
};
class PQimp{
    public:
    int count=0;
    PQ* q;
    int maxsize;
    PQimp(int ms){
        maxsize=ms;
        q=new PQ[ms];
    }
    void insert(int d, int priority_value){
        //Step1: Check Overflow
        //Step2: Traverse the q
        //Step3: Check q[1].pv>priority value
        //Step4: If step 3 is true shift till condition is true
        //Step5: Insert the data
        //Step6: Increase the count
        for(int i=count;i>=0;i++){
            if(q[i].pv>priority_value){
                q[i+1]=q[i];
            }
            else{
                q[i].data=d;
                q[i].pv=priority_value;
                count++;
                break;
            }
        }
    }
    void del(){
        for(int i=0;i<count;i++){
            q[i]=q[i+1];
        }
        count--;
    }

    void display(){
        for(int i=0;i<count;i++){
            cout<<q[i].data<<" ";
        }
        cout<<endl;
    }
};
int main(){
    PQimp obj(100);
    obj.insert(10,2);
    obj.insert(20,3);
    obj.insert(30,1);
    obj.display();
    obj.del();
    obj.display();
    return 0;
}