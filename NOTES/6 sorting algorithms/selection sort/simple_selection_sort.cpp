


#include<iostream>
using namespace std;


// selection sort function
// this is to sort in ascending order

void selectionSort(int* nums,int size){
    int max;
    int maxIndex;
    int j;

    for(  int i=0;i<=size-1;i++ ){

        max = nums[0];

        for(  j=0;j<=size-i-1;j++ ){
           /* max = nums[0]; */                 // yetti eautaa lai for loop bhitra rakhnaa lae purai bigrinxaa                     
            if( nums[j] >= max ){
                max = nums[j];
                maxIndex = j;
            }
        }
        
        nums[maxIndex] = nums[size-i-1];
        nums[size-i-1] = max;
        
    }
    
    // displaying data after sorting
    cout<<"The data in ascending order is ";
    for( int i=0;i<=size-1;i++ ){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[] = {60,50,40,30,20,10};
    selectionSort(nums,6);
}



