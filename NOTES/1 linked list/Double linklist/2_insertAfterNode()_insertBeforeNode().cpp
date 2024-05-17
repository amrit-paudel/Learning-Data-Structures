

#include<iostream>

using namespace std;

class Node{
    public:
    int num;
    Node* nextNodePtr;
    Node* prevNodePtr;

    Node(int num){
        this->num=num;
        this->nextNodePtr = NULL;
        this->prevNodePtr = NULL;
    }

    void displayData(){
        cout<<this->num<<endl;
    }
};

class DoublyLinkedlist{
    private:
    Node* firstNode;
    
    public:
    DoublyLinkedlist(){
        this->firstNode = NULL;
    }

    // insertAtBeginning() method to insert node at beginning
    void insertAtBeginning(int num){
        Node* newNode = new Node(num);
        if(firstNode==NULL){
            firstNode = newNode;
            return;
        }

        newNode->nextNodePtr = firstNode;
        firstNode->prevNodePtr = newNode;
        firstNode = newNode;

    }


    // displayData() method to display the data of the node
    void displayData(){
        Node* temp = firstNode;

        while(temp!=NULL){
            temp->displayData();
            temp = temp->nextNodePtr;
        }
    }


    // method to insert a node after a specified node
    void insertBeforeNode(int key,int num){
        Node* temp = firstNode;
        Node* newNode = new Node(num);

        while(temp->num != key){
            temp=temp->nextNodePtr;
        }
        
        
        newNode->nextNodePtr = temp->nextNodePtr;
        temp->nextNodePtr->prevNodePtr = newNode;

        newNode->prevNodePtr = temp;
        temp->nextNodePtr = newNode;
        // See above unlike in singly linked list in double linked list
        // we have to do much more pointer operations
        // may be confusing
        // for simplicity
        // visualize the diagram shown in copy

    }

    // method to insert a node before a specified node
    void insertAfterNode(int key, int num){
        Node* temp = firstNode;
        Node* newNode = new Node(num);

        while(temp->num != key){
            temp = temp->nextNodePtr;
        }

        temp->prevNodePtr->nextNodePtr = newNode;
        newNode->prevNodePtr = temp->prevNodePtr;

        newNode->nextNodePtr = temp;
        temp->prevNodePtr = newNode;
        // See above unlike in singly linked list in double linked list
        // we have to do much more pointer operations
        // may be confusing
        // for simplicity
        // visualize the diagram shown in copy

    }
};

int main(){
    DoublyLinkedlist dllobj;
    // dllobj : doubly linkedlist object

    dllobj.insertAtBeginning(10);
    dllobj.insertAtBeginning(20);
    dllobj.insertAtBeginning(30);
    dllobj.insertAtBeginning(40);
    dllobj.insertAtBeginning(50);

    dllobj.insertAfterNode(30,31);
    dllobj.insertBeforeNode(30,29);


    dllobj.displayData();


}