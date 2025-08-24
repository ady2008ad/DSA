//WAP to implement a stack using a singly linked list and perform basic stack operations.
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class Stack{
    public:
    Node *head=NULL;
    void push(int d){
        Node *newNode = new Node(d);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return ;
        }
        else
        {
            Node *temp = head;
            while (temp->next!= NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is Empty!"<<endl;
            return ;
        }
        if(head==NULL||head->next==NULL){
            head=NULL;
        }
        else{
            Node *temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
        }
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    
    }
};
int main(){
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.display();
    obj.pop();
    obj.display();
    return 0;
}