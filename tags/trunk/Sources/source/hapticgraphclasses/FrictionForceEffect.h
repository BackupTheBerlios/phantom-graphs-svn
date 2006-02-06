//*******************************************************************************
/// @file	FrictionForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		06.01.2006
/// @date	Letzte Änderung	04.02.2006
//*******************************************************************************

// Änderungen:
// 04.02.06		- Doku vervollständigt.


#ifndef _FRICTIONFORCEEFFECT_H_
#define _FRICTIONFORCEEFFECT_H_

#include "HapticEffect.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse zur Ausgabe einer "ambienten" Reibungskraft auf dem Phantom Device.
//...............................................................................
class FrictionForceEffect : public HapticEffect
{
	protected:		
		
		//.......................................................................
		/// @brief	"Größe" der Kraft.
		///
		///			Für weiterführende Erkärungen s. "API Reference" des 
		///			OpenHaptics Toolkit.
		//.......................................................................
		double m_Magnitude;
		
		//.......................................................................
		/// @brief	Zunahme der Kraft.
		///
		///			Für weiterführende Erkärungen s. "API Reference" des 
		///			OpenHaptics Toolkit.
		//.......................................................................
		double m_Gain;

		//=======================================================================
		// von HapticEffect geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Setzt die entsprechenden Eigenschaften beim Rendern des 
		///			Effekts in HLAPI-Aufrufe um.
		//.......................................................................
		virtual void renderProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert den Effekt mit den angegebenen Werten.
		/// @param	magnitude	"Größe" der Kraft.	Default: 0.0
		/// @param	gain		Zunahme der Kraft.	Default: 0.0
		//.......................................................................
		FrictionForceEffect( double magnitude = 0.0, double gain = 0.0 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~FrictionForceEffect();
		
		//.......................................................................
		/// @brief	Setzt den Wert für die Magnitude der Kraft.
		/// @param	value	Neuer Wert für die Magnitude der Kraft.
		//.......................................................................
		void setMagnitude( double value );
		
		//.......................................................................
		/// @brief	Setzt den Wert für die Zunahme der Kraft.
		/// @param	value	Neuer Wert für die Zunahme der Kraft.
		//.......................................................................
		virtual void setGain( double value );
	
};

#endif // _FRICTIONFORCEEFFECT_H_