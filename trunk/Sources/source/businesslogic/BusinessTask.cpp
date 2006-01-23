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
	day_duration = 0;
	day_final = 0;
	isMilestone = false;

	day_begin = -1;
	day_end = day_begin + day_duration;
	force = 0;
	surface = 0;
}

BusinessTask::BusinessTask(string taskname, int duration, int final, bool Milestone)
{
	name = taskname;
	day_duration = duration;
	day_final = final;
	isMilestone = Milestone;

	// day_begin = begin;
	day_end = calcDayEnd(day_begin, day_duration);
	force = 0;
	surface = 0;
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

void BusinessTask::printInfo()
{
	cout << this->name << " dauert " << this->day_duration << " Tage." << endl;
	//printf("\n\n \n\n");
}
