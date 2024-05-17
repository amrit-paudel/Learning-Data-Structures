

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
        newNode->nextNodePtr = firstNode;
        firstNode = newNode;
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

    // Making this function so that .peek() could work down in stack class
    // basically all I need to do is return the first node

    Node* getFirstNode(){
        Node* tempNode = firstNode;
        return tempNode;
    }
};

// Now Implementing stack from the linked list
// linklist implemented stack will have
// .push()
// .pop()
// .isEmpty()
// .peek()
// but I guess it wont have .isFull() method

class Stack{
    // unlike in previous here
    // we do not need any size
    // since we are implementing using
    // linked list
    private:
    Linklist* stackll;

    public:

    Stack(){
        stackll = new Linklist();
    }

    ~Stack(){
        delete stackll;
    }

    void push(int item){
        stackll->insertAtBeginning(item);
    }

    void pop(){
        stackll->deleteFromBeginning();
    }

    int peek(){
        return stackll->getFirstNode()->data;
    }

    bool isEmpty(){
        return ( stackll->getFirstNode() == NULL );
    }





};

int main(){
    Linklist ll;
    ll.insertAtBeginning(10);
    ll.insertAtBeginning(30);
    ll.insertAtBeginning(40);
    ll.insertAtBeginning(50);
    ll.insertAtBeginning(60);

   // ll.displayData();

   Stack stackobj;
   stackobj.push(10);
   stackobj.push(20);
   stackobj.push(30);
   stackobj.push(40);

   cout<<stackobj.peek()<<endl;

   stackobj.pop();
   cout<<stackobj.peek()<<endl;
}