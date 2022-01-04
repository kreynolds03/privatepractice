#include <cstdio>
#include<iostream>
#include <string>
#include <cmath>


using namespace std;


class Rectangle
{
    private:
        int width, height;
    public:
        Rectangle(); //default constructor
        Rectangle(int, int); //parameterized constructor
        Rectangle(Rectangle&); //copy constructor
        int Area(){
            return width * height;
        }
};

Rectangle::Rectangle(){
    width = 1;
    height = 2;
}

Rectangle::Rectangle(int w, int h){
    width = w;
    height = h;
}

Rectangle::Rectangle(Rectangle &R){
    width = R.width;
    height = R.height;

}


int main(){

    Rectangle R;
    Rectangle R1(6,10);
    Rectangle R3(10000,3456);
    Rectangle R2(R1);
    //R.set_values(4,8);
    //R2.set_values(2345,23235);
    //R3.set_values(232,33);

    cout<<"Area is..."<<R.Area()<<endl;
    cout<<"Area is..."<<R1.Area()<<endl;
    cout<<"Area is..."<<R3.Area()<<endl;

   
    return 0;

}