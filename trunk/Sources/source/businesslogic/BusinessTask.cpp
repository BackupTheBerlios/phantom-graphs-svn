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
	m_Name = (char) "unnamed Task";
	day_duration = 0;
	day_final = 0;
	isMilestone = false;

	m_DayBegin = -1;
	day_end = m_DayBegin + day_duration;
	force = 0;
	surface = 0;

	// Nachfolger- und Vorgängerlisten löschen
	m_TasksFollowing.clear();
	m_TasksPrivious.clear();
}

BusinessTask::BusinessTask(string taskname, int duration, int final, bool Milestone)
{
	m_Name = taskname;
	day_duration = duration;
	day_final = final;
	isMilestone = Milestone;

	// m_DayBegin = begin;
	day_end = calcDayEnd(m_DayBegin, day_duration);
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
	cout << this->m_Name << " dauert " << this->day_duration << " Tage." << endl;
}

string BusinessTask::getName()
{
	return m_Name;
}

void BusinessTask::addTaskFollowing(BusinessTask)
{

}

void BusinessTask::addTaskPrevious(BusinessTask)
{

}
