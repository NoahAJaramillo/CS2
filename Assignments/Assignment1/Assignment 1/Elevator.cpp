//
//  Elevator.cpp
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.
   
#include "Elevator.h"
// constructor for number of floors - no default constructor
Elevator::Elevator(int floors)
{
    maxfloor = floors;    // highest numbered floor in the building
}

//Destructor
Elevator::~Elevator()
{
  
}

// report current status: floor, direction, door status
void Elevator::Move()
{
    
}

//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)
{

}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{

}
// handle rider request inside elevator
void Elevator::ChooseFloor(int floorchosen)
{
    
}



