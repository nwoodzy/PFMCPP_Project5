#include "Sailboat.h"

Sailboat::Sailboat()
{
    numOfSails = 1;
    hasKeel = false;
    std::cout << "a Sailboat was created" << std::endl; 
}
Sailboat::~Sailboat()
{
    std::cout << "a Sailboat named was destroyed" << std::endl; 
}
Sailboat::Mast::Mast()
{
    mastHeight = 14;
    std::cout << "a mast was created" << std::endl;
}

Sailboat::Mast::~Mast()
{
    std::cout << "a mast was destroyed" << std::endl; 
}

int Sailboat::findOppositeTack( int directionInDegrees )
{
    int x = ( directionInDegrees + 180 ) % 360;
    std::cout << "your new heading is " << x << "degrees" << std::endl;
    return x;
}

void Sailboat::trimSail( int currentTrim, int inchesOfSheet )
{
    if (inchesOfSheet != 0)
    {
        for (int x = 0; x <= inchesOfSheet; ++x)
        {
            currentTrim -= inchesOfSheet;
        }
    }
    std::cout << "you have no sheet to trim!" << std::endl; 
}

void Sailboat::dropAnchor()
{
    if (isAnchored == false)
    {
        isAnchored = true;
        std::cout << "now you're anchored mate." << std::endl; 
    }
    else
    {
        std::cout << "you're already anchored!" << std::endl; 
    }
}
void Sailboat::Mast::reduceSail( int reefs )
{
    if (numOfReefs != numOfTotalReefs)
    {
        numOfReefs += reefs;
    }
    else 
    {
        std::cout << "you can't take that many reefs!" << std::endl;
    }
}
void Sailboat::Mast::increaseSail (int reefs )
{
    if ( numOfTotalReefs == 0 )
    {
        std::cout << "you're sail is all the way up already!" << std::endl;
    }
    if ( reefs > numOfTotalReefs  )
    {
        numOfReefs = numOfTotalReefs;
    }
    else 
    {
        numOfReefs -= reefs;
    }
}
int Sailboat::Mast::getHeelDistance ( int distanceToWater )
{
    int x = mastHeight - distanceToWater;
    std::cout << "Heel distance is: " << x << std::endl;
    return x;
}

void Sailboat::sailCheck( Sailboat& sailboat )
{
    std::cout << "Sailboat has " << sailboat.numOfSails << " sails" << std::endl;
}

void Sailboat::Mast::mastHeightCheck( Sailboat::Mast& mast )
{
    std::cout << "mast height: " << mast.mastHeight << std::endl;
}
void Sailboat::Mast::reefCheck( Sailboat::Mast& mast )
{
    std::cout << "number of reefs: " << mast.numOfReefs << std::endl;
}