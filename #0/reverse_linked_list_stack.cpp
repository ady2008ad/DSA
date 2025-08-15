//Reversing a linked list using stack.
#include <iostream>
using namespace std;

class Stack{
    public:
    int *stack;
    int top;
    int size;

    class singleLL;

    Stack(int s){
        stack=new int[s];
        top=-1;
        size=s;
    }

    void push(int value){
        stack[++top]=value;
    }

    int pop(){
        return stack[top--];
    }
    friend class singleLL;

};

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next=NULL;
    }
};

class singleLL
{
public:
    Node *head=NULL;
    void insert_at_beg(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insert_at_end(int d)
    {
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

    void insert_at_pos(int d,int pos){
        Node *newNode=new Node(d);
        Node *temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void delete_at_beg(){
        if(head==NULL){
            cout<<"Linked List is Empty"<<endl;
            return ;
        }
        else{
            head=head->next;
        }
    }

    void delete_at_end(){
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

    void delete_at_pos(int pos){
        Node *temp=head;
        for(int i=1;i<=pos-2;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }


    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverse(Stack &s){
        Node *temp=head;
        while(temp!=NULL){
            s.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            int val=s.pop();
            temp->data=val;
            temp=temp->next;
        }

    }
};

int main()
{
    singleLL obj;
    Stack s(100);
    obj.insert_at_beg(10);
    obj.insert_at_beg(20);
    obj.insert_at_beg(30);
    obj.insert_at_end(40);
    obj.insert_at_end(50);
    obj.insert_at_end(60);
    obj.insert_at_pos(70,3);
    obj.display();
    obj.delete_at_end();
    obj.delete_at_beg();
    obj.display();
    obj.reverse(s);
    obj.display();

    return 0;
}