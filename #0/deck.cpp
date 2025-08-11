#include <iostream>
using namespace std;
int front = -1;
int rear = -1;
int max_size = 100;
int q[100];

void insert_front(int a)
{
    if (front == 0 && rear == max_size - 1 || front == rear + 1)
    {
        cout << "Overflow!" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    if (front == 0)
    {
        front = max_size - 1;
    }
    else
    {
        front = front - 1;
    }
    q[front] = a;
}
void insert_rear(int b)
{
    if ((rear + 1) % max_size == front)
    {
        cout << "Queue Overflow." << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear=0;
    }
    else
    {
        rear = (rear + 1) % max_size;
    }
    q[rear] = b;
}
void delete_front()
{
    if (front == -1)
    {
        cout << "Queue underflow." << endl;
        return;
    }
    int element = q[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % max_size;
    }
    cout << "deleted:" << element << endl;
}

void delete_rear()
{
    if (front == -1)
    {
        cout << "underflow." << endl;
        return;
    }
    int val = q[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return ;
    }
    if (rear == 0)
    {
        rear = max_size - 1;
    }
    else
    {
        rear--;
    }
    cout << "deleted:" << val << endl;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    int i = front;
    while (true)
    {
        cout << q[i] << " ";
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % max_size;
    }
    cout << endl;
}
int main()
{
    insert_front(10);
    insert_front(20);
    insert_front(30);
    insert_rear(40);
    insert_rear(50);
    delete_front();
    delete_rear();
    display();

    return 0;
}