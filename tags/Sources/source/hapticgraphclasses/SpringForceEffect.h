//*******************************************************************************
/// @file	SpringForceEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.01.2006
/// @date	Letzte �nderung	28.01.2006
//*******************************************************************************

// �nderungen:


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
		/// @brief	
		//.......................................................................
		double m_Magnitude;
		
		//.......................................................................
		/// @brief	
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
		/// @brief	Spezifiziert die Eigenschaften des Effektes f�r HLAPI.
		//.......................................................................
		virtual void renderProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	
		//.......................................................................
		SpringForceEffect( double magnitude, double gain, Position anchor );

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual ~SpringForceEffect();
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		void setMagnitude( double value );
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual void setGain( double value );
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		void setAnchorPosition( double x, double y, double z );
	
};

#endif // _SPRINGFORCEEFFECT_H_