#pragma once
#include <iostream>

struct SchoolWeek 
{
    SchoolWeek();
    ~SchoolWeek();
    SchoolDay monday;
    SchoolDay tuesday;
    SchoolDay wednesday;
    SchoolDay thursday;
    SchoolDay friday;
    
    void makeHalfDay( SchoolDay day, float lengthDecrease );
    void snowDay( SchoolDay day);
    JUCE_LEAK_DETECTOR(SchoolWeek)
};
