
// A Node class
class Node {
    constructor(item) {
        this.item = item;
        this.nextNode = null;
    }

    // to display the data
    display() {
        console.log(this.item);
    }
};


// A linklist class
class Linklist {
    constructor() {
        this.firstNode = null;
    }

    // checks if the linklist is empty
    isEmpty() {
        return this.firstNode === null;
    }

    // method to insert a node at beginning
    insertAtBeginning(item) {
        const newNode = new Node(item);
        newNode.nextNode = this.firstNode;
        this.firstNode = newNode;
    }

    // method to insert a node at end
    insertAtEnd(item) {
        const newNode = new Node(item);
        if (this.isEmpty()) {
            this.insertAtBeginning(item);
        }
        else {


            let tempNode = this.firstNode;
            while (tempNode.nextNode !== null) {
                tempNode = tempNode.nextNode;
            }

            newNode.nextNode = tempNode.nextNode;
            tempNode.nextNode = newNode;
        }
    }

    // method to delete a node from beginning
    deleteFromBeginning() {
        if(this.isEmpty()){
            console.log("Linklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            this.firstNode = this.firstNode.nextNode;
            // Unlike in c++ we don't need to delete the 
            // memory of tempNode object
            // In JS there is a thing called
            // garbage collection, which auto
            // frees the memory once it finds 
            // that memory isn't being used
        }
    }

    // method to delete a node at end
    deleteFromEnd() {
        if(this.isEmpty()){
            console.log("Linklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            let prevTempNode = null;
            while (tempNode.nextNode !== null) {
                prevTempNode = tempNode;
                tempNode = tempNode.nextNode;
            }
            prevTempNode.nextNode = tempNode.nextNode;
        }

    }


    // to insert a new node after a node
    insertAfter(key,item){
        const newNode = new Node(item);
        let tempNode = this.firstNode;

        while( tempNode.nextNode.item !== key ){
            tempNode = tempNode.nextNode;
        }
        newNode.nextNode = tempNode.nextNode;
        tempNode.nextNode = newNode;


    }

    // to insert a new node before a node
    insertBefore( key,item ){
        const newNode = new Node(item);
        let tempNode = this.firstNode;
        while( tempNode.item !== key ){
            tempNode = tempNode.nextNode;
        }
        newNode.nextNode = tempNode.nextNode;
        tempNode.nextNode = newNode;
    }

    // to delete a node after a specified node
    deleteAfter(key){
        if( this.firstNode.nextNode.item === key ){
            this.deleteFromBeginning();
        }
        else{
            let tempNode = this.firstNode;
            let prevTempNode = null;
    
            while( tempNode.nextNode.item !== key ){
                prevTempNode = tempNode;
                tempNode = tempNode.nextNode;
            }
    
            prevTempNode.nextNode = tempNode.nextNode;
            // here we take out tempNode from the
            // linklist
            // Now if were implementing linklist
            // in a low-level language like c++
            // we need to free that memory occupied
            // by tempNode
            // but here in JS once the garbage
            // collector finds that memory isn't being used
            // it releases that memory
        }


    }


    // to delete a node before a specified node
    deleteBefore(  key ){
        let temp = this.firstNode;
        while(temp.item !== key){
            temp = temp.nextNode;
        }
        if( temp.nextNode.nextNode === null ){
            this.deleteFromEnd();
        }
        else{
            let tempNode = this.firstNode;

            while(tempNode.item !== key){
                tempNode = tempNode.nextNode;
            }
    
            tempNode.nextNode = tempNode.nextNode.nextNode;
        }


    }




    // a method to display the linklist
    display() {
        let tempNode = this.firstNode;

        while (tempNode !== null) {
            tempNode.display();
            tempNode = tempNode.nextNode;
        }
    }

};

const linklist = new Linklist();

linklist.insertAtBeginning(10);
linklist.insertAtBeginning(20);
linklist.insertAtBeginning(30);
linklist.insertAtBeginning(40);

linklist.insertAtEnd(5);
linklist.insertAtEnd(4);
linklist.insertAtEnd(3);

linklist.insertAfter(30,31);
linklist.insertBefore(30,29);
/*
linklist.deleteFromBeginning();
linklist.deleteFromEnd();

linklist.deleteAfter(5);
linklist.deleteBefore(29);
*/

/*
linklist.deleteAfter(31);
linklist.deleteBefore(4);
*/

linklist.display();