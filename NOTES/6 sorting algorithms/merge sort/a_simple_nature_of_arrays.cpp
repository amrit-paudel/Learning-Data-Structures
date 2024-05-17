


#include<iostream>
using namespace std;

void increaseEachItem( int nums[],int size ){
    for( int i=0;i<=size-1;i++ ){
        nums[i] = nums[i] + 1;
    }
}

void display(int nums[],int size){
        for( int i=0;i<=size-1;i++ ){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[] = {10,20,30,40,50};
    increaseEachItem(nums,5);
    display(nums,5);

}

/*
While working with arrays, remember that the name of array itself is a pointer
So the above function increaseEachItem function do not need to return the new 
array after increasing the each item

While we are increasing the each item we are already working with the original array 
because the namr of array is a pointer
So when we pass the ayyay name here, increaseEachItem(nums,5); we actually pass the pointer to the function
*/


