

// Unlike in c++ the array in javascript is 
// dynamic, it can grow as per the items
// so it is not necessary to mention the size


// Implementation of Circular Queue

class Queue{
    constructor(size){
        this.size = size;
        this.queueArray = [this.size];
        this.rear = -1;
        this.front = 0;
    }

    // method to check if the Queue is empty
    isEmpty(){
        return ((this.rear == -1 && this.front == 0) ) ;
    }

    // method to check if the Queue is full
    isFull(){
        if( this.rear > this.front ){
            return ( this.front===0 && this.rear===this.size-1 );
        }
        if( this.front > this.rear && this.front!==0 && this.rear!==0 ){
            return (this.front === ( ( this.rear + 1 ) % this.size) ); 
        }
        
    }

    // method to add the items in the queue
    enQueue(item){
        if( this.isFull() ){
            console.log("Queue is full");
        }
        else{
            this.rear = ( this.rear + 1 ) % this.size;
            this.queueArray[this.rear] = item;
        }
    }

    deQueue(){
        if(this.isEmpty()){
            console.log("Queue is empty");
        }
        else if( this.front === this.rear ){
            this.front = 0;
            this.rear = -1;
        }
        else{
            
            delete this.queueArray[this.front];
            this.front = ( this.front + 1 ) % this.size ; 
        }
    }

    peek(){
        if(this.isEmpty()){
            console.log("Queue is empty");
        }
        else if( this.rear < this.front ){
            if( this.isFull() ){
                return this.queueArray[0];
            }
            else{ return this.queueArray[this.rear]; }
            
        }
        else{
            return this.queueArray[this.front];
        }
    }

};



const queue = new Queue(4);
queue.enQueue(10);
queue.enQueue(20);
queue.enQueue(30);
queue.enQueue(40);

console.log(queue.queueArray)


queue.deQueue();
queue.deQueue();
queue.deQueue();
console.log(queue.peek());

queue.enQueue(5);
queue.enQueue(6);
queue.enQueue(7);

console.log(queue.peek());
console.log(queue.queueArray)

