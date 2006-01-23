//*******************************************************************************
/// @file	BusinessTask.h
/// @author	Carsten Arnold
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	06.01.2006
//*******************************************************************************

#if !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
#define AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
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
	void printInfo();
	Position getPosition();
	float getHeight();
	float getWidth();
	int getForce();
	BusinessTask();
	BusinessTask(string taskname, int day_duration, int day_final, bool isMilestone);
	virtual ~BusinessTask();

private:
	float height;
	float width;
	Position position;
	int calcDayEnd(int begin, int duration);
	bool isMilestone;
	int day_begin;
	int surface;
	int day_end;
	int day_final;
	int force;
	int day_duration;
	string name;
protected:
	void businessToViewCoordinates();
	void viewToBusinessCoordinates();
};

#endif // !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
