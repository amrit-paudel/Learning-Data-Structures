

#include<iostream>
#include<string>

using namespace std;

int main(){

    string* nodeList = new string[10];

    nodeList[0]="A";
    nodeList[1]="B";

    cout<<nodeList[0];

    delete[] nodeList;




}