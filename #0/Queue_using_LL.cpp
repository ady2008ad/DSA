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
    void enqueue(int d){
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
    void dequeue(){
        if(head==NULL){
            cout<<"Linked List is Empty"<<endl;
            return ;
        }
        else{
            head=head->next;
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
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.display();
    obj.dequeue();
    obj.display();
    return 0;
}