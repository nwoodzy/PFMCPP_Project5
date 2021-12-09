/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        // even though I chose the name 'memberFunc' for this function, you should NAME THINGS WHAT THEY ARE OR WHAT THEY DO.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
    
    int findOppositeTack ( int directionInDegrees );
    void trimSail( int currentTrim, int inchesOfSheet );
    void dropAnchor();
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
    void splitUpClass( int numOfGroups );
    void shortenSchoolDay( float lengthDecrease );
    void sunCameOut();
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

        void levelUp( int improvementAmount );
        void getTubed( int currentStokeLevel );
        void wipeOut( int currentStokeLevel );
    };

    void increaseWaveHeight( float newWaveHeight );
    bool shouldIGoOut( int fatigueLevel );
    float chooseBoardSize();
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
    //Sailboat
    std::cout << "\nSailboat test\n" << std::endl;
    Sailboat laser, rhodes;

    rhodes.numOfSails = 2;
    laser.numOfSails = 1;

    std::cout << "Rhodes has " << rhodes.numOfSails << " sails" << std::endl;
    std::cout << "Laser has " << laser.numOfSails << " sails" << std::endl;

    laser.findOppositeTack ( 12 );

    rhodes.trimSail( 15, 12 );
    rhodes.dropAnchor();

    Sailboat::Mast mast1, mast2;
    
    mast1.mastHeight = 14;
    std::cout << "mast1 height: " << mast1.mastHeight << std::endl;

    mast1.reduceSail( 2 );
    std::cout << "mast 1 number of reefs: " << mast1.numOfReefs << std::endl;
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
    tuesday.shortenSchoolDay( 2.f );
    std::cout << "the day is now: " <<tuesday.length <<" hours long" << std::endl;
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

    nov15.increaseWaveHeight( 20.f );

    std::cout << "November 15th wave height is now: " << nov15.waveHeight << std::endl;

    nov16.shouldIGoOut( 8 );
    nov15.chooseBoardSize();

    SurfReport::Surfer shania, cody;

    shania.levelUp( 3 );
    std::cout << "Shania's level is: " << shania.surferSkill << std::endl;
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

    week2.snowDay( week2.thursday);

    std::cout << "good to go!" << std::endl;
}

