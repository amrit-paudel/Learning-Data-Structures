#include<iostream>
#include<cstring>

using namespace std;

class Mobiles{
    private:
    char* name;
    int price;

    public:
    Mobiles(char* name, int price){
        this->price=price;
        this->name=name;
    }

    void printinfo(){
        cout<<"Name : "<<this->name<<endl;
        cout<<"Price : "<<this->price<<endl;
    }

};

int main(){

    Mobiles* samsung=new Mobiles("Samsung Galaxy",50000);
    samsung->printinfo();

    // We can also do this in UD data type
    Mobiles* apple=NULL;
    apple->printinfo();  // but this won't give us anything
    


}