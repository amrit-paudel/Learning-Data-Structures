
// this class handles the task of displaying 
// all stack operations visually

class StackOutput{

}

class Stack{
    constructor(size){
        this.size = size;
        this.stackArray = [this.size];
        this.top = -1;
        this.stackOutput = new StackOutput();
    }

    // method to push data in the stack
    push(item){
        if( this.top===this.size-1 ){
            console.log("Stack is Full");
        }
        else{
            this.stackArray[++this.top] = item;
        }
    }

    // method to pop the item
    pop(){
        if( this.top === -1 ){
            console.log("Stack is empty");
        }
        else{
            this.stackArray.splice(this.top--,1);
            
        }
    }

    // method to get the topmost item of stack
    peek(){
        return this.stackArray[this.top];
    }

    // checks if the stack is empty
    isEmpty(){
        return this.top===-1;
    }

    // checks if the stack is full
    isFull(){
        return this.top===this.size-1;
    }

    // a method to display all the stack items
    display(){
        for( this.i = 0; this.i<=this.top; this.i++ ){
            console.log(this.stackArray[this.i]);
        }
    }
};

const stack = new Stack(4);

stack.push(10);


