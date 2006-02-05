//*******************************************************************************
/// @file	BusinessTask.h
/// @author	Carsten Arnold
/// @date	Erstellt am		30.11.2005
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
//				- modified:
//					getNextTasks()
//					getPreviousTasks() CA
//				- modified: setBegin(float) CA
//				- modified: calcBegin() CA
// 29.01.2006	- modified: moveToFront() CA
// 30.01.2006	- modified: getForce(int,int) CA
//				- modified: enum force CA
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
#include "..\HAPTICGRAPHCLASSES\Utilities.h"	// Hinzugef�gt von der Klassenansicht

using namespace std;

//...............................................................................
/// @brief	diese KLasse verwaltet alle Aufgaben, die im Graph dargestellt werden sollen.
///
//...............................................................................
class BusinessTask : public IBusinessAdapter
{
public:

	//...............................................................................
	/// @brief	bewegt eine Aufgabe zu einem sp�teren Startpunkt
	/// @param new_begin erh�lt seinen neuen Anfang
	//...............................................................................
	virtual void moveToLaterPosition(int new_begin);

	//...............................................................................
	/// @brief	bewegt eine Aufgabe zu einem fr�heren Startpunkt
	/// @param end erh�lt denneuen Endtermin von Nachfolgender Aufgabe
	//...............................................................................
	virtual void moveToEarlierPosition(int end);

	//...............................................................................
	/// @brief	berechnet das Datum nach Links zum Ende der n�chsten vorhergehenden Aufgabe
	/// @return gibt das Datum zur�ck
	//...............................................................................
	void calcForceMedium0();

	//...............................................................................
	/// @brief	berechnet das Datum nach Rechts zum Begin der n�chsten folgenden Aufgabe
	/// @return gibt das Datum zur�ck
	//...............................................................................
	void calcForceMedium1();

	//...............................................................................
	/// @brief	berechnet das Datum �ber das nicht nach Links verschoben werden kann
	/// @return gibt das Datum zur�ck
	//...............................................................................
	virtual int calcForceInc0();

	//...............................................................................
	/// @brief	berechnet das Datum �ber das nicht nach Rechts verschoben werden kann
	/// @return gibt das Datum zur�ck
	//...............................................................................
	virtual int calcForceInc1();

	/// @brief Aufruf zum berechnen der Kraftpositionen der Aufgabe
	void calcRanges();

	/// Datum vom Ende der n�chsten vorhergehenden Aufgabe
	int m_ForceRangeMedium0;

	/// Datum vom Anfang der n�chsten nachfolgenden Aufgabe
	int m_ForceRangeMedium1;

	/// Datum �ber das die Aufgabe nicht weiter nach Links verschoben werden kann
	int m_ForceRangeIncredible0;
	
	/// Datum �ber das die Aufgabe nicht weiter nach Rechts verschoben werden kann
	int m_ForceRangeIncredible1;

	//...............................................................................
	/// @brief	schiebt alle Aufgaben so weit wie m�glich an den Anfang des Projekts
	//...............................................................................
	void moveAllToFront();

	//...............................................................................
	/// @brief	schiebt nachfolgende Aufgaben so weit wie m�glich an den Anfang des Projekts
	//...............................................................................
	void moveFollowingToFront(int earliest);

	//...............................................................................
	/// @brief	schiebt vorhergehende Aufgaben so weit wie m�glich an den Anfang des Projekts
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
	/// @brief	setzt den Anfang einer Aufgabe
	/// @param	begin	Anhand des �bergabewertes entscheidet die Aufgabe den genauen Begin
	/// @return bool true=Begin erfolgreich ge�ndert, false=keine �nderung durchgef�hrt
	//...............................................................................
	bool setBegin(float begin);

	/// @brief f�gt eine Aufgabe zu der Liste der Vorg�nger hinzu
	void addTaskPrevious(BusinessTask *follows);

	/// @brief f�gt eine Aufgabe zu der Liste der Nachfolger hinzu
	void addTaskFollowing(BusinessTask *followed_by);

	/// @brief liefert den Namen der Aufgabe
	/// @return Name der Aufgabe
	string getName();

	/// @brief	gibt einige Infos der Aufgabe auf stdout aus
	void printInfo();

