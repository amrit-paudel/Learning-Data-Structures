
// A Node class
class Node {
    constructor(item) {
        this.item = item;
        this.nextNode = null;
        this.previousNode = null;
    }

    // to display the data
    display() {
        console.log(this.item);
    }
};


// A doublycircularlinklist class
class Doublycircularlinklist {
    constructor() {
        this.firstNode = null;
    }

    // checks if the doublycircularlinklist is empty
    isEmpty() {
        return this.firstNode === null;
    }

    // method to insert a node at beginning
    insertAtBeginning(item) {
        const newNode = new Node(item);
        if( this.isEmpty() ){
            this.firstNode = newNode;
            this.firstNode.nextNode = this.firstNode;
            this.firstNode.previousNode = this.firstNode;
        }
        else{
            let tempNode = this.firstNode;

            while(tempNode.nextNode !== this.firstNode){
                tempNode = tempNode.nextNode;
            }
            newNode.previousNode = tempNode;
            tempNode.nextNode = newNode;
            this.firstNode.previousNode = newNode;
            newNode.nextNode = this.firstNode;

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

            newNode.nextNode = this.firstNode;
            this.firstNode.previousNode = newNode;
            newNode.previousNode = tempNode;
            tempNode.nextNode = newNode;
        }
    }

    // method to delete a node from beginning
    deleteFromBeginning() {
        if(this.isEmpty()){
            console.log("doublycircularlinklist is empty");
        }
        else{
            let tempNode = this.firstNode;
            while( tempNode.nextNode !== this.firstNode ){
                tempNode = tempNode.nextNode;
            }
            tempNode.nextNode = this.firstNode.nextNode;
            this.firstNode.nextNode.previousNode = tempNode;

            this.firstNode = this.firstNode.nextNode;
        }
    }

    // method to delete a node at end
    deleteFromEnd() {
        if(this.isEmpty()){
            console.log("doublycircularlinklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            while( tempNode.nextNode !== this.firstNode ){
                tempNode = tempNode.nextNode;
            }

            this.firstNode.previousNode = tempNode.previousNode;
            tempNode.previousNode.nextNode = this.firstNode;

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
        tempNode.nextNode.previousNode = newNode;
        newNode.previousNode = tempNode;
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
        tempNode.nextNode.previousNode = newNode;
        newNode.previousNode = tempNode;
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
            tempNode.nextNode.previousNode = prevTempNode;
            // here we take out tempNode from the
            // doublycircularlinklist
            // Now if were implementing doublycircularlinklist
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
            tempNode.nextNode.nextNode.previousNode = tempNode;
        }


    }




    // a method to display the doublycircularlinklist
    display() {
        let tempNode = this.firstNode;
        do{
            
            tempNode.display();
            tempNode = tempNode.nextNode;
        }
        while( tempNode !== this.firstNode );
    }

};

const doublycircularlinklist = new Doublycircularlinklist();

doublycircularlinklist.insertAtBeginning(10);
doublycircularlinklist.insertAtBeginning(20);
doublycircularlinklist.insertAtBeginning(30);
doublycircularlinklist.insertAtBeginning(40);

doublycircularlinklist.insertAtEnd(5);
doublycircularlinklist.insertAtEnd(4);
doublycircularlinklist.insertAtEnd(3);

doublycircularlinklist.insertAfter(30,31);
doublycircularlinklist.insertBefore(30,29);
/*
doublycircularlinklist.deleteFromBeginning();
doublycircularlinklist.deleteFromEnd();

doublycircularlinklist.deleteAfter(5);
doublycircularlinklist.deleteBefore(29);
*/


/*
doublycircularlinklist.deleteAfter(31);
doublycircularlinklist.deleteBefore(4);
*/

console.log(doublycircularlinklist.display());
