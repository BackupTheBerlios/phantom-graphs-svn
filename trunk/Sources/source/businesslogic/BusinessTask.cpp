// BusinessTask.cpp: Implementierung der Klasse BusinessTask.
//
//////////////////////////////////////////////////////////////////////

#include "BusinessTask.h"
#include "AppConfiguration.h"

extern AppConfiguration appData;
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

BusinessTask::BusinessTask()
{
	name = (char) "unnamed Task";
	day_begin = 0;
	day_duration = 0;
	day_end = day_begin + day_duration;
	day_final = 0;
	force = 0;
	isMilestone = false;
	surface = 0;
}

BusinessTask::BusinessTask(char taskname, int begin, int duration, int final, bool Milestone)
{
	name = taskname;
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

void BusinessTask::viewToBusinessCoordinates()
{

}

void BusinessTask::businessToViewCoordinates()
{

}

float BusinessTask::getWidth()
{
	width = 1.0;
	return width;
}

float BusinessTask::getHeight()
{
	height = 1.0;
	return height;
}

Position BusinessTask::getPosition()
{
	return position;
}
