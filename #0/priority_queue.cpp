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
    void insert(int d, int priority_value) {
    // Step 1: Check Overflow
    if (count == maxsize) {
        cout << "Queue Overflow!" << endl;
        return;
    }

    int i;
    // Step 2: Traverse backward to find the correct position
    for (i = count - 1; i >= 0; i--) {
        // Step 3: Shift elements if they have greater priority value
        if (q[i].pv > priority_value) {
            q[i + 1] = q[i];
        } else {
            break;
        }
    }

    // Step 4: Insert at the found position
    q[i + 1].data = d;
    q[i + 1].pv = priority_value;

    // Step 5: Increase the count
    count++;
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
    obj.insert(10,1);
    obj.insert(20,3);
    obj.insert(30,2);
    obj.display();
    obj.del();
    obj.display();
    return 0;
}