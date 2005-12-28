//*******************************************************************************
/// @file	IObserver.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte Änderung	28.12.2005
//*******************************************************************************

// Änderungen:


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
		//.......................................................................
		virtual void Update( Observable * pObservable ) = 0;
};

#endif // _IOBSERVER_H_
