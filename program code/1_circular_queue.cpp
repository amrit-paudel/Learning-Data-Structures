

#include<iostream>
#include<vector>

using namespace std;

class CircularQueue{
    private:
    int queueSize;
    int front;
    int rear;
    vector<int> queueVector;

    public:
    CircularQueue(int size){
        this->queueSize = size;
        queueVector.resize(this->queueSize);
        front = 0;
        rear = -1;
    }

    // checks if the queue is full
    bool isFull(){
        if  ( front==0 && rear == queueSize-1 ) {
            return true;
        }
        else{
            return false;
        }
    } 

    // checks if the queue is empty
    bool isEmpty(){
        return ( ( front==0 && rear==-1 ) || front > rear );
    }

    // adds items in the queue
    void enQueue(int item){
        if(isFull()){
            cout<<"Queue is already full"<<endl;
        }
        else{
            rear = (rear + 1) % queueSize ;
            queueVector[rear] = item;
        }
    }

    // removes the item from the queue
    void deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        
        // This happens when there is only one
        // item in the queue
        else if( front == rear ){ 
            front = 0;
            rear = -1;
        }
        else{
            front = ( front + 1 ) % queueSize ; 
        }
    }

    void displayItems(){
        for(int i=0;i<= queueSize -1;i++){
            cout<<queueVector[i]<<endl;
        }
    }
};

int main(){ 

    CircularQueue cqobj(5); // cqobj: read as, Circular Queue Object
    
    cqobj.enQueue(10);
    cqobj.enQueue(20);
    cqobj.enQueue(30);
    cqobj.enQueue(40);
    cqobj.enQueue(50);

   // cqobj.displayItems();
   // this display function must give all the items inserted in the circular queue

    cqobj.deQueue();
    cqobj.deQueue();
    // here we remove two items from the queue
    // now first two spaces became empty
    // Now the queue looks something like this
    // ... ... 30 40 50
    // The inability to use those two empty memory blocks was the 
    // defect of linear queue
    // Now circular queue solves that problem


    cqobj.enQueue(100);
    cqobj.enQueue(200);
    // now those two empty memory blocks must be filled by these two
    // which must be clearly shown by the display function below
    // Now the queue must look like
    // 100 200 30 40 50

    cqobj.displayItems();



}