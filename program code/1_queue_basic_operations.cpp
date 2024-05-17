#include <iostream>
#include <vector>

// don't follow other materials
// all the methods written here are correct

using namespace std;

class Queue
{

private:
    int queueSize;
    int front;
    int rear;
    vector<int> queueVector;

public:
    Queue(int size)
    {
        queueSize = size;
        front = 0;
        rear = -1;
        queueVector.resize(queueSize);
    }

    // .isEmpty() This method checks if the queue is empty or not
    bool isEmpty()
    {
        return ((rear == -1 && front == 0) || front>rear ) ;
    }

    //.isFull()  This method checks if the queue is full or not
    bool isFull()
    {
        return (front == 0 && (rear == queueSize - 1));
    }

    // enqueue() This method adds the item in the queue
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is already full" << endl;
            return;
        }

        queueVector[++rear] = item;
    }

    // dequeue  This method removes the item from the front
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl; 
            return;
        }
        if (front == rear)  /* A good programmer must be aware of these cases, these are the sources of most of the bugs */
        {
            front = 0;
            rear = -1;
        } /* Queue has only one element, so we reset the queue after deleting it. */

        front++;
    }

    int peek(){
        if(isEmpty()){cout<<"Queue is empty"<<endl;}
        return queueVector[front];
    }
};

int main(){
    Queue queueobj(4);

    queueobj.enqueue(10); // This is our first item
    queueobj.enqueue(20);
    queueobj.enqueue(30);
    queueobj.enqueue(40);

    cout<<queueobj.peek()<<endl;
    
    queueobj.dequeue();
    cout<<queueobj.peek()<<endl;
}