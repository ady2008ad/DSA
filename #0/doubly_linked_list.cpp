#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        data=d;
        next=prev=NULL;
    }
};

class doublyList{
    public:
    Node* head;
    Node* tail;
    doublyList(){
        head=tail=NULL;
    }
    void insert_at_beg(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return ;
        }
        else{
            newNode->prev=NULL;
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return ;
        }
    }

    void insert_at_end(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return ;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void delete_from_beg(){
        if(head==NULL){
            cout<<"List is Empty!"<<endl;
            return ;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        delete temp;
    }

    void delete_from_end(){
        if(head==NULL){
            cout<<"List is Empty!"<<endl;
            return ;
        }
        Node *temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        delete temp;
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
    doublyList obj;
    obj.insert_at_beg(10);
    obj.insert_at_beg(20);
    obj.insert_at_end(30);
    obj.insert_at_end(40);
    obj.display();
    obj.delete_from_beg();
    obj.display();
    obj.delete_from_end();
    obj.display();
    return 0;
}