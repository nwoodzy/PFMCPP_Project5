#include "SchoolDay.h"

SchoolDay::SchoolDay()
{ 
    dayOfTheWeek = "Monday";
    length = 6.f;
    runningLate = false;
    std::cout << "A schoolday was created" << std::endl;

}
SchoolDay::~SchoolDay()
{
    std::cout << "A schoolday was destroyed" << std::endl;
}


void SchoolDay::splitUpClass(int numOfGroups)
{   
    if (numberOfKids != 0)
    {
        numberOfKids /= numOfGroups;
    }
    else
    {
        std::cout << "there are" << numberOfKids << "kids in class!" << std::endl;
    }
}
void SchoolDay::shortenSchoolDay( float lengthDecrease )
{
    if (halfDay == false)
    {
        float i = length;
        i -= lengthDecrease;
        length = i;
        std::cout << "SchoolDay length is now: " << length << std::endl;
        halfDay = true;
    }
    
}   
void SchoolDay::sunCameOut()
{
    if (isRaining == true)
    {
        isRaining = false;
        std::cout << "sun came out" << std::endl;
    }
    else
    {
        std::cout << "sun is already out" << std::endl;
    }
}
