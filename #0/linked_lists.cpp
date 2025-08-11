#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
    }
};

class singleLL
{
public:
    Node *head;
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
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp!= NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insert_at_pos(int d){
        Node *newNode=new Node(d);
    }
};

int main()
{

    return 0;
}