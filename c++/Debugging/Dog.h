// Debugging: Dog.h
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

// class Dog definition
class Dog : public Animal
{
public:
    Dog( const int=0, const int=0, string = "Toto" );
    void Print() const;

    void setName(const string);
    string getName()const;

    void operator = (const Animal &a)
    {
        setHeight(a.getHeight());
        setWeight(a.getWeight());
    }
private:
    string name;
}; // end class Dog

#endif // DOG_H
