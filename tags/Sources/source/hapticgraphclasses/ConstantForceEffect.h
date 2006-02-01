//*******************************************************************************
/// @file	ConstantForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		05.01.2006
/// @date	Letzte Änderung	05.01.2006
//*******************************************************************************

// Änderungen:


#ifndef _CONSTANTFORCEEFFECT_H_
#define _CONSTANTFORCEEFFECT_H_

// Haptic Library includes
#include <HDU/hduVector.h>

#include "HapticEffect.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse zur Ausgabe einer konstanten Kraft in Richtung des Direction-
///			Vektors (setDirection()) auf dem Phantom Device.
//...............................................................................
class ConstantForceEffect : public HapticEffect
{
	protected:

		//.......................................................................
		/// @brief	Richtung (Vektor), in der die Kraft wirken soll.
		//.......................................................................
		hduVector3Dd m_Direction;

		//.......................................................................
		/// @brief	"Größe" der Kraft.
		//.......................................................................
		double m_Magnitude;

		//.......................................................................
		/// @brief	Setzt die entsprechenden Eigenschaften beim Rendern des 
		///			Effekts in HLAPI-Aufrufe um.
		//.......................................................................
		virtual void renderProperties();

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt mit den angegebenen Werten.
		/// @param	direction	Richtungsvektor der Kraft.
		///	@param	magnitude	"Größe" der Kraft.
		//.......................................................................
		ConstantForceEffect( const double direction[3], double magnitude );

		//.......................................................................
		///	@brief	Standardkonstruktor: Initialisiert das Objekt mit Defaultwerten.
		///			
		///			Defaultwerte:
		///			- direction: 0.0, 0.0, 0.0
		///			- magnitude: 0.0
		//.......................................................................
		ConstantForceEffect();

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~ConstantForceEffect();
		
		//.......................................................................
		/// @brief	Setzt die Länge des Kraftvektors.
		///	@param	value	"Größe" der Kraft.
		//.......................................................................
		virtual void setMagnitude( double value );
		
		//.......................................................................
		///	@brief	Setzt die Richtung der Kraft.
		///	@param	x	x-Komponente des Richtungsvektors.
		///	@param	y	y-Komponente des Richtungsvektors.
		///	@param	z	z-Komponente des Richtungsvektors.
		//.......................................................................
		virtual void setDirection( double x, double y, double z );
	
};

#endif // _CONSTANTFORCEEFFECT_H_