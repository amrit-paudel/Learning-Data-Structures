
#include<iostream>
using namespace std;


// insertion sort function
// this is to sort in ascending order

void insertionSort(int* nums,int size){
    int out, in;
    for( out=1;out<=size-1;out++ ){
        int temp = nums[out];
        in = out;

        while( in > 0 && nums[in-1] > temp ){   // yedi yo condition satisfy vayo vannae
        // sabai elements lai right shift garnae
        nums[in] = nums[in-1];
        --in;

        }
        nums[in] = temp;
    }
    
    // displaying data after sorting
    cout<<"The data in ascending order is ";
    for( int i=0;i<=size-1;i++ ){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[] = {60,50,40,30,20,10};
    insertionSort(nums,6);
}



