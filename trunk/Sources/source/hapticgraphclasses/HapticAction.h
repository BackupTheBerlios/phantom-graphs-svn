//*******************************************************************************
/// @file	HapticAction.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		15.12.2005
/// @date	Letzte �nderung	27.12.2005
//*******************************************************************************

// �nderungen:
// 27.12.05		- Doku zur Schnittstelle geschrieben


#ifndef _HAPTICACTION_H_
#define _HAPTICACTION_H_

// Haptic Library includes
#include <HL/hl.h>

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Schnittstelle f�r haptische Eventhandler
///
///			Implementierende Klassen m�ssen darauf achten, dass alle HLAPI-Events
///			sauber registriert und deregistriert werden.
//...............................................................................
class IHapticAction
{
	public:

		//.......................................................................
		/// @brief	Registriert ein Event f�r das haptische Objekt, dem es
		///			zugeordnet ist.
		/// @param	shapeID	Die ID des Objektes, f�r das das Event registriert
		///			werden soll.
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID ) = 0;
		
		//.......................................................................
		/// @brief	L�scht ein Event f�r das haptische Objekt, dem es zugeordnet ist
		/// @param	shapeID	Die ID des Objektes, f�r das das Event deregistriert
		///			werden soll.
		//.......................................................................
		virtual void registerAction( HLuint shapeID ) = 0;
		
};

#endif // _HAPTICACTION_H_