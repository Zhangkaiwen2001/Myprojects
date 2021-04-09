// Debugging: Animal.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Animal.h"
#include "Dog.h"
#include "Lion.h"
// default constructor
Animal::Animal( const int h, const int w )
{
    height = h;
    weight = w;
} // end class Animal constructor

Dog::Dog(const int h,const int w,string n): Animal(h,w)
{
    Dog::setName(n);
}

Lion::Lion(const int h,const int w): Animal(h,w)
{

}

// function print definition
void Animal::print() const
{
    cout << "This animal's height and weight are as follows\n"
         << "Height: " << height << "\tWeight: " << weight
         << endl;
} // end function print

void Lion::print() const
{
    cout<<"This animal is a lion"<<endl;
    Animal::print();
}

void Dog::Print() const
{
    cout<<"This animal is a dog,it's name is : "<<name<<endl;
    Animal::print();
}
// return height
int Animal::getHeight() const
{
    return height;
} // end function getHeight

// return weight
int Animal::getWeight() const
{
    return weight;
} // end function getWeight

// function print definition
void Animal::setHeight( const int h )
{
    height = h;
} // end function setHeight

// function print definition
void Animal::setWeight( const int w )
{
    weight = w;
} // end function setWeight

// return name
void Dog::setName(const string n)
{
    name=n;
} // end function getName

string Dog::getName()const
{
    return name;
}
