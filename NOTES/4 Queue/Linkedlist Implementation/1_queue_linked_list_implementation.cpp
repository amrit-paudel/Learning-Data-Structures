

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* nextNodePtr;

    Node(int data){
        this->data = data;
        nextNodePtr = NULL;
    }

    void displayItem(){
        cout<<this->data<<endl;
    }
};

class Linklist{
    private:
    Node* firstNode;

    public:
    // constructor 
    Linklist(){
        this->firstNode = NULL;
    }
    
    // destructor
    ~Linklist(){
        Node* currentNode = firstNode;
        Node* prevCurrentNode;

        while( currentNode!=NULL ){
            prevCurrentNode = currentNode;
            currentNode = currentNode->nextNodePtr;
            delete prevCurrentNode;
        }
    }

    void insertAtBeginning(int item){
        Node* newNode = new Node(item);
        if(isEmpty()){ firstNode = newNode; return; }
        newNode->nextNodePtr = firstNode;
        firstNode = newNode;
    }

    bool isEmpty(){
        return firstNode == NULL;
    }

    void insertAtLast(int item){

        if(isEmpty()){
            insertAtBeginning(item); return;
        }

        Node* newNode = new Node(item);
        Node* tempNode = firstNode;

        while(tempNode->nextNodePtr!=NULL){
            tempNode = tempNode->nextNodePtr;
        }

        newNode->nextNodePtr = tempNode->nextNodePtr;
        tempNode->nextNodePtr = newNode;
    }

    void deleteFromBeginning(){
        Node* tempNode = firstNode;
        firstNode = firstNode->nextNodePtr;
        delete tempNode;
    }

    void displayData(){
        Node* tempNode = firstNode;
        while( tempNode!=NULL ){
            tempNode->displayItem();
            tempNode = tempNode->nextNodePtr;
        }
    }

    // Making this function so that .peek() could work down in stack / Queue class
    // basically all I need to do is return the first node

    Node* getFirstNode(){
        Node* tempNode = firstNode;
        return tempNode;
    }
};

class Queue{
    private:
    Linklist* queuell;
    
    public:
    Queue(){
        queuell = new Linklist();
    }

    bool isEmpty(){
        return queuell->isEmpty();
    }

    void enQueue(int item){
        queuell->insertAtLast(item);
    }

    void deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl; return;
        }
        queuell->deleteFromBeginning();
    }

    int peek(){
        return queuell->getFirstNode()->data;
    }

    void displayData(){
        queuell->displayData();
    }
};

int main(){
    Queue queueobj;
    queueobj.enQueue(10);
    queueobj.enQueue(20);
    queueobj.enQueue(30);
    queueobj.enQueue(40);
    queueobj.enQueue(50);

    queueobj.deQueue();
    queueobj.deQueue();

    queueobj.displayData();

}