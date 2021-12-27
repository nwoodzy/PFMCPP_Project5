/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



#include <iostream>
#include "LeakedObjectDetector.h"
#include "Sailboat.h"
#include "SchoolDay.h"
#include "SurfReport.h"
#include "SchoolWeek.h"
#include "Lineup.h"
#include "Wrappers.h"


/*
 UDT 1:
 */




/*
 UDT 2:
 */


/*
 UDT 3:
 */



/*
 new UDT 4:
 */




/*
 new UDT 5:
 */





/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
*/
int main()
{
    #include "LeakedObjectDetector.h"

    //Sailboat
    std::cout << "\nSailboat test\n" << std::endl;
    SailboatWrapper laser( new Sailboat() ), rhodes( new Sailboat() );

    rhodes.pointerToSailboat->numOfSails = 2;
    laser.pointerToSailboat->numOfSails = 1;

    std::cout << "Rhodes has " << rhodes.pointerToSailboat->numOfSails << " sails" << std::endl;
    std::cout << "Laser has " << laser.pointerToSailboat->numOfSails << " sails" << std::endl;

    rhodes.pointerToSailboat->sailCheck();
    laser.pointerToSailboat->sailCheck();

    laser.pointerToSailboat->findOppositeTack ( 12 );

    rhodes.pointerToSailboat->trimSail( 15, 12 );
    rhodes.pointerToSailboat->dropAnchor();

    MastWrapper mast1( new Sailboat::Mast() ), mast2( new Sailboat::Mast() );

    mast1.pointerToMast->mastHeight = 14;
    std::cout << "mast1 height: " << mast1.pointerToMast->mastHeight << std::endl;

    mast1.pointerToMast->mastHeightCheck();

    mast1.pointerToMast->reduceSail( 2 );
    std::cout << "mast 1 number of reefs: " << mast1.pointerToMast->numOfReefs << std::endl;

    mast1.pointerToMast->reefCheck();

    mast2.pointerToMast->increaseSail ( 5 );
    mast1.pointerToMast->getHeelDistance ( 2 );

    //SchoolDay
    std::cout << "\nSchoolDay test\n" << std::endl;

    SchoolDayWrapper monday( new SchoolDay() ), tuesday( new SchoolDay() );

    monday.pointerToSchoolDay->dayOfTheWeek = "monday";
    tuesday.pointerToSchoolDay->dayOfTheWeek = "tuesday";
    tuesday.pointerToSchoolDay->length = 6.f;
    monday.pointerToSchoolDay->numberOfKids = 5;
    tuesday.pointerToSchoolDay->halfDay = false;

    monday.pointerToSchoolDay->splitUpClass( 2 );
    std::cout << monday.pointerToSchoolDay->numberOfKids <<" kids in each group " << std::endl;

    monday.pointerToSchoolDay->howManyKids( *monday.pointerToSchoolDay);

    tuesday.pointerToSchoolDay->shortenSchoolDay( 2.f );
    std::cout << "the day is now: " <<tuesday.pointerToSchoolDay->length <<" hours long" << std::endl;

    tuesday.pointerToSchoolDay->dayLengthCheck(*tuesday.pointerToSchoolDay);

    monday.pointerToSchoolDay->sunCameOut();
    if (monday.pointerToSchoolDay->isRaining == false)
    {
        std::cout << "it isn't raining anymore!" << std::endl;
    }

 //SurfReport
    std::cout << "\nSurfReport test\n" << std::endl;

    SurfReportWrapper nov15( new SurfReport() ), nov16( new SurfReport );

    nov15.pointerToSurfReport->waveHeight = 20.f;
    nov16.pointerToSurfReport->waveHeight = 3.f;

    std::cout << "November 15th wave height is: " << nov15.pointerToSurfReport->waveHeight << std::endl;

    nov15.pointerToSurfReport->waveHeightCheck(*nov15.pointerToSurfReport);

    nov15.pointerToSurfReport->increaseWaveHeight( 20.f );

    std::cout << "November 15th wave height is now: " << nov15.pointerToSurfReport->waveHeight << std::endl;

    nov15.pointerToSurfReport->waveHeightCheck(*nov15.pointerToSurfReport);

    nov16.pointerToSurfReport->shouldIGoOut( 8 );
    nov15.pointerToSurfReport->chooseBoardSize();

    SurferWrapper shania( new SurfReport::Surfer() ), cody( new SurfReport::Surfer() );

    shania.pointerToSurfer->levelUp( 3 );
    std::cout << "Shania's level is: " << shania.pointerToSurfer->surferSkill << std::endl;

    shania.pointerToSurfer->surferLevelCheck(*shania.pointerToSurfer);

    cody.pointerToSurfer->getTubed( 4 );
    shania.pointerToSurfer->wipeOut( 10 );




//Lineup
    std::cout << "\nLineup test\n" << std::endl;

    LineupWrapper thursdayAM( new Lineup() ), thursdayPM( new Lineup() );

    thursdayAM.pointerToLineup->getSurferInfo( thursdayAM.pointerToLineup->joe );

    thursdayPM.pointerToLineup->teachASurferToSurf( thursdayPM.pointerToLineup->coretta );

//SchoolWeek
    std::cout << "\nSchoolWeek test\n" << std::endl;

    SchoolWeekWrapper week1( new SchoolWeek() ), week2( new SchoolWeek() );

    week1.pointerToSchoolWeek->makeHalfDay( week1.pointerToSchoolWeek->monday, 2.f );
    std::cout << "monday's length is now: " << week1.pointerToSchoolWeek->monday.length << std::endl;

    //week1.pointerToSchoolWeek->monday.dayLengthCheck();

    week2.pointerToSchoolWeek->snowDay( week2.pointerToSchoolWeek->thursday);

    std::cout << "good to go!" << std::endl;
}

