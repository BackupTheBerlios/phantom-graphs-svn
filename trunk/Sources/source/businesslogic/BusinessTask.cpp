//*******************************************************************************
/// @file	BusinessTask.cpp
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte �nderung	30.01.2006 CA
//*******************************************************************************

// �nderungen:
// ...
// 24.01.2006	- Liste mit Vorg�ngern hinzugef�gt CA
//				- Liste mit Nachfolgern hinzugef�gt CA
//				- Memberfunktion zum hinzuf�gen von Vorg�ngern und Nachfolgern CA
// 27.01.2006	- �nderung von Memberfunktion zum hinzuf�gen von Vorg�ngern 
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

	// Nachfolger- und Vorg�ngerlisten l�schen
	m_TasksFollowing.clear();
	m_TasksPrevious.clear();
	m_Movement = 0;
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

	// Nachfolger- und Vorg�ngerlisten l�schen
	m_TasksFollowing.clear();
	m_TasksPrevious.clear();
	m_Movement = 0;
}


BusinessTask::~BusinessTask()
{

}

force BusinessTask::getForce(float x_float, float y_float)
{
	float x = 0.0;

	/* akkumulierte Bewegung aufzeichen
	 * wird in setBegin() wieder genullt */
	m_Movement = m_Movement + x_float;
	x = m_Movement + m_Begin;

	
	if ((m_ForceRangeMedium0 < x) && (x < m_ForceRangeMedium1))
	{
		m_Force = none;
	}
	else if((x < m_ForceRangeIncredible0) || (m_ForceRangeIncredible1 < x))
	{
		m_Force = incredible;
	}
	else
	{
		m_Force = medium;
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
	cout << this->m_Name << " Dauer: " << this->m_Width << " Beginn: ";
	cout << m_Begin << " Endet:" << m_End << " Final: " << m_Final;
	cout << " Forces: " << m_ForceRangeIncredible0 << " " << m_ForceRangeMedium0;
	cout << " " << m_ForceRangeMedium1 << " " << m_ForceRangeIncredible1 << endl;
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
	int new_begin = begin;

	/* wenn der neue Starttermin fr�her liegt */
	if (new_begin < m_Begin)
	{
		moveToEarlierPosition(new_begin);
	}
	/* wenn der neue Starttermin sp�ter liegt */
	else if (new_begin > m_Begin)
	{
		moveToLaterPosition(new_begin);
	}

	/* Ende neu setzen nach �nderung des Begin */
	m_End = calcEnd(m_Begin, m_Width);
	calcRanges();

	/* akkumulierte Bewegungen aus getForce() zur�cksetzen */
	m_Movement = 0;
	
	/* Meldung nach �nderng */
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

	/* Durchlaufe die Vorg�nger und schiebe sie vom ersten Vorg�nger an gesehen
	 * so weit wie m�glich an den Begin des Projektzeitraums */
	for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			/* Rekursiv alle Vorg�nger durchlaufen*/
			(*itObj)->movePreviousToFront();


			/* Berechnung des fr�hesten Anfangs */
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

			/* setzte neuen Begin der Aufgabe auf folge Tag der sp�testen 
			 * vorherigen Aufgabe */
			m_Begin = (float)(maxDay + 0) ;
			m_End = calcEnd(m_Begin, m_Width);
		}
		else m_Begin = 0;
		m_End = calcEnd(m_Begin, m_Width);
	}


}

void BusinessTask::moveFollowingToFront(int earliest)
{

	/* Berechnung des fr�hesten Anfangs */
	int endPrevDay = earliest;

			if ( endPrevDay <= m_Begin)
			{
				/* setzte neuen Begin der Aufgabe auf folge Tag der sp�testen 
				 * vorherigen Aufgabe */
				m_Begin = (float)(endPrevDay + 0);
				m_End = calcEnd(m_Begin, m_Width);
			}

	list<IBusinessAdapter*>::iterator itObj;

	/* Durchlaufe die Nachfolger und schiebe sie vom ersten Nachfolger an gesehen
	 * so weit wie m�glich an den Begin des Projektzeitraums */
	for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			/* Rekursiv alle Nachfolger durchlaufen*/
			(*itObj)->moveFollowingToFront(endPrevDay + m_Width);
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

	/* Durchlaufe die Vorg�nger  */
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

		/* Durchlaufe die Vorg�nger  */
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

	/* Suche erste Bewegungseinschr�nkung Previous */
	list<IBusinessAdapter*>::iterator itObj;
	for (itObj = m_TasksPrevious.begin() ; itObj != m_TasksPrevious.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			test = (*itObj)->getBegin() + (*itObj)->getWidth();
			if (test > range)
			{
				range = test;
			}
		}
	}
	m_ForceRangeMedium0 = range + 0;
}

void BusinessTask::calcForceMedium1()
{
	int range = appData.getProjectDuration();
	int test = 0;

	/* Suche erste Bewegungseinschr�nkung Following */
	list<IBusinessAdapter*>::iterator itObj;
	for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			test = (*itObj)->getBegin();
			if (test < range) range = test;
		}
	}

	m_ForceRangeMedium1 = range - m_Width - 0;
}


void BusinessTask::moveToEarlierPosition(int new_begin)
{
	int test = 0;
	int range = 0;

	if(new_begin < m_ForceRangeIncredible0)
	{
		m_Begin = m_ForceRangeIncredible0;
		movePreviousToFront();
	}
	else if(m_ForceRangeIncredible0 < new_begin && new_begin < m_ForceRangeMedium0)
	{
		/* Durchlaufe die Vorg�nger  */
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
	m_End = calcEnd(m_Begin, m_Width);
}

void BusinessTask::moveToLaterPosition(int new_begin)
{
	int test = 0;
	int range = 0;

	if(new_begin > m_ForceRangeIncredible1)
	{
		m_Begin = m_ForceRangeIncredible1 - m_Width;
		moveFollowingToFront(m_ForceRangeIncredible1);
	}
	else if( m_ForceRangeMedium0 < new_begin && new_begin < m_ForceRangeIncredible1)
	{
		/* Durchlaufe die Vorg�nger  */
		list<IBusinessAdapter*>::iterator itObj;
		for (itObj = m_TasksFollowing.begin() ; itObj != m_TasksFollowing.end(); itObj++)
		{
			if (*itObj != NULL)
			{
				if ( new_begin > (*itObj)->getBegin() )
				{
					(*itObj)->moveToLaterPosition(new_begin + m_Width);
				}
			}
			
		}
		m_Begin = new_begin;

	}
	else
	{
		m_Begin = new_begin;
	}
	m_End = calcEnd(m_Begin, m_Width);
}
