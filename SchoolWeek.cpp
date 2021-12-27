#include "SchoolWeek.h"


SchoolWeek::SchoolWeek()
{
    std::cout << "a School Week was created" << std::endl;
}

SchoolWeek::~SchoolWeek()
{
    monday.length = 6.0;
    tuesday.length = 6.0;
    wednesday.length = 6.0;
    thursday.length = 6.0;
    friday.length = 6.0;
    std::cout << "a SchoolWeek was destroyed" << std::endl;
}


void SchoolWeek::makeHalfDay( SchoolDay day, float lengthDecrease )
{
    day.shortenSchoolDay( lengthDecrease );
}

void SchoolWeek::snowDay( SchoolDay day )
{
    day.length = 0;
    day.numberOfKids = 15;
    std::cout << "No school, snow day!" << std::endl;
}
