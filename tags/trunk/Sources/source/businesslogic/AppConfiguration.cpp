//*******************************************************************************
/// @file	AppConfiguration.cpp
/// @author	Carsten, Arnold
/// @date	Erstellt am		30.11.2005
/// @date	Letzte Änderung	27.01.2006
//*******************************************************************************

// Änderungen:
// 06.01.2006	- Konstruktor, Destruktor CA
//				- initTasks hinzugefügt CA
// 09.01.2006	- Aufgaben initialisiern CA
// 24.01.2006   - Startaufgabe festgelegt (m_rootTask) CA
// 27.01.2006	- added: m_ProjectLines, Anzahl maximaler paralleler Aufgaben CA
//				  added: Getter/Setter m_ProjectLines
//				  coded: Nachfolger/Vorgänger hardcodiert
//				  added: statische m_ProjectLines

#include "AppConfiguration.h"


AppConfiguration::AppConfiguration()
{
	/// @brief Ausgabe von Debuginfos ein-/ausschalten
	setDebugState(true);
	
	// statische Festlegung der Projektdauer
	setProjectDuration(300);

	// statische Festlegung der  maximal parallel ausgeführter Aufgaben
	setProjectLines(3);

	// statische Festlegung der graphischen Einheiten pro Tag

	
	/// @brief Debugausgabe Projektdauer
	if(getDebugState()){
		cout << "Das Projekt dauert " << getProjectDuration() << " Tage." << endl;
	}

}

int AppConfiguration::getProjectDuration()
{
	return m_ProjectDuration;
}


void AppConfiguration::setProjectDuration(int days)
{
	m_ProjectDuration = days;
}

AppConfiguration::~AppConfiguration()
{
}

void AppConfiguration::initTasks()
{
	list<BusinessTask*>::iterator itObj;

	/* Startknoten von dem alle anderen Aufgaben abhängen */
	BusinessTask *task00 = new BusinessTask("A00",0,0,0);
	
	/* Alle anderen Aufgaben */
	BusinessTask *task01 = new BusinessTask("A01",7,10,0);
	BusinessTask *task02 = new BusinessTask("A02",14,24,1);
	BusinessTask *task03 = new BusinessTask("A03",20,44,0);
	BusinessTask *task04 = new BusinessTask("A04",10,34,0);
	BusinessTask *task05 = new BusinessTask("A05",30,55,0);
	BusinessTask *task06 = new BusinessTask("A06",20,70,1);
	BusinessTask *task07 = new BusinessTask("A07",6,80,0);
	BusinessTask *task08 = new BusinessTask("A08",6,300,1);

	BusinessTask *task09 = new BusinessTask("A08",6,300,1);
	delete task09;

	task01->setLine(0);
	task02->setLine(0);
	task03->setLine(0);
	task04->setLine(1);
	task05->setLine(2);
	task06->setLine(0);
	task07->setLine(0);
	task08->setLine(0);

	/* Aufgaben der Aufgabenliste hinzufügen */
	m_BusinessTasks.push_back(task00);
	m_BusinessTasks.push_back(task01);
	m_BusinessTasks.push_back(task02);
	m_BusinessTasks.push_back(task03);
	m_BusinessTasks.push_back(task04);
	m_BusinessTasks.push_back(task05);
	m_BusinessTasks.push_back(task06);
	m_BusinessTasks.push_back(task07);
	m_BusinessTasks.push_back(task08);

	/* Den Aufgaben Nachfolger und Forgänger zuweisen */
	task00->addTaskFollowing(task01);

	task01->addTaskPrevious(task00);
	task01->addTaskFollowing(task02);

	task02->addTaskPrevious(task01);
	task02->addTaskFollowing(task03);
	task02->addTaskFollowing(task04);
	task02->addTaskFollowing(task05);

	task03->addTaskPrevious(task02);
	task03->addTaskFollowing(task06);
	
	task04->addTaskPrevious(task02);
	task04->addTaskFollowing(task06);

	task05->addTaskPrevious(task02);

	task06->addTaskPrevious(task03);
	task06->addTaskPrevious(task04);
	task06->addTaskFollowing(task07);

	task07->addTaskPrevious(task06);
	task07->addTaskFollowing(task08);

	task08->addTaskPrevious(task07);

	
	/* set root Aufgabe */
	m_rootTask = *m_BusinessTasks.begin();

	/* Alle Aufgaben an den Anfang des Projektzeitraums setzen */
	//	m_rootTask->moveAllToFront();

	// Kräfte aller Aufgaben berechnen
	for (itObj = m_BusinessTasks.begin() ; itObj != m_BusinessTasks.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			//delete *itObj;
			//*itObj = NULL;
			(*itObj)->calcRanges();
		}
	}

	// @brief Debuginfo zur Ausgabe aller Tasks
	if(getDebugState())
	{
		cout << "DebugInfo: Aufruf aus AppConfiguration::initTasks" << endl;
		cout << "Name der Startaufgabe: " << m_rootTask->getName() << endl << endl;
	}

	
	// @brief Debuginfo zur Ausgabe aller Tasks
	if(getDebugState())
	{
		for (itObj = m_BusinessTasks.begin() ; itObj != m_BusinessTasks.end(); itObj++)
		{
			if (*itObj != NULL)
			{
				//delete *itObj;
				//*itObj = NULL;
				(*itObj)->printInfo();
			}
		}
		cout << endl;
	}

}

bool AppConfiguration::getDebugState()
{
	return m_debug;
}

void AppConfiguration::setDebugState(bool state)
{
	m_debug = state;
}

int AppConfiguration::getProjectLines()
{
	return m_ProjectLines;
}


IBusinessAdapter* AppConfiguration::getRootTask()
{
	return m_rootTask;
}

void AppConfiguration::setProjectLines(int lines)
{
	m_ProjectLines = lines;
}