	//...............................................................................
	/// @brief	setzt die Eben der Aufgabe, erh�t sich, wenn die Aufgabe parallel
	///			zu einer anderen Aufgabe durchgef�hrt werden kann
	/// @param	line zu setzende Eben [0..[
	//...............................................................................
	void setLine(int line);

	//...............................................................................
	/// @brief	liefert die Eben der Aufgabe
	/// @return Ebene der Aufgabe
	//...............................................................................
	int getLine();

	//...............................................................................
	/// @ brief liefert die Dauer der Aufgabe
	/// @return Dauer der Aufgabe
	//...............................................................................	
	int getWidth();

	//...............................................................................
	/// @brief	Liefert die Kraft, die notwendig ist, um eine Aufgabe zu verschieben
	/// @param	x aktueller x-Wert des Knoten in Business Einheiten
	/// @param	y aktueller y-Wert des Knoten in Business Einheiten
	/// @return	m_Force (siehe oben)
	//...............................................................................
	virtual force getForce(float x, float y);

	BusinessTask();
	virtual ~BusinessTask();

	//...............................................................................
	/// @brief	�berschreibt den StandardKonstruktor mit der �bergabe folgender Parameter
	/// @param	taskname Name der Aufgabe
	/// @param	day_duration Dauer der Aufgabe
	/// @param	day_final Datum an dem die Aufgabe fertig gestellt sein muss
	/// @param	isMilestone ist die Aufgabe ein Milestone
	//...............................................................................
	BusinessTask(string taskname, int day_duration, int day_final, bool isMilestone);

	//.......................................................................
	/// @brief	Liefert die Nachfolger
	/// @return	Liste mit Nachfolgern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getNextTasks();

	//.......................................................................
	/// @brief	Liefert die Vorg�nger
	/// @return	Liste mit Vorg�ngern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getPreviousTasks();

private:

	//...............................................................................
	/// @brief	R�ckgabewerte f�r getForce(), enum deklariert in IBusinessAdapter
	//...............................................................................
	force m_Force;

	//..................................................
	/// @brief rundet floats auf beliebige nachkommastellen ab
	/// @param value float, das gerundet werden soll
	/// @param nachkommastellen - anzugeben in 1 f�r keine, 10 f�r 1, 100 f�r 2 ... Nachkommastellen
	//..................................................
	float runden(float value, int nachkommastellen);

	//..................................................
	/// @brief Darstellungsebene
	//..................................................
	int m_Line;

	//..................................................
	/// @brief Dauer der Aufgabe
	//..................................................
	float width;

	//..................................................
	/// @brief berechnet den Anfangspunkt anhand von Endpunkt und Dauer
	/// @param end Endpunkt
	/// @param duration Dauer
	/// @return	Dauer der Aufgabe
	//..................................................
	int calcBegin(int end, int duration);

	//..................................................
	/// @brief berechnet den Endpunkt anhand von Anfangspunkt und Dauer
	/// @param begin Anfangspunkt
	/// @param duration Dauer
	/// @return Ende der Aufgabe
	//..................................................
	int calcEnd(int begin, int duration);

	//..................................................
	/// @brief ist die Aufgabe Milestone
	//..................................................
	bool isMilestone;

	//..................................................
	/// @brief Anfangsdatum der Aufgabe
	//..................................................
	int m_Begin;

	//..................................................
	/// @brief Enddatum der Aufgabe
	//..................................................
	int m_End;

	//..................................................
	/// @brief Deadline der Aufgabe
	//..................................................
	int m_Final;

	//..................................................
	/// @brief Dauer der Aufgabe
	//..................................................	
	int m_Width;

	//..................................................
	/// @brief Name der Aufgabe
	//..................................................
	string m_Name;

	/// @brief	Liste aller direkter nachfolgenden Aufgaben
	list<IBusinessAdapter*> m_TasksFollowing;

	/// @brief	Liste aller direkter vorhergehender Aufgaben
	list<IBusinessAdapter*> m_TasksPrevious;

protected:

	/// @brief akkumuliert die �bergebenen Differenzen von x-Axis Bewegungen der View
	float m_Movement;
};

#endif // !defined(AFX_BUSINESSTASK_H__2F03CA42_805D_4D8E_90DF_3D94633457FE__INCLUDED_)
