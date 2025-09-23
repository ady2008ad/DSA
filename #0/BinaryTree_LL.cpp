#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node *right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
    void preorder(Node* root){     //Root->Left->Right
        if(root==NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node* root){     //Left->Root->Right
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void postorder(Node* root){     //Left->Right->Root
        if(root==NULL){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(10);
    cout<<"Inorder traversing: ";
    root->inorder(root);
    cout<<endl;
    cout<<"Preorder traversing: ";
    root->preorder(root);
    cout<<endl;
    cout<<"Postorder traversing: ";
    root->postorder(root);
    cout<<endl;
    return 0;
}
/*
        5
       / \
      3   7
     /
    10
*/