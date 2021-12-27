#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct SchoolDay
{   
    SchoolDay();
    ~SchoolDay();
    std::string dayOfTheWeek;
    float length;
    int numberOfKids = 15;
    bool runningLate;
    bool halfDay = false;
    bool isRaining = false;

    void dayLengthCheck( SchoolDay& schoolday );
    void howManyKids( SchoolDay& schoolday );
    void splitUpClass( int numOfGroups );
    void shortenSchoolDay( float lengthDecrease );
    void sunCameOut();
    JUCE_LEAK_DETECTOR(SchoolDay)
};