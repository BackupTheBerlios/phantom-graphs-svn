//*******************************************************************************
/// @file	HapticExceptions.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	26.12.2005
//*******************************************************************************

#ifndef _HAPTICEXCEPTIONS_H_
#define _HAPTICEXCEPTIONS_H_

#include <stdexcept>

using namespace std;

//...............................................................................
//...............................................................................
class HDInitialisationFailedException : public runtime_error
{
	public:

		//.......................................................................
		//.......................................................................
		HDInitialisationFailedException(const string& message)	
		: runtime_error(message) {};	
};

#endif // _HAPTICEXCEPTIONS_H_