// racecar.h
#ifndef RACECAR_H
#define RACECAR_H

#include "car.h"

// class Racecar definition
/* Write class header for Racecar, which inherits publicly
   from Car */
class Racecar :public Car
{
public:
   Racecar( string, string, string );

   void setGearbox( int );
   void useParachute();
   void print() const;

private:
   int gearbox; // number of gears in car (e.g., 5-speed)
   string sponsor;
   bool parachuteDeployed;

}; // end class Racecar

#endif // RACECAR_H
