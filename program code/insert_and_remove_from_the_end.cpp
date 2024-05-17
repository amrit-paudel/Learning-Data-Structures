

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


// lets make a linkedlist class

class linkedList {
    private:
    Node* firstNode;

    public:
    linkedList(){
        this->firstNode=NULL;
    }

    bool isEmpty(){
        return firstNode==NULL;
    }

    void displayData(){
        Node* temp=firstNode;

        while(temp!=NULL){
            temp->displayData();
            temp=temp->nextNodePtr;
        }
    }

    void insertAtEnd(int num){
        // first lets make a node to insert
        Node* tempNode = new Node(num);

        Node* tempFirstNode = firstNode;
        while(tempFirstNode->nextNodePtr!=NULL){
            tempFirstNode = tempFirstNode->nextNodePtr;
        }

        tempNode->nextNodePtr = tempFirstNode->nextNodePtr;
        tempFirstNode->nextNodePtr = tempNode;
        
    }

    void removeFromEnd(){
        Node* tempNode1 = firstNode;
        Node* tempNode2 = firstNode;
        
        while(tempNode1->nextNodePtr!=NULL){
            tempNode2 = tempNode1;
            tempNode1 = tempNode1->nextNodePtr;

        }
        //At the end of this loop
        // tempNode1 chai last ko NULL node vanda agadi, second last 
        // node samma pugxaa
        // tempNode2 chai third last samma pugxaa

        tempNode2->nextNodePtr = tempNode1->nextNodePtr;

        delete tempNode1;
    }



    void insertAtBeginning(int num){
        Node* tempNode = new Node(num);

        tempNode->nextNodePtr = firstNode;
        firstNode = tempNode;
    }


};

int main(){
    linkedList linkedlistobj;

    linkedlistobj.insertAtBeginning(10);
    linkedlistobj.insertAtBeginning(20);
    linkedlistobj.insertAtBeginning(30);
    linkedlistobj.insertAtBeginning(40);
    linkedlistobj.insertAtBeginning(50);

   // linkedlistobj.insertAtEnd(60);

   linkedlistobj.removeFromEnd();

    linkedlistobj.displayData();
}
