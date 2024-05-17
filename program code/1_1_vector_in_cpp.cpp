



#include<iostream>
#include<vector>
// vectors are really useful in c++ 
// it is like a dynamic array
// we can work without having to set the size at first
// like we do with array
// memory allocation and deallocation are done implicitly


using namespace std;


int main(){
    // this is the format
    // vector keyword data_type variable_name
    vector <int> numarray;
    numarray={10,20,30,40,50};
    
    // we have .size() method that returns the size of vector
    cout<<numarray.size()<<endl;

    // we have .at() method that returns the
    // alue at that index number
    cout<<numarray.at(0)<<endl;

    // we can also access the data values
    // like we do in array 
    cout<<numarray[0]<<endl;

    // we have .resize() property, from which we
    // can resize the size of our vector
    // like
    // numarray.resize(10)
    // now the size has changed to 10


    // .capacity()
    // also an interesting method
    // see the difference between
    // .size() and .capacity() methods

    // capacity is the total number of
    // elements a vector can hold
    // before it can be reallocated


    numarray.push_back(10);
    // .push_back() 
    // this method pushes an element to the top of vector
    
    cout<<"PRINTING EVERY ELEMENT"<<endl;
    for(int i=0;i<=numarray.size()-1;i++){
        cout<<numarray[i]<<endl;
    }


    // .pop_back()
    // this pops an element from vector

    cout<<numarray.back();
    // .back()
    // this one returns the value of top element
    // of the vector stack


   //.reserve() method
   // by this method we can define a vector 
   // of any desired capacity
   // meaning we can define a vector
   // that can hold a defined number of 
    


}