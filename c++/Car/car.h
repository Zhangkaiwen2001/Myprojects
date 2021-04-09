// car.h
#ifndef CAR_H
#define CAR_H

#include <iostream>

#include <string>

using std::string;

// class car definition
class Car
{

public:
    Car( string name, string color );

    void setMaxSpeed( int s = 95 );
    int getMaxSpeed() const;

    void setEngineValves( int v = 4 );
    int getEngineValves() const;

    string getColor() const;
    string getName() const;

    void print() const;

private:
    int maxSpeed;
    int engineValves;
    string color;
    string name;

}; // end class Car

#endif // CAR_H
