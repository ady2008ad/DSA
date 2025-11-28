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
        next = NULL;
    }
};

class CircularLL
{
public:
    Node *head = NULL;

    void insert_at_beg(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
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
            newNode->next = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insert_at_pos(int pos, int d)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_at_beg()
    {
        if (head == NULL)
            return;

        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = head;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
        }
    }

    void delete_at_end()
    {
        if (head == NULL)
            return;

        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = head;
            delete toDelete;
        }
    }

    void delete_at_pos(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 0)
        {
            delete_at_beg();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};