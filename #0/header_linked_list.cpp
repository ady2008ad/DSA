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
class HeaderLL{
    public:
    Node *head;
    Node *header;
    HeaderLL(int dummy){
        header=new Node(dummy);
        head=header;
    }

    void insert_at_beg(int value){
        Node* newNode=new Node(value);
        newNode->next=header->next;
        header->next=newNode;
    }

    void insert_at_end(int value){
        Node *newNode=new Node(value);
        Node* temp=header;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void delete_at_beg(){
        if(header->next==NULL){
            cout<<"List is Empty!"<<endl;
            return ;
        }
        else{
            header->next=header->next->next;
        }
    }

    void delete_at_end(){
        if(header->next==NULL){
            cout<<"List is Empty!"<<endl;
            return ;
        }
        else if(header->next->next==NULL){
            header->next=NULL;
        }
        else{
            Node *temp=header;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
        }
    }

    void display(){
        Node* temp=header->next;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    HeaderLL obj(-1);
    obj.insert_at_beg(10);
    obj.insert_at_beg(20);
    obj.insert_at_end(30);
    obj.insert_at_end(40);
    obj.display();
    obj.delete_at_beg();
    obj.display();
    obj.delete_at_end();
    obj.display();
    return 0;
}