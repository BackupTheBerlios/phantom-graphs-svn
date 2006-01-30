// IBusinessAdapter.h: Schnittstelle f�r die Klasse IBusinessAdapter.
//
//*******************************************************************************
/// @file	IBusinessAdapter.h
/// @author	Carsten Arnold, Matr.-Nr. 232237
/// @date	Erstellt am		15.12.2005
/// @date	Letzte �nderung	24.01.2006
//*******************************************************************************

// �nderungen:
// 06.01.2006	- Schnittstelle getForce() hinzugef�gt
// 09.01.0006		- Schnittstellen getWidth(), getHeight() und getPosition() hinzugef�gt (Kathrin)
// 24.01.2006	- Schnittstelle 
//					getName() 
//					getLine()
//				  hinzugef�gt (CA)
// 28.01.2006	- added:
//					getNextTasks()
//					getPreviousTasks() CA
//				- added setBegin(float) CA
// 30.01.2006	- modified: getForce(int,int) CA
//				- added: enum force CA



#if !defined(AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_)
#define AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../hapticgraphclasses/Utilities.h"
#include "Observable.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//...............................................................................
/// @brief	Aufz�hlungstyp f�r die Kraft
//...............................................................................
enum force {none, medium, incredible};

//...............................................................................
/// @brief	Adapterklasse der eine Referenz zwischen Grafikobjekten der
///			haptischen Szene und den Aufgaben herstellt.
///			
///			Jeder Node enth�lt eine Referenz auf seine entsprechende
///			Aufgabe um relevante Daten mit Ihr auszutauschen
/// @todo	Definition der abstrakten Adapter Methoden
//...............................................................................
class IBusinessAdapter : public Observable
{
public:
	
	//...............................................................................
	/// @brief	Liefert die Kraft, die notwendig ist, um eine Aufgabe zu verschieben
	/// @param	x aktueller x-Wert des Knoten in Business Einheiten
	/// @param	y aktueller y-Wert des Knoten in Business Einheiten
	/// @return	m_Force (siehe oben)
	//...............................................................................
	virtual force getForce(float x, float y)=0;

	//.......................................................................
	/// @brief	Ermittelt die Breite des Darstellungsobjektes in View-Einheiten.
	/// @return	Breite des Darstellungsobjektes in View-Einheiten.
	//.......................................................................
	virtual int getWidth() = 0;

	//.......................................................................
	/// @brief	Ermittelt die H�he des Darstellungsobjektes in View-Einheiten.
	/// @return	H�he des Darstellungsobjektes in View-Einheiten.
	//.......................................................................
	virtual int getLine() = 0;
	
	//.......................................................................
	/// @brief	Ermittelt den Starttag
	/// @return	Starttag
	//.......................................................................
	virtual int getBegin() = 0;

	//.......................................................................
	/// @brief	Liefert den Namen des Tasks
	/// @return	Name als string
	//.......................................................................
	virtual string getName() = 0;

	//.......................................................................
	/// @brief	Liefert die Nachfolger
	/// @return	Liste mit Nachfolgern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getNextTasks() = 0;

	//.......................................................................
	/// @brief	Liefert die Vorg�nger
	/// @return	Liste mit Vorg�ngern
	//.......................................................................
	virtual list<IBusinessAdapter*>& getPreviousTasks() = 0;

	//...............................................................................
	/// @brief	setzt den Anfang einer Aufgabe
	/// @param	begin	Anhand des �bergabewertes entscheidet die Aufgabe den genauen Begin
	//...............................................................................
	virtual bool setBegin(float begin) = 0;

	//...............................................................................
	/// @brief	schiebt alle Aufgaben an den Projektanfang
	/// @param	begin	Anhand des �bergabewertes entscheidet die Aufgabe den genauen Begin
	//...............................................................................
	virtual void moveAllToFront() = 0;

	//...............................................................................
	/// @brief	schiebt nachfolgende Aufgaben so weit wie m�glich an den Anfang des Projekts
	//...............................................................................
	virtual void moveFollowingToFront(int earliest) = 0;

	//...............................................................................
	/// @brief	schiebt vorhergehende Aufgaben so weit wie m�glich an den Anfang des Projekts
	//...............................................................................
	virtual void movePreviousToFront() = 0;

	//...............................................................................
	/// @brief	berechnet den Punkt �ber den nicht nach Links verschoben werden kann
	//...............................................................................
	virtual int calcForceInc0() = 0;

	//...............................................................................
	/// @brief	berechnet den Punkt �ber den nicht nach Rechts verschoben werden kann
	//...............................................................................
	virtual int calcForceInc1() = 0;


};

#endif // !defined(AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_)
