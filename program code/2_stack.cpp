

// our stack must have these basic methods
// .push()
// .pop()
// .isEmpty() 

#include<iostream>
#include<vector>

using namespace std;

class Stack{
    private:
     int size;
     int top;

     vector <int> intarray;

     public:
     Stack(int size){
         this->size=size;
         this->top=-1;
         intarray.reserve(size);
     }

     void push(int item){
         intarray[++top]=item;
     }

     void pop(){
         top--;
     }
     

     // checks if the stack is empty 
     bool isEmpty(){
         return top==-1;
     }

     // checks if the stack is full
     bool isFull(){
         return top == size-1;
     }

     // returns the top item
     int topItem(){
         return intarray[top];
     }

};

int main(){
    Stack stackobj(3);

    stackobj.push(10);
    stackobj.push(20);
    stackobj.push(30);

    while(!stackobj.isEmpty()){
        cout<<stackobj.topItem()<<endl;
        stackobj.pop();
    }
}