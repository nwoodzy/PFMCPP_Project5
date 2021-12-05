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
    ~Sailboat(){}

    std::string boatName;
    struct Mast
    {
        Mast();
        ~Mast(){};

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

    int numOfSails = 1;
    float length = 13.8f;
    bool isAnchored = false;
    float sailArea = 50.6f;
    bool hasKeel = false;
    
    int findOppositeTack ( int directionInDegrees );
    void trimSail( int inchesOfSheet );
    void dropAnchor();
};
Sailboat::Sailboat()
{
    int mastHeight = 14;
    std::cout << "a Sailboat was created" << std::endl; 
}
Sailboat::~Sailboat()
{
    std::cout << "a Sailboat was destroyed" << std::endl; 
}

Sailboat laser;

float findOppositeTack( int directionInDegrees )
{
    return ( directionInDegrees + 180 ) % 360;
}

void trimSail( int currentTrim, int inchesOfSheet )
{
    if (inchesOfSheet != 0)
    {
        currentTrim -= inchesOfSheet;
    }
    std::cout << "you have no sheet to trim!" << std::endl; 
}

void dropAnchor()
{
    if (laser.isAnchored == false)
    {
        laser.isAnchored = !laser.isAnchored;
        std::cout << "now you're anchored mate." << std::endl; 
    }
    std::cout << "you're already anchored!" << std::endl; 
}
/*
 UDT 2:
 */
struct SchoolDay
{   
    std::string dayOfTheWeek;
    float length;
    int numberOfKids;
    struct Child
    {
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
    bool halfDay;
    bool isRaining;
    
    void splitUpClass( int numOfGroups );
    void lengthenSchoolDay( float lengthIncrease );
    void sunCameOut();
};
SchoolDay::SchoolDay()
{

};
SchoolDay schoolday;
/*
 UDT 3:
 */
struct SurfReport
{
    float waveHeight;
    float wavePeriod;
    std::string windDirection;
    int windSpeed;
    bool isRaining;
    bool isBusy;
    struct Surfer
    {
        bool atBeach;
        int surferAge;
        int surferSkill;
        float boardSize;
        bool havingLesson;

        void levelUp( int improvementAmount );
        int getTubed( int currentStokeLevel );
        int wipeOut( int currentStokeLevel );
    };
    Surfer s;
    void increaseWaveHeight( float newWaveHeight );
    bool shouldIGoOut( int fatigueLevel );
    float chooseBoardSize();
};
SurfReport surfReport;

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
