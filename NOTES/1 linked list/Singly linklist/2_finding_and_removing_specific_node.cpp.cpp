

#include<iostream>

using namespace std;

// first we make a node class
// for simplicity let our node only holds int data

class Node{
    public:
    int num;
    Node* nextNodePtr;

    Node(int num){
        this->num=num;
        this->nextNodePtr=NULL;
    }

    void displayNodeData(){
        cout<<"Num : "<<this->num<<endl;
    }
};

class Linklist{

    private:
    Node* firstNode;

    public:
    Linklist(){
        this->firstNode=NULL;
    }

    void insertFirst(int num){
        Node* temp = new Node(num);
        temp->nextNodePtr = firstNode;
        firstNode=temp;
    }

    void deleteFirst(){
        Node* temp = firstNode;
        firstNode=firstNode->nextNodePtr;
        delete temp;
    }

    void displaydata(){
        Node* tempNode = this->firstNode;

        while(tempNode!=NULL){
            tempNode->displayNodeData();
            tempNode=tempNode->nextNodePtr;
        }
    }



    // Method to find a specific node

    Node* findNode(int keyvalue){
        Node* temp = this->firstNode;

        while(temp->num!=keyvalue){
            temp=temp->nextNodePtr;
            if(temp==NULL){
                cout<<"Could not find node"<<endl;
                return 0;
            }
        }

        return temp;
    }
    

    // method to delete a node having specified key value
    void deleteNode(int keyvalue){
        Node* tempNode = this->findNode(keyvalue);
        Node* tempPreviousNode = firstNode;

        while(tempPreviousNode->nextNodePtr!=tempNode){
            tempPreviousNode = tempPreviousNode->nextNodePtr;
        }

        tempPreviousNode->nextNodePtr = tempNode->nextNodePtr;

        delete tempNode;

    }


};

int main(){
    Linklist linklistobj;

    linklistobj.insertFirst(10);
    linklistobj.insertFirst(20);
    linklistobj.insertFirst(30);
    linklistobj.insertFirst(40);
    linklistobj.insertFirst(50);
    linklistobj.insertFirst(60);
    linklistobj.insertFirst(70);
    linklistobj.insertFirst(80);

    cout<<"Before finding and removing 50"<<endl;
    linklistobj.displaydata();
    
    // finding a node
    Node* temp = linklistobj.findNode(50);
    
    // deleting a node
    linklistobj.deleteNode(temp->num);
    
    cout<<endl<<"After deleting a node"<<endl;
    linklistobj.displaydata();


}

