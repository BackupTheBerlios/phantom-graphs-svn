//*******************************************************************************
/// @file	ViscousForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		08.01.2006
/// @date	Letzte �nderung	05.02.2006
//*******************************************************************************

// �nderungen:
// 05.02.06		- Doku vervollst�ndigt.


#ifndef _VISCOUSFORCEEFFECT_H_
#define _VISCOUSFORCEEFFECT_H_

#include "HapticEffect.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse zur Ausgabe einer "ambienten" Viskost�t auf dem Phantom Device.
//...............................................................................
class ViscousForceEffect : public HapticEffect
{
	protected:
		
		//.......................................................................
		/// @brief	"Gr��e" der Kraft.
		///
		///			F�r weiterf�hrende Erk�rungen s. "API Reference" des 
		///			OpenHaptics Toolkit.
		//.......................................................................
		double m_Magnitude;
		
		//.......................................................................
		/// @brief	Zunahme der Kraft.
		///
		///			F�r weiterf�hrende Erk�rungen s. "API Reference" des 
		///			OpenHaptics Toolkit.
		//.......................................................................
		double m_Gain;

		//=======================================================================
		// von HapticEffect geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Spezifiziert die Eigenschaften des Effektes f�r HLAPI.
		//.......................................................................
		virtual void renderProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert den Effekt mit den angegebenen Werten.
		/// @param	magnitude	"Gr��e" der Kraft. Default: 0.0
		/// @param	gain		Zunahme der Kraft. Default: 0.0
		//.......................................................................
		ViscousForceEffect( double magnitude = 0.0, double gain = 0.0 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~ViscousForceEffect();
		
		//.......................................................................
		/// @brief	Setzt den Wert f�r die Magnitude der Kraft.
		/// @param	value	Neuer Wert f�r die Magnitude der Kraft.
		//.......................................................................
		void setMagnitude( double value );
		
		//.......................................................................
		/// @brief	Setzt den Wert f�r die Zunahme der Kraft.
		/// @param	value	Neuer Wert f�r die Zunahme der Kraft.
		//.......................................................................
		virtual void setGain( double value );
		
};

#endif // _VISCOUSFORCEEFFECT_H_