

#include<iostream>

using namespace std;

class Node{
    public:

    int num;
    Node* nextNodePtr;
    Node* prevNodePtr;

    Node(int num){
        this->num=num;
        this->nextNodePtr=NULL;
        this->prevNodePtr=NULL;
    }

    void displayData(){
        cout<<this->num<<endl;
    }

};

class DoublyLinkList{
    private:
    Node* firstNode;

    public:
    
    DoublyLinkList(){
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


    // insertAtEnd() method to insert node at the end
    void insertAtEnd(int num){
        Node* newNode = new Node(num);

        Node* temp = firstNode;
        while(temp->nextNodePtr!=NULL){
            temp = temp->nextNodePtr;
        }
        
        newNode->prevNodePtr = temp;
        temp->nextNodePtr = newNode;

    }
};


int main(){
    DoublyLinkList dllobj;
    // dllobj : short form for double linklist object

    dllobj.insertAtBeginning(10);
    dllobj.insertAtBeginning(20);
    dllobj.insertAtBeginning(30);
    dllobj.insertAtBeginning(40);

    dllobj.insertAtEnd(9);
    dllobj.insertAtEnd(8);

    dllobj.displayData();

    
}