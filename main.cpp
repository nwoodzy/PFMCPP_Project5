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

/*
 UDT 1:
 */
struct Sailboat 
{
    Sailboat();
    ~Sailboat();

    std::string boatName;
    struct Mast
    {
        Mast();
        ~Mast();

        int mastHeight;
        int boomLength = 109;
        bool isBermudaRig = true;
        bool isLateen = false;
        bool isStepped = true;
        int numOfReefs = 0;
        int numOfTotalReefs = 4;

        void mastHeightCheck()
        {
            std::cout << "mast height: " << this->mastHeight << std::endl;
        }
        void reefCheck()
        {
            std::cout << "number of reefs: " << this->numOfReefs << std::endl;
        }
        void reduceSail( int reefs );
        void increaseSail (int reefs );
        int getHeelDistance ( int distanceToWater );
    };

    int numOfSails;
    float length = 13.8f;
    bool isAnchored = false;
    float sailArea = 50.6f;
    bool hasKeel;
    bool isStillFloating = true;
    
    void sailCheck()
    {
        std::cout << "Sailboat has " << this->numOfSails << " sails" << std::endl;
    }
    int findOppositeTack ( int directionInDegrees );
    void trimSail( int currentTrim, int inchesOfSheet );
    void dropAnchor();
    JUCE_LEAK_DETECTOR(Sailboat)
};
Sailboat::Sailboat()
{
    numOfSails = 1;
    hasKeel = false;
    std::cout << "a Sailboat was created" << std::endl; 
}
Sailboat::~Sailboat()
{
    std::cout << "a Sailboat named was destroyed" << std::endl; 
}
Sailboat::Mast::Mast()
{
    mastHeight = 14;
    std::cout << "a mast was created" << std::endl;
}

Sailboat::Mast::~Mast()
{
    std::cout << "a mast was destroyed" << std::endl; 
}

struct SailboatWrapper
{
    SailboatWrapper( Sailboat* ptr ) : pointerToSailboat( ptr ) {}
    ~SailboatWrapper()
    {
        delete pointerToSailboat;
    }

    Sailboat* pointerToSailboat = nullptr;
};

struct MastWrapper 
{
    MastWrapper( Sailboat::Mast* ptr ) : pointerToMast( ptr ) {}
    ~MastWrapper()
    {
        delete pointerToMast;
    }
    Sailboat::Mast* pointerToMast = nullptr;
};

int Sailboat::findOppositeTack( int directionInDegrees )
{
    int x = ( directionInDegrees + 180 ) % 360;
    std::cout << "your new heading is " << x << "degrees" << std::endl;
    return x;
}

void Sailboat::trimSail( int currentTrim, int inchesOfSheet )
{
    if (inchesOfSheet != 0)
    {
        for (int x = 0; x <= inchesOfSheet; ++x)
        {
            currentTrim -= inchesOfSheet;
        }
    }
    std::cout << "you have no sheet to trim!" << std::endl; 
}

void Sailboat::dropAnchor()
{
    if (isAnchored == false)
    {
        isAnchored = true;
        std::cout << "now you're anchored mate." << std::endl; 
    }
    else
    {
        std::cout << "you're already anchored!" << std::endl; 
    }
}
void Sailboat::Mast::reduceSail( int reefs )
{
    if (numOfReefs != numOfTotalReefs)
    {
        int i = numOfReefs;
        i += reefs;
        numOfReefs = i;
    }
    else 
    {
        std::cout << "you can't take that many reefs!" << std::endl;
    }
}
void Sailboat::Mast::increaseSail (int reefs )
{
    if ( numOfTotalReefs == 0 )
    {
        std::cout << "you're sail is all the way up already!" << std::endl;
    }
    if ( reefs > numOfTotalReefs  )
    {
        numOfReefs = numOfTotalReefs;
    }
    else 
    {
        int i = numOfReefs;
        i -= reefs;
        numOfReefs = i;
    }
}
int Sailboat::Mast::getHeelDistance ( int distanceToWater )
{
    int x = mastHeight - distanceToWater;
    std::cout << "Heel distance is: " << x << std::endl;
    return x;
}

/*
 UDT 2:
 */
struct SchoolDay
{   
    SchoolDay();
    ~SchoolDay();
    std::string dayOfTheWeek;
    float length;
    int numberOfKids = 15;
    bool runningLate;
    bool halfDay = false;
    bool isRaining = false;

