//Binary Tree: A data structure in which each node has atmost two children referred as left child and right child.
#include <iostream>
using namespace std;
class BT
{
    public:
    char *arr;
    int size;
    int capacity;
    BT(int s)
    {
        arr = new char[s];
        size = 0;
        capacity = s;
    }
    void insert_element(char v)
    {
        if (size >= capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        arr[size++] = v;
    }
    int getParent(int i)
    {
        return (i - 1) / 2;
    }
    int getLeft(int i)
    {
        return (2 * i) + 1;
    }
    int getRight(int i)
    {
        return (2 * i) + 2;
    }
    void inorder(int i){     //Left->Root->Right
        if(i>=size){
            return ;
        }
        inorder((2*i)+1);
        cout<<arr[i]<<" ";
        inorder((2*i)+2);
    }
    void preorder(int i){    //Root->Left->Right
        if(i>=size){
            return ;
        }
        cout<<arr[i]<<" ";
        preorder((2*i)+1);
        preorder((2*i)+2);
    }
    void postorder(int i){    //Left->Right->Root
        if(i>=size){
            return ;
        }
        postorder((2*i)+1);
        postorder((2*i)+2);
        cout<<arr[i]<<" ";
    }
};
int main(){
    BT obj(7);
    obj.insert_element('A');
    obj.insert_element('B');
    obj.insert_element('C');
    obj.insert_element('D');
    obj.insert_element('E');
    obj.insert_element('F');
    obj.insert_element('G');
    cout<<"Inorder traversing: ";
    obj.inorder(0);
    cout<<endl;
    cout<<"Preorder traversing: ";
    obj.preorder(0);
    cout<<endl;
    cout<<"Postorder traversing: ";
    obj.postorder(0);
    cout<<endl;
    return 0;
}
/*
        A
       / \
      B   C
     / \ / \
    D  E F  G
*/