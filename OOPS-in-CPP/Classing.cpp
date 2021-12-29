#include <iostream>
#include <cmath>
using namespace std;
// Shape is parent class
class Shape{
    public:
        virtual void Area(){}
        virtual void Perimeter(){}
};
// Square child class so "Inheritance"
// Side is not visible to either Shape nor Circle
// So private keyword "Abstraction"
// Mostly "Polymorphism" as virtual keyword
// I made classes so "Encapusulation"
class Square: public Shape{
    private:
        int side;
    public:
        Square(int s): Shape(){side=s;}
        void Area(){cout<<side*side<<endl;}
        void Perimeter(){cout<<4*side<<endl;}
};
// Circle child class
class Circle: public Shape{
    private:
        double r;
    public:
        Circle(double r): Shape(){this->r = r;}
        void Area(){cout<<M_PI*r*r<<endl;}
        void Perimeter(){cout<<2*M_PI*r<<endl;}
};
class Rectangle: public Shape{
    protected:
        int l,b;
    public:
        Rectangle(int l,int b): Shape(){this->l = l;this->b = b;}
        void Area(){cout<<l*b<<endl;}
        void Perimeter(){cout<<2*(l + b)<<endl;}
};
int main(){
    Shape *sq = new Square(10);
    Shape *cr = new Circle(11.11);
    Shape *sql = new Rectangle(11,12);
    sq->Area();
    sq->Perimeter();
    cr->Area();
    cr->Perimeter();
    sql->Area();
    sql->Perimeter();
    return 0;
}