// Debugging: debugging.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Animal.h"
#include "Lion.h"
#include "Dog.h"

int main()
{
   Animal a1( 0, 0 );
   Dog d1( 60, 120, "Fido" );
   Dog d2;
   Lion lion1( 45, 300 );

   a1.print();
   d1.Print();
   d2.Print();
   lion1.print();

   a1 = d1;
   cout << "Animal 1 now has the same height and weight "
        << "as dog 1\n";
   a1.print();

   d2 = a1;
   cout << "Dog 2 now has the same height and weight as animal 1\n";
   d2.print();

   return 0;
} // end main
