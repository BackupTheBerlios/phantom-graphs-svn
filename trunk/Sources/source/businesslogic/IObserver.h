//*******************************************************************************
/// @file	IObserver.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte Änderung	30.12.2005
//*******************************************************************************

// Änderungen:
// 30.12.05		- Doku zu Update vervollständigt.


#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

#include "Observable.h"

class Observable;

//...............................................................................
/// @brief	Schnittstelle für  das Observer-Pattern
///
///			Klassen, die diese Schnittstelle implementieren, können sich bei 
///			Observables anmelden um über Änderungen informiert zu werden
//...............................................................................
class IObserver
{
	public:
		//.......................................................................
		/// @brief	Veranlasst den Observer, sich die benötigten Informationen 
		///			vom Observable zu holen
		/// @param	pObservable	Das observierte Objekt, von dem der Observer
		///						Informationen braucht.
		//.......................................................................
		virtual void Update( Observable * pObservable ) = 0;
};

#endif // _IOBSERVER_H_
