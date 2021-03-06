#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    string *arr;

    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        arr = new string[size];
    }

    bool isFull()
    {
        if ((rear + 1) & size == front)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == -1)
        {
            return true;
        }
        return false;
    }

    void Enqueue(string data)
    {
        if (isFull())
        {
            cout << "Queue OverFlow" << endl;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
            rear = (rear + 1) % size;
        }
        else
        {
            arr[rear] = data;
            rear = (rear + 1) % size;
        }
    }

    string Dequeue()
    {
        if (!isEmpty() && front != rear)
        {
            string value = arr[front];
            front = (front + 1) % size;
            cout<<"Your "<< value << " is ready"<<endl;
            return value;
        }
        else{
            front = rear = -1;
            cout<<"You have not ordered anything! Order First"<<endl;
        }
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Empty Queue";
        }
        else
        {
            int f = front;
            while (f != rear)
            {
                cout << arr[f] << " ";
                f = (f + 1) % size;
            }
        }
    }
};

int main()
{   
    int choice;
    string order;
    Queue myQueue;
    bool flag = true;
    while(flag){
        cout<<"Enter 1 to place order: "<<endl;
        cout<<"Enter 2 to get order: "<<endl;
        cout<<"Enter 3 to exit: "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter your order to place: ";
                cin>>order;
                myQueue.Enqueue(order);
                break;
            case 2:
                myQueue.Dequeue();
                break;
            case 3:
                cout<<"Exit"<<endl;
                flag = false;
                break;
            default: 
                cout<<"Invalid input"<<endl;
                break;
        }
        cout<<endl;

    }

}