#include<iostream>
using namespace std;

int counter ( int num ){
    return ++num;
}

int main(){
    
    int num  = counter(10);
    cout<<"Num"<<num<<endl;

    while( num < 20 ){
        cout<<" Inside loop "<<endl;
        num = counter(num++);

    }

}