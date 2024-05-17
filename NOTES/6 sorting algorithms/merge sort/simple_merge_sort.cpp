

#include<iostream>
using namespace std;

// merge function to merge the sorted array 

void merge( int nums[] , int leftIndex, int rightIndex, int upperBound ){
    int size = upperBound - leftIndex + 1;
    int tempNums[50];                              // could not find a way to set the size of array with something like size defined just above line
    int tempIndex = 0;
    int mid = rightIndex-1;

    while( leftIndex <= mid && rightIndex <= upperBound ){  // while both left array and right array are non empty
        if( nums[leftIndex] < nums[rightIndex] ){
            tempNums[tempIndex++] = nums[leftIndex++];
        }
        else{
            tempNums[tempIndex++] = nums[rightIndex++];
        }
    }

    while( leftIndex <= mid ){                    // left array is non empty and right array is empty
        tempNums[tempIndex++] = nums[leftIndex++];
    }

    while( rightIndex <= upperBound ){                 // right array is non empty and left array is empty
        tempNums[tempIndex++] = nums[rightIndex++];
    }

    // this one is the heart of this whole sorting algorithm
    for( tempIndex=leftIndex ; tempIndex<=upperBound; tempIndex++ ){
        nums[tempIndex] = tempNums[tempIndex-leftIndex];
        // just forgetting to subtract leftIndex causes disaster, so be careful
        // nums[tempIndex] = tempNums[tempIndex];  writing this instead of upper one causes disaster
        // lets understand this later on
        // this seems a weird problem
        // I wonder if other people face this ?
        // I will put this one on stack overflow later on 
         
    }
}

// function to sort the array by recurssion
void mergeSort( int nums[] , int lowerBound , int upperBound ){
    if( lowerBound == upperBound ){     // this is the base case for the recurssion
        return;
    }
    else{
        int mid = ( lowerBound + upperBound ) / 2;

        mergeSort( nums , lowerBound , mid );    // sort the left array
        mergeSort( nums , mid+1 , upperBound );  // sort the right array
        merge( nums , lowerBound , mid+1 , upperBound );  // merge left and right array after sorting them
    }
}


// function to display the array
void displayArray( int nums[] , int size ){
    int i;
    for( i=0;i<=size-1;i++ ){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[] = {60,50,40,30,20,10};
    mergeSort( nums , 0 , 5 );
    displayArray(nums,6);
}




