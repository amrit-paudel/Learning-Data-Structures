
#include <iostream>

using namespace std;

class Node
{
public:
    int coeff;
    int exponent;
    Node *nextNodePtr;

    Node(int coeff, int exponent)
    {
        this->coeff = coeff;
        this->exponent = exponent;

        this->nextNodePtr = NULL;
    }
};

class Linklist
{
private:
    Node *firstNode;

public:
    Linklist()
    {
        this->firstNode = NULL;
    }

    // to insert node at beginning
    void insertAtBeginning(int coeff, int exponent)
    {
        Node *newNode = new Node(coeff, exponent);
        if (firstNode == NULL)
        {
            this->firstNode = newNode;
        }
        else
        {
            newNode->nextNodePtr = this->firstNode;
            this->firstNode = newNode;
        }
    }

    Node *getFirstNode()
    {
        return this->firstNode;
    }


    Linklist operator+(Linklist poly)
    {
        Linklist result;
        Node *tempNode1 = this->firstNode;
        Node *tempNode2 = poly.getFirstNode();
        
        int count = 0;
        while (tempNode1 != NULL || tempNode2 != NULL)
        { count++;
            if ((tempNode1->exponent) < (tempNode2->exponent))
            {
                result.insertAtBeginning(tempNode2->coeff, tempNode2->exponent);
            }
            else if ((tempNode1->exponent) > (tempNode2->exponent))
            {
                result.insertAtBeginning(tempNode1->coeff, tempNode1->exponent);
            }
            else if ((tempNode1->exponent) == (tempNode2->exponent))
            {
                result.insertAtBeginning((tempNode1->coeff+tempNode2->coeff), tempNode1->exponent);
            }
            tempNode1 = tempNode1->nextNodePtr;
            tempNode2 = tempNode2->nextNodePtr;
            
        } 
        result.display();
        if (tempNode1 != NULL)
        {
            while (tempNode1 != NULL)
            {
                result.insertAtBeginning(tempNode1->coeff, tempNode1->exponent);
                tempNode1 = tempNode1->nextNodePtr;
            }
        }
        else if (tempNode2 != NULL)
        {
            while (tempNode2 != NULL)
            {
                result.insertAtBeginning(tempNode2->coeff, tempNode2->exponent);
                tempNode2 = tempNode2->nextNodePtr;
            }
        }

      /*  // analyzing final result linklist
        Node* tempNode3 = result.getFirstNode();
        Node* prevTempNode;

        while(tempNode3 != NULL){
            prevTempNode = tempNode3;
            tempNode3 = tempNode3->nextNodePtr;

            if( prevTempNode->exponent == tempNode3->exponent ){
                prevTempNode->coeff = prevTempNode->coeff + tempNode3->coeff;
                prevTempNode->nextNodePtr = tempNode3->nextNodePtr;
                
                delete tempNode3;
            }
        }*/

        return result;

    }

    void display(){
        Node* tempNode = this->firstNode;
        while( tempNode != NULL ){
            cout<<tempNode->coeff<<"x"<<tempNode->exponent<<" ";
            tempNode = tempNode->nextNodePtr;
        }
    }
};

int main()
{
    Linklist poly1; // 5x2 + 4x + 2
   
    
    poly1.insertAtBeginning(2,0);
    poly1.insertAtBeginning(4,1);
     poly1.insertAtBeginning(5,2);

    Linklist poly2; // 6x3 + 4x2 + 3x + 5
   
    
    
    poly2.insertAtBeginning(5,0);
    poly2.insertAtBeginning(3,1);
    poly2.insertAtBeginning(4,2);
     poly2.insertAtBeginning(6,3);

    //poly2.display();

    Linklist resultPoly;

    resultPoly = poly1+poly2;
    resultPoly.display();
}