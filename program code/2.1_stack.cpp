

// to check the balanced parenthesis in a mathematical expression using stack

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Stack{
    private:
    int size;
    int top;
    vector <char> charArray;

    public:
    Stack(int size){
        this->size=size;
        charArray.reserve(size);
        top=-1;
    }

    void push(char ch){
        charArray[++top] = ch;
    }

    void pop(){
        top--;
    }

    char top(){
        return charArray[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==size-1;
    }



};

int main(){

    string exp;
    cout<<"Enter a mathematical expression ?"<<endl;
    cin>>exp;

    for(int i=0;i<=exp.size()-1;i++){
        if(exp[i]=='(') {
            
        }
    }

}