#include <iostream>
#include "LeakedObjectDetector.h"
/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
#endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





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
    Sailboat laser, rhodes;

    rhodes.numOfSails = 2;
    laser.numOfSails = 1;

    std::cout << "Rhodes has " << rhodes.numOfSails << " sails" << std::endl;
    std::cout << "Laser has " << laser.numOfSails << " sails" << std::endl;

    rhodes.sailCheck();
    laser.sailCheck();

    laser.findOppositeTack ( 12 );

    rhodes.trimSail( 15, 12 );
    rhodes.dropAnchor();

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

    SchoolDay monday, tuesday;

    monday.dayOfTheWeek = "monday";
    tuesday.dayOfTheWeek = "tuesday";
    tuesday.length = 6.f;
    monday.numberOfKids = 5;
    tuesday.halfDay = false;

    monday.splitUpClass( 2 );
    std::cout << monday.numberOfKids <<" kids in each group " << std::endl;

    monday.howManyKids();

    tuesday.shortenSchoolDay( 2.f );
    std::cout << "the day is now: " <<tuesday.length <<" hours long" << std::endl;

    tuesday.dayLengthCheck();

    monday.sunCameOut();
    if (monday.isRaining == false)
    {
        std::cout << "it isn't raining anymore!" << std::endl;
    }

 //SurfReport
    std::cout << "\nSurfReport test\n" << std::endl;

    SurfReport nov15, nov16;

    nov15.waveHeight = 20.f;
    nov16.waveHeight = 3.f;

    std::cout << "November 15th wave height is: " << nov15.waveHeight << std::endl;

    nov15.waveHeightCheck();

    nov15.increaseWaveHeight( 20.f );

    std::cout << "November 15th wave height is now: " << nov15.waveHeight << std::endl;

    nov15.waveHeightCheck();

    nov16.shouldIGoOut( 8 );
    nov15.chooseBoardSize();

    SurfReport::Surfer shania, cody;

    shania.levelUp( 3 );
    std::cout << "Shania's level is: " << shania.surferSkill << std::endl;

    shania.surferLevelCheck();

    cody.getTubed( 4 );
    shania.wipeOut( 10 );




//Lineup
    std::cout << "\nLineup test\n" << std::endl;

    Lineup thursdayAM, thursdayPM;

    thursdayAM.getSurferInfo( thursdayAM.joe );

    thursdayPM.teachASurferToSurf( thursdayPM.coretta );

//SchoolWeek
    std::cout << "\nSchoolWeek test\n" << std::endl;

    SchoolWeek week1, week2;

    week1.makeHalfDay( week1.monday, 2.f );
    std::cout << "monday's length is now: " << week1.monday.length << std::endl;

    week1.monday.dayLengthCheck();

    week2.snowDay( week2.thursday);

    std::cout << "good to go!" << std::endl;
}

