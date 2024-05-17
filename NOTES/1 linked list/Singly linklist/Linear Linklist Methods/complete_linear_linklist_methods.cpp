

// look at these methods
// especially that .deleteAfter()

#include<iostream>

using namespace std;

class Node{
    public:
    int num;
    Node* nextNodePtr;

    Node(int num){
        this->num = num;
        this->nextNodePtr = NULL;
    }

    void display(){
        cout<<this->num<<endl;
    }
};

class Linklist{
    private:
    Node* firstNode;

    public:
    Linklist(){
        this->firstNode = NULL;
    }

    // to insert node at beginning
    void insertAtBeginning(int item){
        Node* newNode = new Node(item);
        if( firstNode == NULL ){
            firstNode = newNode;
        }
        else{
            newNode->nextNodePtr = firstNode;
            firstNode = newNode;
        }
    }

    // to display the nodes
    void display(){
        Node* tempNode = firstNode;
        while( tempNode != NULL ){
            tempNode->display();
            tempNode = tempNode->nextNodePtr;
        }
    }

    // to insert a node before a node
    void insertBefore(int key, int item){
        Node* newNode = new Node(item);
        Node* tempNode = firstNode;

        while(tempNode->num != key){
            tempNode = tempNode->nextNodePtr;
        }

        newNode->nextNodePtr = tempNode->nextNodePtr;
        tempNode->nextNodePtr = newNode;
    }

    // to delete a node after a node
    void deleteAfter(int key){
        Node* prevTempNode;
        Node* tempNode = firstNode;

        while( tempNode->nextNodePtr->num != key ){
            prevTempNode = tempNode;
            tempNode = tempNode->nextNodePtr;
        }
        if( tempNode == firstNode ){
            this->deleteFromBeginning();             // this one is super important to consider
            // finding conditions like this one is a sign of experienced programmer
        }
        else{
         prevTempNode->nextNodePtr = tempNode->nextNodePtr;
         delete tempNode;
        }

    }

    // to remove a node before a node
    void removeBefore(int key){
        Node* tempNode = firstNode;
        while(tempNode->num!=key){
            tempNode = tempNode->nextNodePtr;
        }
        Node* temp = tempNode->nextNodePtr;
        tempNode->nextNodePtr = tempNode->nextNodePtr->nextNodePtr;
        delete temp;
    }



    // to remove a first node
    void deleteFromBeginning(){
        Node* tempNode = firstNode;
        firstNode = firstNode->nextNodePtr;
        delete tempNode;
    }

    // to remove a last node
    void deleteFromLast(){
        Node* tempNode = firstNode;
        Node* prevTempNode;
        while( tempNode->nextNodePtr != NULL ){
            prevTempNode = tempNode;
            tempNode = tempNode->nextNodePtr;
        }
        prevTempNode->nextNodePtr = tempNode->nextNodePtr;
        delete tempNode;

    }
};

int main(){
    Linklist llobj;
    llobj.insertAtBeginning(10);
    llobj.insertAtBeginning(20);
    llobj.insertAtBeginning(30);
    llobj.insertAtBeginning(40);
    llobj.insertAtBeginning(50);

    

    llobj.insertBefore(30,29);
    llobj.insertBefore(20,19);

   

    llobj.deleteAfter(40);
    llobj.deleteFromLast();

    llobj.removeBefore(20);
    llobj.removeBefore(30);

    llobj.display();

    
}