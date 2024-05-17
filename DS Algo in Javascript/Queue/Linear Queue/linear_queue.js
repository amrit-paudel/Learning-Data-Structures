

// Unlike in c++ the array in javascript is 
// dynamic, it can grow as per the items
// so it is not necessary to mention the size

class Queue{
    constructor(size){
        this.size = size;
        this.queueArray = [this.size];
        this.rear = -1;
        this.front = 0;
    }

    // method to check if the Queue is empty
    isEmpty(){
        return ((this.rear == -1 && this.front == 0) || this.front>this.rear ) ;
    }

    // method to check if the Queue is full
    isFull(){
        return (this.front == 0 && (this.rear == this.size - 1));
    }

    // method to add the items in the queue
    enQueue(item){
        if( this.isFull() ){
            console.log("Queue is full");
        }
        else{
            this.queueArray[++this.rear] = item;
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
            delete this.queueArray[this.front++];
        }
    }

    peek(){
        if(this.isEmpty()){
            console.log("Queue is empty");
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

console.log(queue.peek());

queue.deQueue();
queue.deQueue();
queue.deQueue();
queue.deQueue();

queue.deQueue();

