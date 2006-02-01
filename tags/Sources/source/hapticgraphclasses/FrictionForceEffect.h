//*******************************************************************************
/// @file	FrictionForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		06.01.2006
/// @date	Letzte Änderung	06.01.2006
//*******************************************************************************

// Änderungen:


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
		//.......................................................................
		double m_Magnitude;
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		double m_Gain;

		//.......................................................................
		/// @brief	Setzt die entsprechenden Eigenschaften beim Rendern des 
		///			Effekts in HLAPI-Aufrufe um.
		//.......................................................................
		virtual void renderProperties();

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert den Effekt mit den angegebenen Werten.
		/// @param	magnitude	
		/// @param	gain
		//.......................................................................
		FrictionForceEffect( double magnitude = 0.0, double gain = 0.0 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~FrictionForceEffect();
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		void setMagnitude( double value );
		
		//.......................................................................
		/// @brief
		//.......................................................................
		virtual void setGain( double value );
	
};

#endif // _FRICTIONFORCEEFFECT_H_