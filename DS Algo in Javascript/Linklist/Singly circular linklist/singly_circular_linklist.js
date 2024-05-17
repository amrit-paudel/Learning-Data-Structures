
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


// A Circularlinklist class
class Circularlinklist {
    constructor() {
        this.firstNode = null;
    }

    // checks if the Circularlinklist is empty
    isEmpty() {
        return this.firstNode === null;
    }

    // method to insert a node at beginning
    insertAtBeginning(item) {
        const newNode = new Node(item);
        if( this.isEmpty() ){
            this.firstNode = newNode;
            this.firstNode.nextNode = this.firstNode;
        }
        else{
            let tempNode = this.firstNode;
            while( tempNode.nextNode !== this.firstNode ){
                tempNode = tempNode.nextNode;
            }
            newNode.nextNode = tempNode.nextNode;
            tempNode.nextNode = newNode;
            this.firstNode = newNode;
        }
    }

    // method to insert a node at end
    insertAtEnd(item) {
        const newNode = new Node(item);
        if (this.isEmpty()) {
            this.insertAtBeginning(item);
        }
        else {


            let tempNode = this.firstNode;
            while (tempNode.nextNode !== this.firstNode) {
                tempNode = tempNode.nextNode;
            }

            newNode.nextNode = tempNode.nextNode;
            tempNode.nextNode = newNode;
        }
    }

    // method to delete a node from beginning
    deleteFromBeginning() {
        if(this.isEmpty()){
            console.log("Circularlinklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            while( tempNode.nextNode !== this.firstNode ){
                tempNode = tempNode.nextNode;
            }
            tempNode.nextNode = this.firstNode.nextNode;
            this.firstNode = this.firstNode.nextNode;
        }
    }

    // method to delete a node at end
    deleteFromEnd() {
        if(this.isEmpty()){
            console.log("Circularlinklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            let prevTempNode = null;
            while (tempNode.nextNode !== this.firstNode) {
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
            // Circularlinklist
            // Now if were implementing Circularlinklist
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
        if( temp.nextNode.nextNode === this.firstNode ){
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




    // a method to display the Circularlinklist
    display() {
        let tempNode = this.firstNode;
        do{
            tempNode.display();
            tempNode = tempNode.nextNode;
        } while( tempNode !== this.firstNode );
    }

};

const circularlinklist = new Circularlinklist();

circularlinklist.insertAtBeginning(10);
circularlinklist.insertAtBeginning(20);
circularlinklist.insertAtBeginning(30);
circularlinklist.insertAtBeginning(40);

circularlinklist.insertAtEnd(5);
circularlinklist.insertAtEnd(4);
circularlinklist.insertAtEnd(3);

circularlinklist.insertAfter(30,31);
circularlinklist.insertBefore(30,29);
/*
circularlinklist.deleteFromBeginning();
circularlinklist.deleteFromEnd();
/*
circularlinklist.deleteAfter(5);
circularlinklist.deleteBefore(29);
*/


/*
circularlinklist.deleteAfter(31);
circularlinklist.deleteBefore(4);
*/

console.log(circularlinklist.display());