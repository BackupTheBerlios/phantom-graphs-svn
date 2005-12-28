//*******************************************************************************
/// @file	Observable.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte Änderung	28.12.2005
//*******************************************************************************

// Änderungen:


#ifndef _OBSERVABLE_H_
#define _OBSERVABLE_H_

#include "IObserver.h"

#include <list>
using namespace std;

//...............................................................................
/// @brief	Implementiert das Observer-Pattern
///
///			Klassen, die von Observable erben, können Objekte, die an ihrem Zustand
///			interessiert sind über Änderungen informieren ohne eine enge Bindung 
///			zu ihnen zu haben.
//...............................................................................
class Observable
{
	protected:

		//.......................................................................
		/// @brief	Liste aller angemeldeten Observer.
		//.......................................................................
		list<IObserver*> m_Observers;

	public:
	
		//.......................................................................
		//.......................................................................
		Observable();

		//.......................................................................
		/// @brief	Registriert einen neuen Obersver.
		//.......................................................................
		void AddObserver(IObserver * pObserver);

		//.......................................................................
		/// @brief	Meldet einen Observer beim Observable ab. Das Observer-Objekt
		///			wird dabei nicht gelöscht.
		//.......................................................................
		void RemoveObserver( IObserver * pObserver );

		//.......................................................................
		/// @brief	Informiert alle Observer darüber, dass sich der Zustand des 
		///			Observables geändert hat.
		//.......................................................................
		void NotifyAll();
};

#endif // _OBSERVABLE_H_