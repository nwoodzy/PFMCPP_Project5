#pragma once

#include "SurfReport.h"
#include "Sailboat.h"
struct Sailboat;
struct Mast;
struct SchoolDay;
struct SchoolWeek;
struct SurfReport;
struct Surfer;
struct Lineup;

struct SailboatWrapper
{
    SailboatWrapper( Sailboat* ptr );
    ~SailboatWrapper();

    Sailboat* pointerToSailboat = nullptr;
};

struct MastWrapper 
{
    MastWrapper( Sailboat::Mast* ptr );
    ~MastWrapper();

    Sailboat::Mast* pointerToMast = nullptr;
};

struct SchoolDayWrapper
{
    SchoolDayWrapper( SchoolDay* ptr );
    ~SchoolDayWrapper();

    SchoolDay* pointerToSchoolDay = nullptr;
};

struct SurfReportWrapper
{
    SurfReportWrapper( SurfReport* ptr );
    ~SurfReportWrapper();

    SurfReport* pointerToSurfReport = nullptr;
};

struct SurferWrapper
{
    SurferWrapper( SurfReport::Surfer* ptr );
    ~SurferWrapper();

    SurfReport::Surfer* pointerToSurfer = nullptr;
};

struct LineupWrapper
{
    LineupWrapper( Lineup* ptr );
    ~LineupWrapper();

    Lineup* pointerToLineup = nullptr;
};

struct SchoolWeekWrapper
{
    SchoolWeekWrapper( SchoolWeek* ptr );
    ~SchoolWeekWrapper();
    
    SchoolWeek* pointerToSchoolWeek = nullptr;
};
