//*******************************************************************************
/// @file	AppConfiguration.h
/// @author	Carsten, Arnold
/// @date	Erstellt am		06.01.2006
/// @date	Letzte Änderung	06.01.2006
//*******************************************************************************

// Änderungen:
// 06.01.2006	- Konstruktor, Destruktor
//				- initTasks hinzugefügt
// 09.01.2006

#include "AppConfiguration.h"


AppConfiguration::AppConfiguration()
{
	// statische Festlegung der Projektdauer
	setProjectDuration(300);
	cout << "Das Projekt dauert " << getProjectDuration() << " Tage." << endl;

}

int AppConfiguration::getProjectDuration()
{
	// Dummy
	return m_ProjectDuration;
}

void AppConfiguration::setProjectDuration( int value )
{
	m_ProjectDuration = value;
}

AppConfiguration::~AppConfiguration()
{
}

void AppConfiguration::initTasks()
{
	list<BusinessTask*>::iterator itObj;


	BusinessTask *task01 = new BusinessTask("A01",7,10,0);
	BusinessTask *task02 = new BusinessTask("A02",14,24,1);
	BusinessTask *task03 = new BusinessTask("A03",20,44,0);
	BusinessTask *task04 = new BusinessTask("A04",10,34,0);
	BusinessTask *task05 = new BusinessTask("A05",30,56,0);
	BusinessTask *task06 = new BusinessTask("A06",20,70,1);
	BusinessTask *task07 = new BusinessTask("A07",6,80,0);
	BusinessTask *task08 = new BusinessTask("A08",6,300,1);

	//m_BusinessTasks.push_back(task);
	m_BusinessTasks.push_back(task01);
	m_BusinessTasks.push_back(task02);
	m_BusinessTasks.push_back(task03);
	m_BusinessTasks.push_back(task04);
	m_BusinessTasks.push_back(task05);
	m_BusinessTasks.push_back(task06);
	m_BusinessTasks.push_back(task07);
	m_BusinessTasks.push_back(task08);

	//task01->printInfo();

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
	
	//m_BusinessTasks.clear();
	

}
