#pragma once
#include <iostream>

/*
 UDT 1:
 */
struct Sailboat 
{
    Sailboat();
    ~Sailboat();

    std::string boatName;
    struct Mast
    {
        Mast();
        ~Mast();

        int mastHeight;
        int boomLength = 109;
        bool isBermudaRig = true;
        bool isLateen = false;
        bool isStepped = true;
        int numOfReefs = 0;
        int numOfTotalReefs = 4;

        void mastHeightCheck()
        {
            std::cout << "mast height: " << this->mastHeight << std::endl;
        }
        void reefCheck()
        {
            std::cout << "number of reefs: " << this->numOfReefs << std::endl;
        }
        void reduceSail( int reefs );
        void increaseSail (int reefs );
        int getHeelDistance ( int distanceToWater );
    };

    int numOfSails;
    float length = 13.8f;
    bool isAnchored = false;
    float sailArea = 50.6f;
    bool hasKeel;
    bool isStillFloating = true;
    
    void sailCheck()
    {
        std::cout << "Sailboat has " << this->numOfSails << " sails" << std::endl;
    }
    int findOppositeTack ( int directionInDegrees );
    void trimSail( int currentTrim, int inchesOfSheet );
    void dropAnchor();
    JUCE_LEAK_DETECTOR(Sailboat)
};
