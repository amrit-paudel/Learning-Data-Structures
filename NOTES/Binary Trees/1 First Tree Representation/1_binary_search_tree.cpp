
#include<iostream>

using namespace std;

// we will make class of node type
// we know that each node will have
/*
 1) data of any type
 2) rightChildPtr
 3) left ChildPtr
*/


class Node{
    public:

    int num;
    Node* rightChildPtr;
    Node* leftChildPtr;

    Node( int num ){
        this->num = num;
        this->rightChildPtr = NULL;
        this->leftChildPtr = NULL;
    }

    // display method to display the data inside the Node
    void displayNodeData(){
        cout<<this->num;
    }

};


// Now we will make a tree class
class Tree{
    private:
    Node* rootNode = NULL;     // a tree must have a root node, we can access the whole tree by root node
    // it is the most important thing in the tree
    
    int globalSpace = 5;
    
    // this data is for printTree() method below

    public:
    // method to insert the new node
    /*
    void insert( int num ){
        Node* newNode = new Node(num);

        if( this->rootNode == NULL ){
            this->rootNode = newNode;
        }
        else{
            Node* currentNode = this->rootNode;  // first we will start from root node, and as we 
            // move along the tree to insert the data inright location the currentNode will be different
            Node* parentNode;

            while(true){
                parentNode = currentNode;

                if( num <= currentNode->num ){    // if the data to be inserted is less than or 
                //equal to the data in currentNode we want to mmove towards left to insert new node
                    currentNode = currentNode->leftChildPtr;
                    if( currentNode == NULL ){
                        parentNode->leftChildPtr = newNode;
                        return;
                    }
                }
                else{   // else we want to move right from root node to insert the new node
                    currentNode = currentNode->rightChildPtr;
                    if( currentNode == NULL ){
                        parentNode->rightChildPtr = newNode;
                        return;
                    }
                }
            }
        }

    }
    */

   // this one seems not natural, so lets try another one

   void insert( int num ){
       
       Node* newNode = new Node(num);

       if( this->rootNode == NULL ){
           this->rootNode = newNode;
           cout<<"Value inserted as root node"<<endl;
       }
       else{

           Node* currentNode = this->rootNode;        //lets change the name to currentRootNode

           while( currentNode != NULL ){ 

               if( ( newNode->num < currentNode->num ) && ( currentNode->leftChildPtr == NULL ) ){   
                   currentNode->leftChildPtr = newNode;
                   //cout<<"New node is added to left"<<endl;
                   break;
                   // this break is very essential here
                   // after adding the new node we break out of loop
                   // and when another .insert() is called from main
                   // than loop runs again
               }

               else if( ( newNode->num < currentNode->num ) && ( currentNode->leftChildPtr != NULL ) ){
                   currentNode = currentNode->leftChildPtr;
                   
                   //// simple currentNode lai left tira move garaidinae
               }

               else if( ( newNode->num > currentNode->num ) && ( currentNode->rightChildPtr == NULL ) ){
                   currentNode->rightChildPtr = newNode;
                   //cout<<"New node is added to the right"<<endl;
                   break;
               }
               else if ( ( newNode->num > currentNode->num ) && ( currentNode->rightChildPtr != NULL ) ){
                   currentNode = currentNode->rightChildPtr;
                   
                   // simple currentNode lai right tira move garaidinae
               }

           }
       }
   }


   // Method to get the root node
   Node* getRootNode(){
       return this->rootNode;
   }

   // A method to print the tree in cmd, just to visually observe the tree
   void printTree( Node* currNode, int space ){
       if( currNode == NULL ){   // base case for recurssion
           return;  
       }
       else{
           space = space + this->globalSpace;
           
           printTree( currNode->rightChildPtr , space );  // print value of right Node from current node
           
           cout<<endl;

           for( int i=this->globalSpace; i<space; i++ ){
               cout<<" ";
           }
           cout<<currNode->num<<endl;                    // Print the current value

           printTree( currNode->leftChildPtr , space );  // print the value of left node from current node
       }

    // this print tree is not standard function
    // this is just for our simplicity and better visualization
    // here we must supply the root node of tree
   }




    

};


int main(){
    Tree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(9);
    tree.insert(11);
    tree.insert(29);
    tree.insert(31);
    


    tree.printTree( tree.getRootNode() , 5 );
}