#include "Wrappers.h"
#include "Sailboat.h"
#include "SchoolDay.h"
#include "SurfReport.h"
#include "SchoolWeek.h"
#include "Lineup.h"

SailboatWrapper::SailboatWrapper( Sailboat* ptr ) : pointerToSailboat( ptr ) {}

SailboatWrapper::~SailboatWrapper()
{
    delete pointerToSailboat;
}

MastWrapper::MastWrapper( Mast* ptr ) : pointerToMast( ptr ) {}

MastWrapper::~MastWrapper()
{
    delete pointerToMast;
}

SchoolDayWrapper::SchoolDayWrapper( SchoolDay* ptr ) : pointerToSchoolDay( ptr ) {}

SchoolDayWrapper::~SchoolDayWrapper()
{
    delete pointerToSchoolDay;
}


SurfReportWrapper::SurfReportWrapper( SurfReport* ptr ) : pointerToSurfReport( ptr ) {}

SurfReportWrapper::~SurfReportWrapper()
{
    delete pointerToSurfReport;
}


SurferWrapper::SurferWrapper( Surfer* ptr ) : pointerToSurfer( ptr ){}

SurferWrapper::~SurferWrapper()
{
    delete pointerToSurfer;
}


LineupWrapper::LineupWrapper( Lineup* ptr ) : pointerToLineup( ptr ) {}

LineupWrapper::~LineupWrapper()
{
    delete pointerToLineup;
}


SchoolWeekWrapper::SchoolWeekWrapper( SchoolWeek* ptr ) : pointerToSchoolWeek ( ptr ) {}

SchoolWeekWrapper::~SchoolWeekWrapper()
{
    delete pointerToSchoolWeek;
}
