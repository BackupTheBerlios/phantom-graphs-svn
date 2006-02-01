//*******************************************************************************
/// @file	HapticExceptions.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	27.12.2005
//*******************************************************************************

// �nderungen:
// 27.12.05		Doku geschrieben

#ifndef _HAPTICEXCEPTIONS_H_
#define _HAPTICEXCEPTIONS_H_

#include <stdexcept>

using namespace std;

//...............................................................................
/// @brief	Exceptionklasse, die einen Fehler bei der Initialisierung des 
///			haptischen Ger�ts anzeigt.
//...............................................................................
class HDInitialisationFailedException : public runtime_error
{
	public:

		//.......................................................................
		/// @brief	Konstruktor: Erzeugt ein Exception-Objekt mit einer Nachricht
		///	@param	message	Nachricht, die beim Exceptionhandling abgefragt werden kann
		//.......................................................................
		HDInitialisationFailedException(const string& message)	
		: runtime_error(message) {};	
};

#endif // _HAPTICEXCEPTIONS_H_