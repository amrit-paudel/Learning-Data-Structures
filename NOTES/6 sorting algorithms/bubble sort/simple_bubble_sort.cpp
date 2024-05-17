
#include<iostream>
using namespace std;


// function to bubble sort data
// this is to sort in ascending order

void bubbleSort(int* nums,int size){
    int temp;
    for( int i=0;i<=size-1;i++ ){
        for( int j=0;j<=size-1;j++ ){
            if( nums[j] > nums[j+1] ){
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }

    cout<<"The data in ascending order is ";
    for( int i=0;i<=size-1;i++ ){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[] = {60,50,40,30,20,10};
    bubbleSort(nums,6);
}



