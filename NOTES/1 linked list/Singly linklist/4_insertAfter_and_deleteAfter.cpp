

// Implementation of a linked list

// We need a node class or a list class
// and a linkedlist class

// we will implement three basic member function of a linked list

// insertFirst()
// removeFirst()
// displayList()

#include <iostream>

using namespace std;

class Node
{
public:
    int num;
    Node *nextNodePtr;

    Node(int num)
    { // the purpose of a constructor is to
      // initialize the data members inside the class
        this->num = num;

        nextNodePtr = NULL; // here we are just creating a single list
        // we are not linking here, so initially we are
        // setting the next pointer to null
    }

    void displayNode()
    {
        cout << this->num << endl;
    }
};

class Linklist
{ // think of it initially a Linklist would contain
  // only one node which next pointer points to null

private:
    Node *firstNode;

public:
    Linklist()
    {
        this->firstNode = NULL;
    }

    // also we may need to find out whether the linked list is empty or not
    // so lets add one method for that

    bool isEmpty()
    {
        return firstNode == NULL;
    }

    void insertFirst(int num)
    {
        Node *tempNode = new Node(num);
        tempNode->nextNodePtr = firstNode;
        firstNode = tempNode;
    }

    void removeFirst()
    {
        Node *tempNode = firstNode;
        // surumaa hami lae firstnode banaa ko and
        // tai first node vandaa agadi aaru nodes haru lai
        // logically link gardai gayaeko
        // here nodes are linked logically unlike physically like in array so
        // might feel like difficult at beginning

        firstNode = firstNode->nextNodePtr;
        // aba chai firstnode vanda exact pachadi ko node first node hunae vayo

        delete tempNode;
        // since tempNode maa previous firstnode ko memory xaa, so
        // yeslai delete operator lagaudaa memory release hunxaa
    }

    void displayList()
    {
        Node* tempNode = firstNode;
        // hamilae sidhai firstnode lai nai looping garaeko vayae ni hunthyo
        // but Linkedlist class maa firstNode is really important
        // displayList() function end vayae paxi firstNode -> nextNodePtr() maa NULL
        // aauxaa so further methods ko lagi firstNode () useless hunxaa
        // also displayList() paxi insertfirst() use garna paryo vannae pani mildainaa
        // since firstNode->nextNodePtr == NULL xaa, and Linkedlist empty xainaa

        while(tempNode->nextNodePtr!=NULL){
            tempNode->displayNode();
            tempNode=tempNode->nextNodePtr;
        }

        if(tempNode->nextNodePtr == NULL){   // if we hadn't added this than 10 won't get printed
            tempNode->displayNode();
        }


    }

    // to insert a node after a node
    void insertAfter(int key,int item){
        Node* newNode = new Node(item);

        Node* tempNode = firstNode;
        Node* tempNode1 = firstNode;
        while( tempNode->num!=key ){
            tempNode1 = tempNode;
            tempNode = tempNode->nextNodePtr;
        }
        newNode->nextNodePtr = tempNode;
        tempNode1->nextNodePtr = newNode;
    }

    // to delete a node after a given node
    void deleteAfter (int key){
        Node* tempNode = firstNode;
        Node* tempNode1 = firstNode;
        while( tempNode->nextNodePtr->num!=key ){
            tempNode1 = tempNode;
            tempNode = tempNode->nextNodePtr;
        }

        tempNode1->nextNodePtr = tempNode->nextNodePtr;
        delete tempNode;

    }


};

int main()
{
    Linklist linklistobj;
    linklistobj.insertFirst(10);
    linklistobj.insertFirst(20);
    linklistobj.insertFirst(30);
    linklistobj.insertFirst(40);
    linklistobj.insertFirst(50);
    linklistobj.insertFirst(60);

    linklistobj.insertAfter(50,51);
    linklistobj.deleteAfter(30);


    linklistobj.displayList();
}