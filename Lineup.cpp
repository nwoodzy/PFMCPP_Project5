#include "Lineup.h"


Lineup::Lineup()
{
    std::cout << "a new Lineup was created" << std::endl;
}

Lineup::~Lineup()
{
    std::cout << "a Lineup was destroyed" << std::endl;
    tuesday.isBusy = false;
}

void Lineup::getSurferInfo( SurfReport::Surfer surfer ) 
{
    if ( surfer.atBeach )
    {
        std::cout << "surfer is at the beach" << std::endl;
    }
    else 
    {
        std::cout << "surfer is not at the beach" << std::endl;
    }
    std::cout << "surfer is " << surfer.surferAge << " years old" << std::endl;

    std::cout << "surfer's skill level is: " << surfer.surferSkill << std::endl;
    
    std::cout << "surfer is using a " << surfer.boardSize << "ft board" << std::endl;
    
    if ( surfer.havingLesson )
    {
        std::cout << "surfer is having lesson" << std::endl;
    }
    else 
    {
        std::cout << "surfer is not having lesson" << std::endl;
    }
}

void Lineup::teachASurferToSurf( SurfReport::Surfer surfer )
{
    surfer.havingLesson = true;
    std::cout << "surfer is now having lesson" << std::endl;
}