    void dayLengthCheck()
    {
        std::cout << "the day is now: " <<this->length <<" hours long" << std::endl;
    }
    void howManyKids()
    {
        std::cout << this->numberOfKids <<" kids in each group " << std::endl;
    }
    void splitUpClass( int numOfGroups );
    void shortenSchoolDay( float lengthDecrease );
    void sunCameOut();
    JUCE_LEAK_DETECTOR(SchoolDay)
};
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

struct SchoolDayWrapper
{
    SchoolDayWrapper( SchoolDay* ptr ) : pointerToSchoolDay( ptr ) {}
    ~SchoolDayWrapper()
    {
        delete pointerToSchoolDay;
    }

    SchoolDay* pointerToSchoolDay = nullptr;
};

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

/*
 UDT 3:
 */
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

struct SurfReportWrapper
{
    SurfReportWrapper( SurfReport* ptr ) : pointerToSurfReport( ptr ) {}
    ~SurfReportWrapper()
    {
        delete pointerToSurfReport;
    }

    SurfReport* pointerToSurfReport = nullptr;
};

struct SurferWrapper
{
    SurferWrapper( SurfReport::Surfer* ptr ) : pointerToSurfer( ptr ){}
    ~SurferWrapper()
    {
        delete pointerToSurfer;
    }

    SurfReport::Surfer* pointerToSurfer = nullptr;
};

void SurfReport::Surfer::levelUp( int improvementAmount )
{
    if (surferSkill <= 10)
    {
        for (int x = 0; x <= improvementAmount && surferSkill <= 10; ++x)
        {
            int i = surferSkill;
            ++i;
            surferSkill = i;
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
        int i = fatigueLevel;
        ++i;
        fatigueLevel = i;
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

/*
 new UDT 4:
 */
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

Lineup::Lineup()
{
    std::cout << "a new Lineup was created" << std::endl;
}

Lineup::~Lineup()
{
    std::cout << "a Lineup was destroyed" << std::endl;
    tuesday.isBusy = false;
}

struct LineupWrapper
{
    LineupWrapper( Lineup* ptr ) : pointerToLineup( ptr ) {}
    ~LineupWrapper()
    {
        delete pointerToLineup;
    }
    Lineup* pointerToLineup = nullptr;
};

void Lineup::getSurferInfo( SurfReport::Surfer surfer ) 
{
    if ( surfer.atBeach == true)
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
    
    if ( surfer.havingLesson == true)
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
/*
 new UDT 5:
 */
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

struct SchoolWeekWrapper
{
    SchoolWeekWrapper( SchoolWeek* ptr ) : pointerToSchoolWeek ( ptr ) {}
    ~SchoolWeekWrapper()
    {
        delete pointerToSchoolWeek;
    }
    SchoolWeek* pointerToSchoolWeek = nullptr;
};

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

    Sailboat::Mast mast1, mast2;
    
    mast1.mastHeight = 14;
    std::cout << "mast1 height: " << mast1.mastHeight << std::endl;

    mast1.mastHeightCheck();

    mast1.reduceSail( 2 );
    std::cout << "mast 1 number of reefs: " << mast1.numOfReefs << std::endl;

    mast1.reefCheck();

    mast2.increaseSail ( 5 );
    mast1.getHeelDistance ( 2 );

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

    monday.pointerToSchoolDay->howManyKids();

    tuesday.pointerToSchoolDay->shortenSchoolDay( 2.f );
    std::cout << "the day is now: " <<tuesday.pointerToSchoolDay->length <<" hours long" << std::endl;

    tuesday.pointerToSchoolDay->dayLengthCheck();

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

    nov15.pointerToSurfReport->waveHeightCheck();

    nov15.pointerToSurfReport->increaseWaveHeight( 20.f );

    std::cout << "November 15th wave height is now: " << nov15.pointerToSurfReport->waveHeight << std::endl;

    nov15.pointerToSurfReport->waveHeightCheck();

    nov16.pointerToSurfReport->shouldIGoOut( 8 );
    nov15.pointerToSurfReport->chooseBoardSize();

    SurfReport::Surfer shania, cody;

    shania.levelUp( 3 );
    std::cout << "Shania's level is: " << shania.surferSkill << std::endl;

    shania.surferLevelCheck();

    cody.getTubed( 4 );
    shania.wipeOut( 10 );




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

    week1.pointerToSchoolWeek->monday.dayLengthCheck();

    week2.pointerToSchoolWeek->snowDay( week2.pointerToSchoolWeek->thursday);

    std::cout << "good to go!" << std::endl;
}

