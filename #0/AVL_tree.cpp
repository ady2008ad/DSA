#include <iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
class AVL{
    Node* root;
    void insert_rec(Node* root,int key){

    }
    public:
    void insert(int key){
        insert(root,key);
    }
    void delet(int key){

    }
    void search(int key){

    }

}