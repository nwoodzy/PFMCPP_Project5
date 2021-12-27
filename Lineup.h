#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "SurfReport.h"

struct Lineup
{
    Lineup();
    ~Lineup();
    SurfReport::Surfer joe;
    SurfReport::Surfer madeline;
    SurfReport::Surfer coretta;
    SurfReport tuesday;

    void getSurferInfo( SurfReport::Surfer surfer );
    void teachASurferToSurf( SurfReport::Surfer surfer );
    JUCE_LEAK_DETECTOR(Lineup)
};
