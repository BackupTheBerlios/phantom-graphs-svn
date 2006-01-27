//*******************************************************************************
/// @file	BusinessTask.h
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	24.01.2006 CA
//*******************************************************************************

// Änderungen:
// ...
// 24.01.2006	- Liste mit Vorgängern hinzugefügt
//				- Liste mit Nachfolgern hinzugefügt
//				- Memberfunktion zum hinzufügen von Vorgängern und Nachfolgern

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
	void addTaskPrevious(BusinessTask *follows);
	void addTaskFollowing(BusinessTask *followed_by);
	string getName();
	void printInfo();
	int getDayBegin();
	int getLine();
	int getDuration();
	int getForce();
	BusinessTask();
	BusinessTask(string taskname, int day_duration, int day_final, bool isMilestone);
	virtual ~BusinessTask();

private:
	//..................................................
	/// @brief Darstellungsebene
	//..................................................
	int m_line;

	float width;
	Position position;
	int calcDayEnd(int begin, int duration);
	bool isMilestone;
	int m_DayBegin;
	int surface;
	int day_end;
	int day_final;
	int force;
	int m_DayDuration;
	string m_Name;

	/// @brief	Liste aller direkter nachfolgenden Aufgaben
	list<BusinessTask*> m_TasksFollowing;

	/// @brief	Liste aller direkter vorhergehender Aufgaben
	list<BusinessTask*> m_TasksPrivious;

protected:
	void businessToViewCoordinates();
	void viewToBusinessCoordinates();
};

#endif // !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
