//*******************************************************************************
/// @file	Observable.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte Änderung	05.02.2006
//*******************************************************************************

// Änderungen:
// 05.02.06		- Doku vervollständigt.


#ifndef _OBSERVABLE_H_
#define _OBSERVABLE_H_

#include "IObserver.h"
class IObserver;

#include <list>
using namespace std;

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
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
		/// @brief	Konstrktor: Initialisiert das Objekt.
		//.......................................................................
		Observable();

		//.......................................................................
		/// @brief	Registriert einen neuen Obersver.
		/// @param	pObserver	Zeiger auf ein Observer-Objekt, das den Observable
		///						von jetzt an beobachten will.
		//.......................................................................
		void AddObserver(IObserver * pObserver);

		//.......................................................................
		/// @brief	Meldet einen Observer beim Observable ab. Das Observer-Objekt
		///			wird dabei nicht gelöscht.
		/// @param	pObserver	Zeiger auf das Observer-Objekt, das von jetzt an
		///						den Observable nicht mehr beobachten will.
		//.......................................................................
		void RemoveObserver( IObserver * pObserver );

		//.......................................................................
		/// @brief	Informiert alle Observer darüber, dass sich der Zustand des 
		///			Observables geändert hat.
		//.......................................................................
		void NotifyAll();
};

#endif // _OBSERVABLE_H_