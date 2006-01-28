//*******************************************************************************
/// @file	BusinessTask.cpp
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	28.01.2006 CA
//*******************************************************************************

// Änderungen:
// ...
// 24.01.2006	- Liste mit Vorgängern hinzugefügt CA
//				- Liste mit Nachfolgern hinzugefügt CA
//				- Memberfunktion zum hinzufügen von Vorgängern und Nachfolgern CA
// 27.01.2006	- Änderung von Memberfunktion zum hinzufügen von Vorgängern 
//				  und Nachfolgern CA
// 28.01.2006	- m_Width umdefiniert CA
//				- update: setLine() CA
//				- added:
//					getNextTasks()
//					getPreviousTasks()
//				- added: setBegin(float)
//				- added: calcBegin()


#include "BusinessTask.h"
#include "AppConfiguration.h"

extern AppConfiguration appData;
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

BusinessTask::BusinessTask()
{
	m_Name = (char) "unnamed Task";
	m_Width = 0;
	day_final = 0;
	isMilestone = false;

	m_Begin = -1;
	day_end = m_Begin + m_Width;
	force = 0;
	surface = 0;

	// Nachfolger- und Vorgängerlisten löschen
	m_TasksFollowing.clear();
	m_TasksPrevious.clear();
}

BusinessTask::BusinessTask(string taskname, int duration, int final, bool Milestone)
{
	m_Name = taskname;
	m_Width = duration;
	day_final = final;
	isMilestone = Milestone;

	// m_DayBegin = begin;
	// day_end = calcDayEnd(m_Begin, m_Width);
	
	/* Berechne den Anfang der Aufgabe*/
	m_Begin = calcBegin(final, duration);

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

int BusinessTask::getWidth()
{
	return m_Width;
}

int BusinessTask::getLine()
{
	return m_Line;
}

int BusinessTask::getBegin()
{
	return m_Begin;
}

void BusinessTask::printInfo()
{
	cout << this->m_Name << " dauert " << this->m_Width << " Tage." << endl;
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
	m_TasksPrevious.push_back(followes);
}

list<IBusinessAdapter*>&  BusinessTask::getNextTasks()
{
	return m_TasksFollowing;
}

list<IBusinessAdapter*>&  BusinessTask::getPreviousTasks()
{
	return m_TasksPrevious;
}

void BusinessTask::setLine(int line)
{
	m_Line = line;
}

bool BusinessTask::setBegin(float begin)
{
	float begin_neu = runden(begin, 1);
	m_Begin = begin_neu;
	return true;
}


float BusinessTask::runden(float value, int nachkommastellen)
{
	// return ( (float) ( (long) (f * 100 + 0.5) ) ) / 100;
	return ( (float) ( (long) (value * nachkommastellen) ) ) / nachkommastellen;
}

int BusinessTask::calcBegin(int end, int duration)
{
	int begin;
	begin = end - duration;
	return begin;
}
