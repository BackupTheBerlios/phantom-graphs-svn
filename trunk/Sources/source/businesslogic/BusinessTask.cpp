//*******************************************************************************
/// @file	BusinessTask.cpp
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	30.01.2006 CA
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
// 29.01.2006	- added: moveToFront() CA
// 30.01.2006	- modified: getForce(int,int) CA
//				- added: enum force CA
//				- modified: moveToFront(), moveFollowingToFront(), 
//				  movePreviousToFront() CA
//				- modified calcRanges() CA
				



#include "BusinessTask.h"
#include "AppConfiguration.h"
#include <stdio.h>

extern AppConfiguration appData;
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

BusinessTask::BusinessTask()
{
	m_Name = (char) "unnamed Task";
	m_Width = 0;
	m_Final = 0;
	isMilestone = false;

	m_Begin = 0;
	m_End = m_Begin + m_Width;
	m_Force = none;
	surface = 0;

	// Nachfolger- und Vorgängerlisten löschen
	m_TasksFollowing.clear();
	m_TasksPrevious.clear();
}

BusinessTask::BusinessTask(string taskname, int duration, int final, bool Milestone)
{
	m_Name = taskname;
	m_Width = duration;
	m_Final = final;
	isMilestone = Milestone;

	// m_DayBegin = begin;
	// m_End = calcDayEnd(m_Begin, m_Width);
	
	/* Berechne Anfang und Ende der Aufgabe*/
	m_Begin = calcBegin(m_Final, m_Width);
	m_End = calcEnd(m_Begin, m_Width);

	m_Force = none;
	surface = 0;

	// Nachfolger- und Vorgängerlisten löschen
	m_TasksFollowing.clear();
	m_TasksPrevious.clear();
}


BusinessTask::~BusinessTask()
{

}

force BusinessTask::getForce(float x_float, float y_float)
{
	int x = m_Begin + (int) x_float;
	
	if ( ((m_ForceRangeIncredible0 < x) && (x < m_ForceRangeMedium0)) ||
		 ((m_ForceRangeMedium1 < x) || x < (m_ForceRangeIncredible1)))
	{
		m_Force = medium;
	}
	else if ((m_ForceRangeMedium0 < x) && (x < m_ForceRangeMedium1)) m_Force = none;
	else
	{
		m_Force = incredible;
	}
	
	return m_Force;
}

int BusinessTask::calcEnd(int begin, int duration)
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

int BusinessTask::getEnd()
{
	return m_End;
}

void BusinessTask::printInfo()
{
	cout << this->m_Name << " dauert " << this->m_Width << " Tage, beginnt am " << m_Begin << ". und endet am " << m_End << ". Tag" << endl;
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
	int new_begin = 0;
	int previous_end = 0;

	// float begin_neu = runden(begin, 1);
	if (begin < m_Begin)
	{
		moveToEarlierPosition(begin);
	}

	// m_Begin = (int)begin;

	/* Ende neu setzen nach Änderung des Beginns */
	m_End = calcEnd(m_Begin, m_Width);
	
	/* Meldung nach Änderng */

	
	this->NotifyAll();
	
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

void BusinessTask::moveAllToFront()
{
	moveFollowingToFront(m_End);
	movePreviousToFront();
}

void BusinessTask::movePreviousToFront()
{
	list<IBusinessAdapter*>::iterator itObj;

	/* Durchlaufe die Vorgänger und schiebe sie vom ersten Vorgänger an gesehen
	 * so weit wie möglich an den Begin des Projektzeitraums */
	for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			/* Rekursiv alle Vorgänger durchlaufen*/
			(*itObj)->movePreviousToFront();


			/* Berechnung des frühesten Anfangs */
			int maxDay = 0;

			list<IBusinessAdapter*>::iterator prevObj;

			for (prevObj = m_TasksPrevious.begin() ; prevObj != m_TasksPrevious.end(); prevObj++)
			{
				if (*prevObj != NULL)
				{
					/* Ende der vorherigen Aufgabe */
					int end = (*prevObj)->getBegin() + (*prevObj)->getWidth();

					if ( end <= m_Begin && end > maxDay)
					{
						maxDay = end;
					}
				}
			}

			/* setzte neuen Begin der Aufgabe auf folge Tag der spätesten 
			 * vorherigen Aufgabe */
			setBegin( (float)(maxDay + 0) );
		}
		else setBegin(0);
	}


}

