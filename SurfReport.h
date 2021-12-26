#pragma once
#include <iostream>

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

        void surferLevelCheck()
        {
            std::cout << "Surfer's level is: " << this->surferSkill << std::endl;
        }
        void levelUp( int improvementAmount );
        void getTubed( int currentStokeLevel );
        void wipeOut( int currentStokeLevel );
    };

    void waveHeightCheck()
    {
        std::cout << "Wave height is: " << this->waveHeight << std::endl;
    }
    void increaseWaveHeight( float newWaveHeight );
    bool shouldIGoOut( int fatigueLevel );
    float chooseBoardSize();
    JUCE_LEAK_DETECTOR(SurfReport)
};
