#include <iostream>
/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) add 2 member functions to each of these 2 new types.
       These member functions should make use of the member variables. 
       Maybe interact with their properties or call their member functions.
       The purpose is to demonstrate that you know how to use a class's member variables and member functions when it is a member of another class.
 
 7) use at least 2 instances of each of your UDTs in main. 
       - call every member function of your UDTs to make sure they work as expected and don't produce warnings.
       - add some std::cout statements in main() that use your UDT's member variables.
       you have 5 UDTs and 2 nested UDTs, so there should be at minimum 14 UDTs declared in main(), as well as 14 * 3 function calls happening.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
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

        void reduceSail( int reefs );
        void increaseSail (int reefs );
        int getHeeldDistance ( int distanceToWater );
    };
    Mast mast;

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
    std::cout << "a Sailboat named" << boatName << "was created" << std::endl; 
}
Sailboat::~Sailboat()
{
    std::cout << "a Sailboat named" << boatName << "was destroyed" << std::endl; 
}
Sailboat::Mast::Mast()
{
    int mastHeight = 14;
    std::cout << "a mast was created" << std::endl;
}

Sailboat::Mast::~Mast()
{
    std::cout << "a mast was destroyed" << std::endl; 
}


Sailboat laser;

int Sailboat::findOppositeTack( int directionInDegrees )
{
    return ( directionInDegrees + 180 ) % 360;
}

void Sailboat::trimSail( int currentTrim, int inchesOfSheet )
{
    if (inchesOfSheet != 0)
    {
        for (int x = 0; x <= inchesOfSheet; x++)
        {
            currentTrim -= inchesOfSheet;
        }
    }
    std::cout << "you have no sheet to trim!" << std::endl; 
}

void Sailboat::dropAnchor()
{
    while (bool isStillFloating = true)
    {
        if (laser.isAnchored == false)
        {
            laser.isAnchored = !laser.isAnchored;
            std::cout << "now you're anchored mate." << std::endl; 
        }
        std::cout << "you're already anchored!" << std::endl; 
    }
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
    struct Child
    {
        Child();
        ~Child();
        int numOfNaps;
        int childAge;
        bool hasLunch;
        bool isDressed;
        bool wearingShoes;

        void goHomeEarly();
        void makeLunch();
        void takeNap();
    };
    Child child;
    bool runningLate;
    bool halfDay = false;
    bool isRaining = false;
    
    void splitUpClass( int numOfGroups );
    void lengthenSchoolDay( float lengthIncrease );
    void sunCameOut();
};
SchoolDay::SchoolDay()
{ 
    dayOfTheWeek = "Monday";
    length = 6.f;
    runningLate = false;
    std::cout << dayOfTheWeek << "was created" << std::endl;

};
SchoolDay::~SchoolDay()
{
    std::cout << dayOfTheWeek << "was destroyed" << std::endl;
};
SchoolDay::Child::Child()
{
    std::cout << "a child aged:" << childAge << "was created" << std::endl;
}
SchoolDay::Child::~Child()
{
    std::cout << "a child aged:" << childAge << "was destroyed" << std::endl;
}

void SchoolDay::splitUpClass(int numOfGroups)
{   
    if (numberOfKids != 0)
    {
        numberOfKids /= 2;
    }
    else
    {
        std::cout << "there are" << numberOfKids << "kids in class!" << std::endl;
    }
}
void SchoolDay::lengthenSchoolDay( float lengthIncrease )
{
    while (halfDay == false)
    {
        length += lengthIncrease;
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
    Surfer s;

    void increaseWaveHeight( float newWaveHeight );
    bool shouldIGoOut( int fatigueLevel );
    float chooseBoardSize();
};

SurfReport::SurfReport()
{
    waveHeight = 3.5;
    wavePeriod = 18.4;
    windDirection = "SSE";
    windSpeed = 10;
    std::cout<< "a SurfReport was created" << std::endl;
}

SurfReport::~SurfReport()
{
    std::cout<< "a SurfReport was destroyed" << std::endl;
}

SurfReport::Surfer::Surfer()
{
    surferAge = 35;
    std::cout<< "a Surfer aged" << surferAge << "was created" << std::endl;
}

SurfReport::Surfer::~Surfer()
{
    std::cout<< "a Surfer aged" << surferAge << "was destroyed" << std::endl;
}

void SurfReport::Surfer::levelUp( int improvementAmount )
{
    if (surferSkill <= 10)
    {
        for (int x = 0; x <= improvementAmount && surferSkill <= 10; x++)

            surferSkill += 1; 
    }
}
void SurfReport::Surfer::getTubed( int currentStokeLevel )
{
    currentStokeLevel += 10; 
    std::cout << "tubed! Stoke level =" << currentStokeLevel << std::endl;
}
void SurfReport::Surfer::wipeOut( int currentStokeLevel )
{
    currentStokeLevel -=10;
    std::cout << "wipeout! Stoke level =" << currentStokeLevel << std::endl;
}

void SurfReport::increaseWaveHeight( float newWaveHeight )
{
    waveHeight = newWaveHeight; 
}
bool SurfReport::shouldIGoOut( int fatigueLevel )
{
    if (fatigueLevel < 10)
    {
        fatigueLevel += 1;
        return true;
    }
    return false;
}
float SurfReport::chooseBoardSize()
{
    float boardLength = 8.f;
    for (float x = 0.f; x <= waveHeight; x+=1.f)
    {
        if (boardLength > 5.0)
        {
            boardLength -= .5;
        }
    }
    return boardLength;
}

/*
 new UDT 4:
 */
struct Lineup
{
    Lineup();
    ~Lineup();
    SurfReport::Surfer joe{ };
    SurfReport::Surfer madeline{};
    SurfReport::Surfer coretta{};
    SurfReport tuesday{};
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
/*
 new UDT 5:
 */
struct SchoolWeek 
{
    SchoolWeek();
    ~SchoolWeek();
    SchoolDay monday{};
    SchoolDay tuesday{};
    SchoolDay wednesday{};
    SchoolDay thursday{};
    SchoolDay friday{};
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
    std::cout << "good to go!" << std::endl;
}
