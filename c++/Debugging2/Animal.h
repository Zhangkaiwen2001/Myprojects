// Debugging: Animal.h

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using std::string;

// Note: class Animal is an abstract class
// class Animal definition
class Animal
{
public:
   Animal( int = 0, int = 0 );

   virtual void setHeight( int );
   virtual int getHeight() const;

   virtual void setWeight( int );
   virtual int getWeight() const;

   virtual void print() const;

private:
   int height;
   int weight;

}; // end class Animal

#endif // ANIMAL_H
