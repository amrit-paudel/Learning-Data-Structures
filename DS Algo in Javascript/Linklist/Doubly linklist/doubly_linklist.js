
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


// A doublylinklist class
class Doublylinklist {
    constructor() {
        this.firstNode = null;
    }

    // checks if the doublylinklist is empty
    isEmpty() {
        return this.firstNode === null;
    }

    // method to insert a node at beginning
    insertAtBeginning(item) {
        const newNode = new Node(item);
        if( this.isEmpty() ){
            this.firstNode = newNode;
        }
        else{
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
            while (tempNode.nextNode !== null) {
                tempNode = tempNode.nextNode;
            }
            newNode.previousNode = tempNode;
            tempNode.nextNode = newNode;
        }
    }

    // method to delete a node from beginning
    deleteFromBeginning() {
        if(this.isEmpty()){
            console.log("doublylinklist is empty");
        }
        else{
            this.firstNode = this.firstNode.nextNode;
        }
    }

    // method to delete a node at end
    deleteFromEnd() {
        if(this.isEmpty()){
            console.log("doublylinklist is empty");
        }
        else{

            let tempNode = this.firstNode;
            let prevTempNode = null;
            while( tempNode.nextNode !== null ){
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
            // doublylinklist
            // Now if were implementing doublylinklist
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




    // a method to display the doublylinklist
    display() {
        let tempNode = this.firstNode;
        while( tempNode !== null ){
            tempNode.display();
            tempNode = tempNode.nextNode;
        }
    }
    

    displayInReverse(){
        let tempNode = this.firstNode;
        while( tempNode.nextNode !== null ){
            tempNode = tempNode.nextNode;
        }

        while( tempNode !== null ){
            tempNode.display();
            tempNode = tempNode.previousNode;
        } 
    }

};

const doublylinklist = new Doublylinklist();

doublylinklist.insertAtBeginning(10);
doublylinklist.insertAtBeginning(20);
doublylinklist.insertAtBeginning(30);
doublylinklist.insertAtBeginning(40);

doublylinklist.insertAtEnd(5);
doublylinklist.insertAtEnd(4);
doublylinklist.insertAtEnd(3);

doublylinklist.insertAfter(30,31);
doublylinklist.insertBefore(30,29);
/*
doublylinklist.deleteFromBeginning();
doublylinklist.deleteFromEnd();

doublylinklist.deleteAfter(5);
doublylinklist.deleteBefore(29);



/*
doublylinklist.deleteAfter(31);
doublylinklist.deleteBefore(4);
*/

console.log(doublylinklist.displayInReverse());
// the fact that we were able to implement above 
// method is a proof that our doubly linked list worked
// really well
