//*******************************************************************************
/// @file	HapticAction.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		15.12.2005
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		- Doku zur Schnittstelle geschrieben


#ifndef _HAPTICACTION_H_
#define _HAPTICACTION_H_

// Haptic Library includes
#include <HL/hl.h>

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Schnittstelle für haptische Eventhandler
///
///			Implementierende Klassen müssen darauf achten, dass alle HLAPI-Events
///			sauber registriert und deregistriert werden.
//...............................................................................
class IHapticAction
{
	public:

		//.......................................................................
		/// @brief	Registriert ein Event für das haptische Objekt, dem es
		///			zugeordnet ist.
		/// @param	shapeID	Die ID des Objektes, für das das Event registriert
		///			werden soll.
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID ) = 0;
		
		//.......................................................................
		/// @brief	Löscht ein Event für das haptische Objekt, dem es zugeordnet ist
		/// @param	shapeID	Die ID des Objektes, für das das Event deregistriert
		///			werden soll.
		//.......................................................................
		virtual void registerAction( HLuint shapeID ) = 0;
		
};

#endif // _HAPTICACTION_H_