

#include <iostream>

using namespace std;

// function to swap the elements
void swap(int nums[], int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

// function to make partition of the array
// here the array is virtually divided in to two parts
// one at the RHS of the pivot element
// other at the LHS of the pivot element

int partition(int nums[], int left, int right, int pivot)
{
    
    int leftMark = left-1;
    int rightMark = right;


    while(true){

        while(nums[++leftMark] < pivot)
        ;
        while( nums[--rightMark] > pivot )
        ;

        if( leftMark >= rightMark )
            break;
        
        else
            swap(nums,leftMark,rightMark);
        
    }

    swap(nums,leftMark,right);

    return leftMark;


}



// function to Quick Sort the array
void quickSort(int nums[], int left, int right)
{
    if (right-left <= 0)
    {   // this is also our base conditiion for the recurssion
        // here if we did right-left==0, than it won't work for the condition when pivotIndex is returned as 0, than
        // as per quickSort(nums,left,pivotIndex-1); we will get quickSort(nums,left,-1);
        // so right-left==0; fails for this condition

        return; // remember here we are working on the pass by reference function, so whatever we do with the
        // nums array here, the original one in the main function is affected
        // so we do no tneed to return anything from the function here
    }
    else
    {
        cout<<"inside quickSort, else"<<endl;
        int pivot = nums[right];

        int pivotIndex = partition(nums,left, right, pivot);
        quickSort(nums, left, pivotIndex - 1);  // this will sort the left partiton of the array after the pivot index
        quickSort(nums, pivotIndex + 1, right); // this will sort the right partiton of the array after the pivot index
    }
}

// function t o display the array
void displayArray(int nums[], int size)
{
    int i;
    for (i = 0; i <= size - 1; i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    int nums[] = {60,50,40,30,20,10};

    quickSort(nums, 0, 5); // BE CAREFUL, here we are passing the name of the array
    // which means we are passing the reference to the original array
    // so whatever we do in the passes function it affects the original nums[] array we made in the main function
    // this is also a type of the pass by reference

    // Now after this the array is sorted, lets display this
    displayArray(nums, 6);
}