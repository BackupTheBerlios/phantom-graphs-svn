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

	for (itObj = m_BusinessTasks.begin() ; itObj != m_BusinessTasks.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			delete *itObj;
			*itObj = NULL;
		}
	}
	m_BusinessTasks.clear();

	
	
}
