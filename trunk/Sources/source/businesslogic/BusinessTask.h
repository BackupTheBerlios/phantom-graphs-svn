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

#include "IBusinessAdapter.h"
#include "IBusinessConverter.h"
#include "..\HAPTICGRAPHCLASSES\Utilities.h"	// Hinzugefügt von der Klassenansicht


//...............................................................................
/// @brief	diese KLasse verwaltet alle Aufgaben, die im Graf dargestellt werden sollen.
///
//...............................................................................
class BusinessTask : public IBusinessAdapter, public IBusinessConverter 
{
public:
	Position getPosition();
	float getHeight();
	float getWidth();
	int getForce();
	BusinessTask();
	BusinessTask(char taskname, int day_begin, int day_duration, int day_final, bool isMilestone);
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
	char name;
protected:
	void businessToViewCoordinates();
	void viewToBusinessCoordinates();
};

#endif // !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
