


#include<iostream>

using namespace std;

// First lets make a node class
class Node{
    public:
    int num;
    Node* nextNodePtr;

    Node(int num){
        this->num=num;
        this->nextNodePtr=NULL;
    }

    void displayData(){
        cout<<this->num<<endl;
    }
};


// lets make a Circular linkedlist class

class linkedList {
    private:
    Node* firstNode;

    public:
    linkedList(){
        this->firstNode=NULL;
    }

    bool isEmpty(){

        return firstNode == NULL;
    }

    void displayData(){

        Node* tempNode = firstNode;

        do
        {
            tempNode->displayData();
            tempNode=tempNode->nextNodePtr;
        } while (tempNode!=firstNode);
        

    }


    // Method to insert node at the beginning of circular linked list
    void insertAtBeginning(int num){
        Node* tempNode = new Node(num);
        if(firstNode == NULL){
            this->firstNode = tempNode;
            firstNode->nextNodePtr = firstNode;
            return;
        }

        Node* temp = firstNode;
        while(temp->nextNodePtr!=firstNode){
            temp=temp->nextNodePtr;
        }

        temp->nextNodePtr = tempNode;
        tempNode->nextNodePtr = firstNode;
        firstNode = tempNode;

    }

    // Method to search any node by the provided key value
    // Here in this case we will return a node
    Node* search(int key){

        Node* temp = firstNode;
        while(temp->num!=key){
            temp=temp->nextNodePtr;
        }
        return temp;
    }

    // Inserting a node at any specified position
    // Here we will have two methods
    // 1) insertBefore() and 
    // 2) insertAfter()
    

    // insertBefore() method
    void insertBefore(int key,int num2){
        Node* newNode = new Node(num2);

        Node* temp1 = firstNode;

        while(temp1->num!=key){
            temp1=temp1->nextNodePtr;
        }

        newNode->nextNodePtr = temp1->nextNodePtr;
        temp1->nextNodePtr = newNode;

    }


    // insertAfter() method

    void insertAfter(int key,int num2){
        Node* newNode = new Node(num2);

        Node* temp = firstNode;
        while(temp->nextNodePtr->num != key){
            temp = temp->nextNodePtr;
        }

        newNode->nextNodePtr = temp->nextNodePtr;
        temp->nextNodePtr = newNode;
    }





};

int main(){
    linkedList circularlinkedlistobj;

    circularlinkedlistobj.insertAtBeginning(10);
    circularlinkedlistobj.insertAtBeginning(20);
    circularlinkedlistobj.insertAtBeginning(30);
    circularlinkedlistobj.insertAtBeginning(40);
    circularlinkedlistobj.insertAtBeginning(50);
    

    //circularlinkedlistobj.displayData();
    
   // Node* searchNode = circularlinkedlistobj.search(40);
   // searchNode->displayData();

   circularlinkedlistobj.insertBefore(40,39);
   circularlinkedlistobj.insertAfter(40,41);

   circularlinkedlistobj.displayData();

}
