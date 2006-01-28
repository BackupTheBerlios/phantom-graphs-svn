//*******************************************************************************
/// @file	BusinessTask.h
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


#if !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
#define AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <list>
#include <iostream>
#include "IBusinessAdapter.h"
#include "IBusinessConverter.h"
#include "..\HAPTICGRAPHCLASSES\Utilities.h"	// Hinzugefügt von der Klassenansicht

using namespace std;

//...............................................................................
/// @brief	diese KLasse verwaltet alle Aufgaben, die im Graph dargestellt werden sollen.
///
//...............................................................................
class BusinessTask : public IBusinessAdapter, public IBusinessConverter 
{
public:
	void setLine(int line);
	void addTaskPrevious(BusinessTask *follows);
	void addTaskFollowing(BusinessTask *followed_by);
	string getName();
	void printInfo();
	int getBegin();
	int getLine();
	int getWidth();
	int getForce();
	BusinessTask();
	BusinessTask(string taskname, int day_duration, int day_final, bool isMilestone);
	virtual ~BusinessTask();

	//.......................................................................
	/// @brief	Liefert die Nachfolger
	/// @return	Liste mit Nachfolgern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getNextTasks();

	//.......................................................................
	/// @brief	Liefert die Vorgänger
	/// @return	Liste mit Vorgängern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getPreviousTasks();

private:
	//..................................................
	/// @brief Darstellungsebene
	//..................................................
	int m_Line;

	float width;
	Position position;
	int calcDayEnd(int begin, int duration);
	bool isMilestone;
	int m_Begin;
	int surface;
	int day_end;
	int day_final;
	int force;
	int m_Width;
	string m_Name;

	/// @brief	Liste aller direkter nachfolgenden Aufgaben
	list<IBusinessAdapter*> m_TasksFollowing;

	/// @brief	Liste aller direkter vorhergehender Aufgaben
	list<IBusinessAdapter*> m_TasksPrevious;

protected:
	void businessToViewCoordinates();
	void viewToBusinessCoordinates();
};

#endif // !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
