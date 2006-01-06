//*******************************************************************************
/// @file	AppConfiguration.h
/// @author	Carsten, Arnold
/// @date	Erstellt am		06.01.2006
/// @date	Letzte �nderung	06.01.2006
//*******************************************************************************

// �nderungen:
// 06.01.2006	- Konstruktor, Destruktor
//				- initTasks hinzugef�gt

#ifndef _APPCONFIGURATION_H_
#define _APPCONFIGURATION_H_

#include <list>

using namespace std;

#include "BusinessTask.h"
// #include "..\hapticgraphclasses\HapticObject.h"

//...............................................................................
/// @author	Carsten Arnold
///
/// @brief	Klasse, die f�r projekt�bergreifende Aufgaben zust�ndig ist und 
//			static Member zur Verf�gung stellt
//...............................................................................

class AppConfiguration
{
protected:
	static int m_ProjectDuration;


public:
	void initTasks();
	virtual ~AppConfiguration();
	
	static void setProjectDuration( int value );
	
	static int getProjectDuration();

	//.......................................................................
	/// @brief	Liste aller Aufgaben.
	//.......................................................................
//	vector<HapticObject*> m_SceneElements;
	list<BusinessTask*> m_BusinessTasks;

	AppConfiguration();
	
};

#endif