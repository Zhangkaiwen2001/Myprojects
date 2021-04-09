// Debugging: Dog.cpp
#include <iostream>

using std::cout;
using std::endl;

#include "Dog.h"

// constructor
Dog::Dog( const int h, const int w, string n )
   : Animal( h, w )
{
   setName( n );
} // end class Dog constructor

// function setName definition
void Dog::setName( const char * n )
{
   n = name;
} // end function setName

// function print definition
void Dog::Print() const
{
   cout << "This animal is a dog, its name is: " << name << endl;

   print();
} // end function print
