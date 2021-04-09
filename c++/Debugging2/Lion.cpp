// Debugging: Lion.cpp

#include <iostream>

using std::cout;
using std::endl;

#include "Lion.h"

// default constructor
Lion::Lion( int h, int w )
   : Animal( h, w )
{
   // empty

} // end class Lion constructor

// function print definition
void Lion::print() const
{
   cout << "This animal is a lion\n";
   Animal::print();

} // end function print
