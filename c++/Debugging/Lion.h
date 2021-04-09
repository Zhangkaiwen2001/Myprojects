// Debugging: Lion.h

#ifndef LION_H
#define LION_H

#include "Animal.h"

// class Lion definition
class Lion : public Animal
{
public:
   Lion( const int = 0, const int = 0 );

   void print() const;
}; // end class Lion

#endif // LION_H
