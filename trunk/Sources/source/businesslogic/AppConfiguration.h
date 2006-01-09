//*******************************************************************************
/// @file	AppConfiguration.h
/// @author	Carsten, Arnold
/// @date	Erstellt am		06.01.2006
/// @date	Letzte Änderung	06.01.2006
//*******************************************************************************

// Änderungen:
// 06.01.2006	- Konstruktor, Destruktor
//				- initTasks hinzugefügt

#ifndef _APPCONFIGURATION_H_
#define _APPCONFIGURATION_H_

#include "BusinessTask.h"
#include <list>

using namespace std;


//...............................................................................
/// @author	Carsten Arnold
///
/// @brief	Klasse, die für projektübergreifende Aufgaben zuständig ist und 
//			static Member zur Verfügung stellt
//...............................................................................

class AppConfiguration
{
public:
	static int m_ProjectDuration;


public:
	void initTasks();
	~AppConfiguration();
	
	/// @brief	Dauer des gesamt darzustellenden Projekts setzen
	static void setProjectDuration( int value );
	
	/// @brief	Gibt die gesamt darzustellenden Dauer des Projekts zurück
	static int getProjectDuration();

	/// @brief	Liste aller Aufgaben.
	list<BusinessTask*> m_BusinessTasks;

	AppConfiguration();
	
};

#endif