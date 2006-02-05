//*******************************************************************************
/// @file	IObserver.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.12.2005
/// @date	Letzte �nderung	30.12.2005
//*******************************************************************************

// �nderungen:
// 30.12.05		- Doku zu Update vervollst�ndigt.


#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

#include "Observable.h"

class Observable;

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Schnittstelle f�r  das Observer-Pattern.
///
///			Klassen, die diese Schnittstelle implementieren, k�nnen sich bei 
///			Observables anmelden um �ber �nderungen informiert zu werden.
//...............................................................................
class IObserver
{
	public:
		//.......................................................................
		/// @brief	Veranlasst den Observer, sich die ben�tigten Informationen 
		///			vom Observable zu holen.
		/// @param	pObservable	Das observierte Objekt, von dem der Observer
		///						Informationen braucht.
		//.......................................................................
		virtual void Update( Observable * pObservable ) = 0;
};

#endif // _IOBSERVER_H_
