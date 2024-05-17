

#include<iostream>
#include<string>
using namespace std;


// finding the nth triangular number
int triangle(int num){
    if(num==1){
        return num;
    }
    else{
        return num + triangle(num-1);
    }

}

// cacluates the factorial of the given number
int factorial(int n){
    if(n==1){
        return 1;
    }
    else {
    return n * factorial( n-1 );
    }
}

// converts the provided decimal number to binary
void decimalToBinary(int num){
    if( num==1 ){
        cout<< num;
    }
    else{
        decimalToBinary(num/2);
        cout<<num%2;
    }
}


// find the nth fibochani number
// sometimes there can be more than one base case just like here
// this function returns the n'th fibonachi number
// through recursion

int fibonachiFromRecursion(int num){
    if( num== 0){return 1;}
    else if( num==1 ){return 1;}
    else{
        return ( fibonachiFromRecursion(num-1) + fibonachiFromRecursion(num-2) );
    }
}


// this function returns the n'th fibonachi
// number through iterative method

int fibonachiFromIteration(int num){
    if( num==1 ){return 1;}
    else{
        int front = 0; int back = 1;
        int temp;
        for( int i=1;i<=num;i++ ){
            temp = back;
            back = back + front;
            front = temp;
        } return back;

    }
}

// Tower of hanoi problem
void TOH( int num, string source, string temp, string dest ){
    if( num==1 ){
        cout<<"Move Disc From "<<source<<" to "<<dest<<endl;
    }
    else{
        TOH( num-1, source, dest, temp );
        cout<<"Move a disc from "<<source<<" to "<<dest<<endl;
        TOH(num-1, temp, source, dest);
    }
}



int main(){
   // cout<<fibonachiFromRecursion(5)<<endl;
   // cout<<fibonachiFromIteration(5)<<endl;
   
   /*
   int num;
   string source, temp, dest;
   cout<<"Enter the number of disc for tower of honoi"<<endl;
   cin>>num;
   cout<<"Enter source \nEnter Temp \nEnter destination"<<endl;
   cin>>source>>temp>>dest;
   TOH(num, source, temp, dest);
   */

  

}