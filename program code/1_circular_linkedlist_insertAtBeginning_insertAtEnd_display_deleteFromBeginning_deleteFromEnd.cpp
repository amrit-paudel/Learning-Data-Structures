


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

    void insertAtEnd(int num){

        if(firstNode==NULL){
            this->insertAtBeginning(num);
        }

        Node* tempNode = new Node(num);
        Node* temp = firstNode;
        while(temp->nextNodePtr!=firstNode){
            temp = temp->nextNodePtr;
        }
        temp->nextNodePtr = tempNode;
        tempNode->nextNodePtr = firstNode;
    }

    void removeFromEnd(){
        Node* temp1 = firstNode;
        Node* temp2 = firstNode;

        while(temp1->nextNodePtr!=firstNode){
            temp2 = temp1;
            temp1 = temp1->nextNodePtr;

        }

        temp2->nextNodePtr = temp1->nextNodePtr;

        delete temp1;
    }



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

    void removeFromBeginning(){
        Node* temp = firstNode;
        Node* temp1 = firstNode;
       /* 
        Node* temp = firstNode;
        firstNode = temp->nextNodePtr;
        delete temp;

        yo gardaa mildainaa, 
        paxi display gardaa infinite loop chalxaaa
        
        */
       while(temp->nextNodePtr!=firstNode){
           temp = temp->nextNodePtr;
       }
       firstNode = firstNode->nextNodePtr;
       temp->nextNodePtr = firstNode;

       delete temp1;
    }


};

int main(){
    linkedList circularlinkedlistobj;

    circularlinkedlistobj.insertAtBeginning(10);
    circularlinkedlistobj.insertAtBeginning(20);
    circularlinkedlistobj.insertAtBeginning(30);
    circularlinkedlistobj.insertAtBeginning(40);
    circularlinkedlistobj.insertAtBeginning(50);

  //  circularlinkedlistobj.insertAtEnd(5);

  //  circularlinkedlistobj.removeFromEnd();

  circularlinkedlistobj.removeFromBeginning();

    circularlinkedlistobj.displayData();
}
