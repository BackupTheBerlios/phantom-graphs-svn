//*******************************************************************************
/// @file	AppConfiguration.h
/// @author	Carsten, Arnold
/// @date	Erstellt am		30.11.2005
/// @date	Letzte �nderung	27.01.2006
//*******************************************************************************

// �nderungen:
// 06.01.2006	- Konstruktor, Destruktor CA
//				- initTasks hinzugef�gt CA
// 09.01.2006	- Aufgaben initialisiern CA
// 24.01.2006   - Startaufgabe festgelegt (m_rootTask) CA
// 27.01.2006	- added: m_ProjectLines, Anzahl maximaler paralleler Aufgaben CA
//				  added: Getter/Setter m_ProjectLines
//				  coded: Nachfolger/Vorg�nger hardcodiert
//				  added: statische m_ProjectLines

#ifndef _APPCONFIGURATION_H_
#define _APPCONFIGURATION_H_

#include "BusinessTask.h"
#include <list>
#include <iostream>

using namespace std;


//...............................................................................
/// @author	Carsten Arnold
///
/// @brief	Klasse, die f�r projekt�bergreifende Aufgaben zust�ndig ist und 
///			static Member zur Verf�gung stellt, Singelton
//...............................................................................

class AppConfiguration
{
private:

	/// @brief h�lt den aktuellen Debugstatus
	///        default=false, wird im Konstruktor gesetzt gesetzt
	bool m_debug;

	/// @brief Dauer des Projektzeitraums
	int m_ProjectDuration;
	
	/// @brief Anzahl maximaler paralleler Aufgaben
	int m_ProjectLines;

	/// @ brief Pointer auf die fiktive Startaufgabe, die nur Startpunkt 
	///   und selbst keine wirkliche Aufgabe ist Aufgabe 
	IBusinessAdapter* m_rootTask;

public:

	/// @brief	setzt die Anzahl maximaler paralleler Aufgaben
	/// @param	lines Anzahl maximaler paralleler Aufgaben
	void setProjectLines(int lines);

	/// @brief	Liste aller Aufgaben.
	list<BusinessTask*> m_BusinessTasks;

	/// @brief	hier werden alle Aufgaben initialisiert
	///			momentan hard codiert, als Erwiterung ist das einlesen aus XML
	///			vorgesehen
	void initTasks();
	
	/// @brief	setzt die Gesamtdauer des Projekts in Tagen
	/// @param	days Gesamtdauer des Projekts in Tagen
	void setProjectDuration(int days);
	
	/// @brief	Gibt die gesamt darzustellenden Dauer des Projekts zur�ck
	int getProjectDuration();

	/// @brief	liefert einen Pointer auf die Anfangsaufgabe
	IBusinessAdapter* getRootTask();

	/// @brief	liefert die max. Anzahl paralleler Aufgaben
	int getProjectLines();

	/// @brief	setzt den Debugstatus zur Anzeige von Infos w�hrend der Programmausf�hrung
	/// @param	state true/false
	void setDebugState(bool state);

	/// @brief	liefert den aktuellen Debugstatus
	bool getDebugState();

	AppConfiguration();
	~AppConfiguration();	

};

#endif