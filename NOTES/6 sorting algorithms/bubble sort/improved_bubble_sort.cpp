
#include<iostream>
using namespace std;


// function to bubble sort data
// this is to sort in ascending order

void bubbleSort(int* nums,int size){
    int temp;
    int flag = 1;
    for( int i=0;i<=size-1 && flag == 1 ;i++ ){
        // look at the above properly, first time doing this
        // actually we could do this in c++

        flag = 0;

        for( int j=0;j<=size-1;j++ ){
            if( nums[j] > nums[j+1] ){  // yo condition satiafy naa hudaa pailai sort vai sakkaeko hunxaa
            // so tyo case maa flag 0 nai rahanxaa, so next iteration step check garnai paraenaa
            
                flag = 1;
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



