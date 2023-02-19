//
//  Elevator.cpp
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.

/*
    I declare that all material in this assessment task is my work except where there is clear acknowledgement or reference
    to the work of others. I further declare that I have complied and agreed to the CMU Academic Integrity Policy at the University
    website. http://www.coloradomesa.edu/student-services/documents
    Author's Name: Noah Jaramillo   UID(700#): 700452295  Date: 2/18/2023
*/
   
#include "Elevator.h"
#include <iostream>
// constructor for number of floors - no default constructor
Elevator::Elevator(int floors)
{
    maxfloor = floors;    // highest numbered floor in the building
    floorup = new bool[12];
    floordown = new bool[12];
    button = new bool[12];
    currentdirection = STOPPED;
    currentfloor = 0;
    dooropen = 0;
    for(int i = 0; i < 12; i++)
    {
        floorup[i] = 0;
        floordown[i] = 0;
        button[i] = 0;
    }
}

//Destructor
Elevator::~Elevator()
{
    delete [] floorup;
    delete [] floordown;
    delete [] button;
    
}

// move floor in required direction
void Elevator::Move()
{
    //releases button queue for current floor if rider gets off
    if(button[currentfloor] == true)
    {
        button[currentfloor] = false;
    }


    //stops elevator if no queue exists

    bool noQueue = true;
    for (int i = 0; i < 11; i++)
    {
        if (floorup[i] || floordown[i] || button[i])
        {
            noQueue = false;
        }
    }
    if (noQueue == true)
    {
        currentdirection = STOPPED;
        dooropen = 0;
    }

    //looks for queue then moves in proper direction if there is a queue and elevator is currently stopped
    if (currentdirection == STOPPED)
    {
        for(int i = 0; i < 11; i++)
        {
            if(floorup[i] == true || floordown[i] == true)
            {
                if(currentfloor == (maxfloor))
                {
                    currentdirection = DOWN;
                    if(floordown[maxfloor] == true)
                    {
                        dooropen = 1;
                        floordown[maxfloor] = false;
                        return;
                    }
                    dooropen = 0;
                    return;
                }
                else if(currentfloor == 0)
                {
                    currentdirection = UP;
                    if(floorup[0] == true)
                    {
                        dooropen = 1;
                        floorup[0] = false;
                        return;
                    }
                    dooropen = 0;
                    return;
                }
                else
                {
                    if(floorup[i] == true && i >= currentfloor)
                    {
                        currentdirection = UP;
                        if(currentfloor == i)
                        {
                            dooropen = 1;
                            floorup[i] = false;
                            return;
                        }
                        dooropen = 0;
                        return;
                    }
                    if(floorup[i] == true && i < currentfloor)
                    {
                        currentdirection = DOWN;
                        dooropen = 0;
                        return;
                    }
                    if(floordown[i] == true && i > currentfloor)
                    {
                        currentdirection = UP;
                        dooropen = 0;
                        return;
                    }
                    if(floordown[i] == true && i <= currentfloor)
                    {
                        currentdirection = DOWN;
                        if(currentfloor == i)
                        {
                            dooropen = 1;
                            floordown[currentfloor] = false;
                        }
                        dooropen = 0;
                        return;
                    }
                }
            }
            
        }
    }

    if (currentdirection == UP)
    {
        if(currentfloor == (maxfloor))
        {
            currentdirection = DOWN;
            dooropen = 1;
            return;
        }
        if(floorup[currentfloor] == true)
        {
            dooropen = 1;
            floorup[currentfloor] = false;
            return;
        }
        else
        {
            dooropen = 0;
            currentfloor++;
            return;
        }
    }

    if (currentdirection == DOWN)
    {
        if(currentfloor == 0)
        {
            currentdirection = UP;
            dooropen = 1;
            return;
        }
        if(floordown[currentfloor] == true)
        {
            dooropen = 1;
            floordown[currentfloor] = false;
            currentfloor--;
            return;
        }
        else
        {
            dooropen = 0;
            currentfloor--;
            return;
        }
    }
}

//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)
{
    currentFloor = currentfloor;
    currDir = currentdirection;
    doorIsOpen = dooropen;
}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{
    if(direction == DOWN)
    {
        floordown[floorNum] = true;
    }
    if(direction == UP)
    {
        floorup[floorNum] = true;
    }
}
// handle rider request inside elevator
void Elevator::ChooseFloor(int floorchosen)
{
    button[floorchosen] = true;
}



