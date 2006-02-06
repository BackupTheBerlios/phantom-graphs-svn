//*******************************************************************************
/// @file	Observable.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte Änderung	28.12.2005
//*******************************************************************************

// Änderungen:


#include "Observable.h"

//*******************************************************************************
Observable::Observable()
{
	m_Observers.clear();
}
//*******************************************************************************

//*******************************************************************************
void Observable::AddObserver( IObserver * pObserver )
{
	m_Observers.push_back(pObserver);
	pObserver->Update(this);
}
//*******************************************************************************

//*******************************************************************************
void Observable::RemoveObserver( IObserver * pObserver )
{
	m_Observers.remove(pObserver);
}
//*******************************************************************************

//*******************************************************************************
void Observable::NotifyAll()
{
	list<IObserver*>::iterator itObs;
	for (itObs = m_Observers.begin(); itObs != m_Observers.end(); itObs++)
	{
		(*itObs)->Update(this);
	}
}
//*******************************************************************************




