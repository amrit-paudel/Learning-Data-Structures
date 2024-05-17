

// Implementation of a linked list

// We need a node class or a list class
// and a linkedlist class

// we will implement three basic member function of a linked list

// insertFirst()
// removeFirst()
// displayList()

#include <iostream>

using namespace std;


// many people make node as structures
// but making class and putting everything under
// public is same as structures

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
        cout << "Data : " << this->num << endl;
    }
};

class Linklist
{ // visualize it initially a Linklist would contain
  // only one node which next pointer points to null

private:
    Node *firstNode;  // a pointer variable of node type

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

        while(tempNode!=NULL){
            tempNode->displayNode();
            tempNode=tempNode->nextNodePtr;
        }

        // so in display list function we have two conditions through which we can iterate
        // first one is while( !tempNode==NULL ); here loop will close at last node only

        // and second one is while( !tempNode->nextNodePtr==NULL )
        // if we had done second one than second last node ko pani print hudainaa
        // since loop will close from second last node



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

    linklistobj.removeFirst();
    linklistobj.removeFirst();
    linklistobj.removeFirst();

    linklistobj.displayList();
}