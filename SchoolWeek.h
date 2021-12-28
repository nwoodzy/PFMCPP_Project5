#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "SchoolDay.h"

struct SchoolWeek 
{
    SchoolWeek();
    ~SchoolWeek();
    SchoolDay monday;
    SchoolDay tuesday;
    SchoolDay wednesday;
    SchoolDay thursday;
    SchoolDay friday;
    
    void makeHalfDay( SchoolDay& day, float lengthDecrease );
    void snowDay( SchoolDay& day);
    JUCE_LEAK_DETECTOR(SchoolWeek)
};
