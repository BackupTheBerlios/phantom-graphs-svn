//*******************************************************************************
/// @file	BusinessTask.h
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
//					getPreviousTasks() CA
//				- added: setBegin(float) CA
//				- added: calcBegin() CA
// 29.01.2006	- added: moveToFront() CA
// 30.01.2006	- modified: getForce(int,int) CA
//				- added: enum force CA
//				- modified: moveToFront() CA
//				- modified: moveToFront(), moveFollowingToFront(), 
//				  movePreviousToFront() CA
//				- modified calcRanges() CA

#if !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
#define AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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

	//...............................................................................
	/// @brief	bewegt eine Aufgabe zu einem früheren Startpunkt
	/// @param end erhält denneuen Endtermin von Nachfolgender Aufgabe
	/// @return liefert Ihr neues Ende zurück
	//...............................................................................
	virtual int moveToEarlierPosition(int end);

	virtual int calcForceInc1();
	void calcForceMedium1();
	void calcForceMedium0();

	//...............................................................................
	/// @brief	berechnet den Punkt über den nicht nach Links verschoben werden kann
	//...............................................................................
	virtual int calcForceInc0();
	
	void calcRanges();
	// int m_ForceRangeNone1;
	// int m_ForceRangeNone0;
	int m_ForceRangeMedium0;
	int m_ForceRangeMedium1;
	int m_ForceRangeIncredible0;
	int m_ForceRangeIncredible1;

	//...............................................................................
	/// @brief	schiebt nachfolgende Aufgaben so weit wie möglich an den Anfang des Projekts
	//...............................................................................
	void moveFollowingToFront(int earliest);

	//...............................................................................
	/// @brief	schiebt vorhergehende Aufgaben so weit wie möglich an den Anfang des Projekts
	//...............................................................................
	void movePreviousToFront();

	//...............................................................................
	/// @brief	Liefert das Ende der Aufgabe
	/// @return Ende der Aufgabe
	//...............................................................................
	int getEnd();

	//...............................................................................
	/// @brief	Liefert den Anfang der Aufgabe
	/// @return Anfang der Aufgabe
	//...............................................................................
	int getBegin();

	//...............................................................................
	/// @brief	schiebt alle Aufgaben so weit wie möglich an den Anfang des Projekts
	//...............................................................................
	void moveAllToFront();

	//...............................................................................
	/// @brief	setzt den Anfang einer Aufgabe
	/// @param	begin	Anhand des Übergabewertes entscheidet die Aufgabe den genauen Begin
	/// @return bool true=Begin erfolgreich geändert, false=keine Änderung durchgeführt
	//...............................................................................
	bool setBegin(float begin);

	void setLine(int line);
	void addTaskPrevious(BusinessTask *follows);
	void addTaskFollowing(BusinessTask *followed_by);
	string getName();
	void printInfo();
	int getLine();
	int getWidth();

	//...............................................................................
	/// @brief	Liefert die Kraft, die notwendig ist, um eine Aufgabe zu verschieben
	/// @param	x aktueller x-Wert des Knoten in Business Einheiten
	/// @param	y aktueller y-Wert des Knoten in Business Einheiten
	/// @return	m_Force (siehe oben)
	//...............................................................................
	virtual force getForce(float x, float y);

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

	//...............................................................................
	/// @brief	Rückgabewerte für getForce()
	//...............................................................................
	force m_Force;

	//..................................................
	/// @brief rundet floats auf beliebige nachkommastellen ab
	/// @param value float, das gerundet werden soll
	/// @param nachkommastellen - anzugeben in 1 für keine, 10 für 1, 100 für 2 ... Nachkommastellen
	//..................................................
	float runden(float value, int nachkommastellen);

	//..................................................
	/// @brief Darstellungsebene
	//..................................................
	int m_Line;

	float width;
	Position position;

	//..................................................
	/// @brief berechnet den Anfangspunkt anhand von Endpunkt und Dauer
	/// @param end Endpunkt
	/// @param duration Dauer
	//..................................................
	int calcBegin(int end, int duration);

	//..................................................
	/// @brief berechnet den Endpunkt anhand von Anfangspunkt und Dauer
	/// @param begin Anfangspunkt
	/// @param duration Dauer
	//..................................................
	int calcEnd(int begin, int duration);

	bool isMilestone;
	int m_Begin;
	int surface;
	int m_End;
	int m_Final;

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
