// BusinessTask.cpp: Implementierung der Klasse BusinessTask.
//
//////////////////////////////////////////////////////////////////////

#include "BusinessTask.h"

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

BusinessTask::BusinessTask()
{
	day_begin = 0;
	day_duration = 0;
	day_end = day_begin + day_duration;
	day_final = 0;
	force = 0;
	isMilestone = false;
	surface = 0;
}

BusinessTask::BusinessTask(int begin, int duration, int final, bool Milestone)
{
	day_begin = begin;
	day_duration = duration;
	day_final = final;
	isMilestone = Milestone;
	day_end = calcDayEnd(day_begin, day_duration);
}


BusinessTask::~BusinessTask()
{

}

int BusinessTask::getForce()
{
	return force;
}

int BusinessTask::calcDayEnd(int begin, int duration)
{
	int end;
	end = 0;
	end = begin + duration;
	
	return end;
}
