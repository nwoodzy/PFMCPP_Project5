#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct SurfReport
{
    SurfReport();
    ~SurfReport();
    float waveHeight;
    float wavePeriod;
    std::string windDirection;
    int windSpeed;
    bool isRaining = false;
    bool isBusy = false;
    struct Surfer
    {
        Surfer();
        ~Surfer();
        bool atBeach = true;
        int surferAge;
        int surferSkill = 0;
        float boardSize = 6.8f;
        bool havingLesson = false;

        void surferLevelCheck(SurfReport::Surfer& surfer);
        void levelUp( int improvementAmount );
        void getTubed( int currentStokeLevel );
        void wipeOut( int currentStokeLevel );
    };

    void waveHeightCheck( SurfReport& report );
    void increaseWaveHeight( float newWaveHeight );
    bool shouldIGoOut( int fatigueLevel );
    float chooseBoardSize();
    JUCE_LEAK_DETECTOR(SurfReport)
};
