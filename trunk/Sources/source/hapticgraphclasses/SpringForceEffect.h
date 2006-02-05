//*******************************************************************************
/// @file	SpringForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.01.2006
/// @date	Letzte Änderung	05.02.2006
//*******************************************************************************

// Änderungen:
// 05.02.06		- Doku vervollständigt.


#ifndef _SPRINGFORCEEFFECT_H_
#define _SPRINGFORCEEFFECT_H_

// Haptic Library includes
#include <HDU/hduVector.h>

#include "HapticEffect.h"
#include "Utilities.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse zur Ausgabe einer Federkraft auf dem Phantom Device.
//...............................................................................
class SpringForceEffect : public HapticEffect
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
		
		//.......................................................................
		/// @brief	Ankerpunkt der dargestellten Federkraft.
		//.......................................................................
		hduVector3Dd m_AnchorPosition;

		//=======================================================================
		// von HapticEffect geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Spezifiziert die Eigenschaften des Effektes für HLAPI.
		//.......................................................................
		virtual void renderProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert den Effekt mit den angegebenen Werten.
		/// @param	magnitude	"Größe" der Kraft.
		/// @param	gain		Zunahme der Kraft.
		/// @param	anchor		Ankerpunkt der dargestellten Federkraft.
		//.......................................................................
		SpringForceEffect( double magnitude, double gain, Position anchor );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~SpringForceEffect();
		
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
		
		//.......................................................................
		/// @brief	Ändert den Ankerpunkt der dargestellten Federkraft.
		///	@param	x	x-Koordinate des neuen Ankerpunktes.
		///	@param	y	y-Koordinate des neuen Ankerpunktes.
		///	@param	z	z-Koordinate des neuen Ankerpunktes.
		//.......................................................................
		void setAnchorPosition( double x, double y, double z );
	
};

#endif // _SPRINGFORCEEFFECT_H_