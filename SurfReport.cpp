#include "SurfReport.h"

SurfReport::SurfReport()
{
    waveHeight = 3.5f;
    wavePeriod = 18.f;
    windDirection = "SSE";
    windSpeed = 10;
    std::cout<< "a SurfReport was created" << std::endl;
}

SurfReport::~SurfReport()
{
    std::cout<< "a SurfReport was destroyed" << std::endl;
}

SurfReport::Surfer::Surfer() :
surferAge(35)
{
    std::cout<< "a Surfer aged: " << surferAge << " was created" << std::endl;
}

SurfReport::Surfer::~Surfer()
{
    std::cout<< "a Surfer aged: " << surferAge << " was destroyed" << std::endl;
}


void SurfReport::Surfer::levelUp( int improvementAmount )
{
    if (surferSkill <= 10)
    {
        for (int x = 0; x <= improvementAmount && surferSkill <= 10; ++x)
        {
            ++surferSkill;
        }
    }
}
void SurfReport::Surfer::getTubed( int currentStokeLevel )
{
    currentStokeLevel += 10; 
    std::cout << "tubed! Stoke level = " << currentStokeLevel << std::endl;
}
void SurfReport::Surfer::wipeOut( int currentStokeLevel )
{
    currentStokeLevel -= 10;
    std::cout << "wipeout! Stoke level = " << currentStokeLevel << std::endl;
}

void SurfReport::increaseWaveHeight( float heightIncrease )
{
    waveHeight += heightIncrease; 
}
bool SurfReport::shouldIGoOut( int fatigueLevel )
{
    if (fatigueLevel < 10)
    {
        ++fatigueLevel;
        std::cout << "new fatigue level = " << fatigueLevel << std::endl;
        std::cout << "yes you should go out" << std::endl;
        return true;
    }
    std::cout << "Don't go out" << std::endl;
    return false;
}
float SurfReport::chooseBoardSize()
{
    float boardLength = 8.f;
    for (float x = 0.f; x <= waveHeight; x += 1.f)
    {
        if (boardLength > 5.f)
        {
            boardLength -= .5f;
        }
    }
    std::cout << "Board length should be: " << boardLength << std::endl;
    return boardLength;
}

void SurfReport::waveHeightCheck(SurfReport& report)
    {
        std::cout << "Wave height is: " << report.waveHeight << std::endl;
    }

void SurfReport::Surfer::surferLevelCheck(SurfReport::Surfer& surfer)
    {
        std::cout << "Surfer's level is: " << surfer.surferSkill << std::endl;
    }
 