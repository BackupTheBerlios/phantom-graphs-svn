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
	
}

int AppConfiguration::getProjectDuration()
{
	// Dummy
	return 300;
}

void AppConfiguration::setProjectDuration( int value )
{
}

AppConfiguration::~AppConfiguration()
{
}

void AppConfiguration::initTasks()
{
	list<BusinessTask*>::iterator itObj;

	/*for (itObj = m_BusinessTasks.begin() ; itObj != m_BusinessTasks.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			delete *itObj;
			*itObj = NULL;
		}
	}
	m_BusinessTasks.clear();
	*/

	// m_ProjectDuration = 300;

	// BusinessTask task = new BusinessTask;

	
	
}
