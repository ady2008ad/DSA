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

class CircularLL{
    public:
    Node *head=NULL;

    void insert_at_beg(int d){
        Node *newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            newNode->next=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    void insert_at_end(int d){
        Node *newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            newNode->next=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    void insert_at_pos(int pos,int d){
        Node *newNode=new Node(d);
        Node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};