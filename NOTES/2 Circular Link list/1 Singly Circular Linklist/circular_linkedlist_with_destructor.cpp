

#include<iostream>

using namespace std;

class Node{
    public:
    int value;
    Node* nextNodePtr;
   // Node* prevNodePtr;

    Node(int value){
        this->value = value;
        this->nextNodePtr = NULL;
       // this->prevNodePtr = NULL;
    }

    void display(){
        cout<<this->value<<"  ";
    }

};

class CircularLinklist{
    private:
    Node* firstNode;

    public:
    CircularLinklist(){
        this->firstNode = NULL;
    }

    // a destructor
    ~CircularLinklist(){
        Node* tempNode = firstNode;
        Node* lastNode;
        Node* prevTempNode;
        
        // lets first find out last node
        while(tempNode->nextNodePtr!=firstNode){
            tempNode = tempNode->nextNodePtr;
        } 
        lastNode = tempNode;
        tempNode = firstNode;
        
        while(tempNode!=lastNode){
            prevTempNode = tempNode;
            tempNode = tempNode->nextNodePtr;
            cout<<"From destructor ";prevTempNode->display();
            delete prevTempNode;
        }
        cout<<"From destructor lastnode ";lastNode->display();
        delete lastNode;

    }



    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        
        if(firstNode == NULL){
            firstNode = newNode;
            firstNode->nextNodePtr = firstNode;
        }
        else{
            Node* tempNode = firstNode;
            while( tempNode->nextNodePtr != firstNode ){
                tempNode = tempNode->nextNodePtr;
            }
            newNode->nextNodePtr = tempNode->nextNodePtr;
            tempNode->nextNodePtr  = newNode;
            firstNode = newNode;
        }
    }

    void removeFromBeginning(){
        if(firstNode == NULL){
            cout<<"Linked list is empty"<<endl;
        }
        else{
            Node* tempNode = firstNode;
            Node* firstNodeCopy = firstNode;
            while(tempNode->nextNodePtr!=firstNode){
                tempNode = tempNode->nextNodePtr;
            }

            tempNode->nextNodePtr = firstNode->nextNodePtr;
            firstNode = firstNode->nextNodePtr;

            delete firstNodeCopy;

        }
    }

    void display(){
        Node* tempNode = firstNode;

        do{
            tempNode->display();
            tempNode = tempNode->nextNodePtr;

        } while( tempNode!=firstNode );
    }
};

int main(){
    CircularLinklist cllobj; // cllobj : circular linklist object
    cllobj.insertAtBeginning(10);
    cllobj.insertAtBeginning(20);
    cllobj.insertAtBeginning(30);
    cllobj.insertAtBeginning(40);
    cllobj.insertAtBeginning(50);
    cllobj.insertAtBeginning(60);
    cllobj.insertAtBeginning(70);

 //  cllobj.display();
}