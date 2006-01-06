//*******************************************************************************
/// @file	HapticEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte �nderung	03.01.2006
//*******************************************************************************

// �nderungen:


#ifndef _HAPTICEFFECT_H_
#define _HAPTICEFFECT_H_

// Haptic Library includes
#include <HL/hl.h>

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse zur Kapselung von HLAPI Force Effects.
//...............................................................................
class HapticEffect
{
	protected:
		
		//.......................................................................
		/// @brief	Effekttyp
		///
		///			Zul�ssige Werte:
		///			- HL_EFFECT_CONSTANT
		///			- HL_EFFECT_SPRING
		///			- HL_EFFECT_VISCOUS
		///			- HL_EFFECT_FRICTION
		///			F�r eine detailiertere Beschreibung der Effekttypen, siehe
		///			3D TOUCH SDK - API REFERENCE
		//.......................................................................
		HLenum m_EffectType;
		
		//.......................................................................
		/// @brief	ID, mit der der Effekt bei HLAPI bekannt ist.
		//.......................................................................
		HLuint m_EffectID;

		//.......................................................................
		/// @brief	Muss von abgeleiteten Klassen implementiert werden, um die 
		///			gew�nschten Eigenschaften des Effektes zu spezifizieren.
		//.......................................................................
		virtual void renderProperties() = 0;

	public:

		//.......................................................................
		///	@brief	Konstruktor: Initialisiert das Objekt mit Defaultwerten und 
		///			macht den Effekt bei HLAPI bekannt.
		//.......................................................................
		HapticEffect(HLenum type = HL_EFFECT_CONSTANT);

		//.......................................................................
		/// @brief	Destuktor: Gibt den Effekt bei HLAPI frei.
		//.......................................................................
		virtual ~HapticEffect();
		
		//.......................................................................
		/// @brief	Startet den Effekt. Der Effekt wird so lange gerendert, bis
		///			stopEffekt() aufgerufen wird.
		//.......................................................................
		virtual void startEffect();

		//.......................................................................
		/// @brief	Stoppt einen bereits gestarteten Effekt.
		//.......................................................................
		virtual void stopEffect();

		//.......................................................................
		/// @brief	L�st den Effekt einmalig aus, er dauert dann f�r die mit duration
		///			spezifizierte Zeit an.
		///	@param	duration	Dauer des Effektes in Millisekunden.
		//.......................................................................
		virtual void triggerEffect( double duration = 100.0 );
	
};

#endif