void BusinessTask::moveFollowingToFront(int earliest)
{

	/* Berechnung des frühesten Anfangs */
	int endPrevDay = earliest;

			if ( endPrevDay <= m_Begin)
			{
				/* setzte neuen Begin der Aufgabe auf folge Tag der spätesten 
				 * vorherigen Aufgabe */
				setBegin( (float)(endPrevDay + 0) );
			}

	list<IBusinessAdapter*>::iterator itObj;

	/* Durchlaufe die Nachfolger und schiebe sie vom ersten Nachfolger an gesehen
	 * so weit wie möglich an den Begin des Projektzeitraums */
	for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			/* Rekursiv alle Nachfolger durchlaufen*/
			(*itObj)->moveFollowingToFront(m_End);
		}
	}
}

void BusinessTask::calcRanges()
{
	calcForceMedium0();
	calcForceMedium1();
	m_ForceRangeIncredible0 = calcForceInc0() - m_Width;
	m_ForceRangeIncredible1 = calcForceInc1();
}

int BusinessTask::calcForceInc0()
{
	int test = 0;
	int range = 0;

	/* Durchlaufe die Vorgänger  */
	list<IBusinessAdapter*>::iterator itObj;
	for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			test = (*itObj)->calcForceInc0();
			if (test > range) range = test;
		}
		
	}
	return (m_Width + range);
}

int BusinessTask::calcForceInc1()
{
	int test = 0;
	int range = appData.getProjectDuration();

	if (m_Final > 0)
	{
		return (m_Final - m_Width);
	}
	else {

		/* Durchlaufe die Vorgänger  */
		list<IBusinessAdapter*>::iterator itObj;
		for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
		{
			if (*itObj != NULL)
			{
				test = (*itObj)->calcForceInc1();
				if (test < range) range = test;
			}			
		}
		return (range - m_Width);
	}
}


void BusinessTask::calcForceMedium0()
{
	int range = 0;
	int test = 0;

	/* Suche erste Bewegungseinschränkung Previous */
	list<IBusinessAdapter*>::iterator itObj;
	for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			test = (*itObj)->getBegin() + (*itObj)->getWidth();
			if (test > range) range = test;
		}
	}
	m_ForceRangeMedium0 = range + 1;
}

void BusinessTask::calcForceMedium1()
{
	int range = appData.getProjectDuration();
	int test = 0;

	/* Suche erste Bewegungseinschränkung Following */
	list<IBusinessAdapter*>::iterator itObj;
	for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			test = (*itObj)->getBegin();
			if (test < range) range = test;
		}
	}

	m_ForceRangeMedium0 = range - m_Width - 1;
}


int BusinessTask::moveToEarlierPosition(int new_begin)
{
	int test = 0;
	int range = 0;

	if(new_begin < m_ForceRangeIncredible0)
	{
		movePreviousToFront();
		m_Begin = m_ForceRangeIncredible0;
	}
	else if(m_ForceRangeIncredible0 < new_begin && new_begin < m_ForceRangeMedium0)
	{
		/* Durchlaufe die Vorgänger  */
		list<IBusinessAdapter*>::iterator itObj;
		for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
		{
			if (*itObj != NULL)
			{
				if ( new_begin < ((*itObj)->getBegin() + (*itObj)->getWidth()) )
				{
					(*itObj)->moveToEarlierPosition(new_begin - (*itObj)->getWidth());
				}
			}
			
		}
		m_Begin = new_begin;

	}
	else
	{
		m_Begin = new_begin;
	}

	return 0;

}
