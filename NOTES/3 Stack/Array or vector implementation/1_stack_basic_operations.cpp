

#include<iostream>
#include<vector>

using namespace std;

class Stack{
    private:
    int stackSize;
    vector<int> intVector;
    int top;

    public:
    Stack(int stackSize){
        this->stackSize = stackSize;
        top = -1;
        intVector.resize(this->stackSize);
    }

    // push() method to put element at top of stack
    void push(int item){
        intVector[++top] = item;
    }

    // pop() removes element from top of stack
    void pop(){
        top--;
    }

    // isEmpty() checks if the stack is empty
    bool isEmpty(){
        return this->top==-1;
    }

    // isFull() checks if the the stack is full
    bool isFull(){
        return top==this->stackSize-1;
    }

    int peek(){
        return intVector[top];
    }
    

    // this method is not among the
    // basic stack operation
    // but we must implement it this way
    // since it prints the values from top to bottom
    // of stack
    void displayItems(){
        int i=top;
        while(i!=-1){
            cout<<intVector[i];
            i--;
        }
    }




};

int main(){

    Stack stackobj(6);
    stackobj.push(10);
    stackobj.push(20);
    stackobj.push(30);
    stackobj.push(40);
    stackobj.push(50);
    stackobj.push(60);

    stackobj.pop();
    stackobj.pop();
    stackobj.pop();

    stackobj.displayItems();

}