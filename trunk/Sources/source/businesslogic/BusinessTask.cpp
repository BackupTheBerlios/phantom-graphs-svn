//*******************************************************************************
/// @file	BusinessTask.cpp
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte �nderung	27.01.2006 CA
//*******************************************************************************

// �nderungen:
// ...
// 24.01.2006	- Liste mit Vorg�ngern hinzugef�gt
//				- Liste mit Nachfolgern hinzugef�gt
//				- Memberfunktion zum hinzuf�gen von Vorg�ngern und Nachfolgern
// 27.01.2006	- �nderung von Memberfunktion zum hinzuf�gen von Vorg�ngern 
//				  und Nachfolgern

#include "BusinessTask.h"
#include "AppConfiguration.h"

extern AppConfiguration appData;
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

BusinessTask::BusinessTask()
{
	m_Name = (char) "unnamed Task";
	m_DayDuration = 0;
	day_final = 0;
	isMilestone = false;

	m_DayBegin = -1;
	day_end = m_DayBegin + m_DayDuration;
	force = 0;
	surface = 0;

	// Nachfolger- und Vorg�ngerlisten l�schen
	m_TasksFollowing.clear();
	m_TasksPrivious.clear();
}

BusinessTask::BusinessTask(string taskname, int duration, int final, bool Milestone)
{
	m_Name = taskname;
	m_DayDuration = duration;
	day_final = final;
	isMilestone = Milestone;

	// m_DayBegin = begin;
	day_end = calcDayEnd(m_DayBegin, m_DayDuration);
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

int BusinessTask::getDuration()
{
	return m_DayDuration;
}

int BusinessTask::getLine()
{
	return m_line;
}

int BusinessTask::getDayBegin()
{
	return m_DayBegin;
}

void BusinessTask::printInfo()
{
	cout << this->m_Name << " dauert " << this->m_DayDuration << " Tage." << endl;
}

string BusinessTask::getName()
{
	return m_Name;
}

void BusinessTask::addTaskFollowing(BusinessTask *followed_by)
{
	m_TasksFollowing.push_back(followed_by);
}

void BusinessTask::addTaskPrevious(BusinessTask *followes)
{
	m_TasksPrivious.push_back(followes);
}
