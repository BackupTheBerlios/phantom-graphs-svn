//*******************************************************************************
/// @file	HapticEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte Änderung	30.01.2006
//*******************************************************************************

// Änderungen:
// 30.01.06		- startEffect() führt die HLAPI-Funktion nur dann aus, wenn der Effekt
//				  vorher noch nicht gestartet wurde, um HLAPI-Fehler zu vermeiden.
//				- stopEffect() führt die HLAPI-Funktion nur dann aus, wenn der Effekt
//				  vorher gestartet wurde, um HLAPI-Fehler zu vermeiden.


#include "HapticEffect.h"

//*******************************************************************************
HapticEffect::HapticEffect(HLenum type)
: m_EffectID(hlGenEffects(1))
{
	m_EffectType = type;
	m_IsActive = false;
}
//*******************************************************************************

//*******************************************************************************
HapticEffect::~HapticEffect()
{
	// Effekt freigeben
	hlDeleteEffects(m_EffectID, 1);
}
//*******************************************************************************

//*******************************************************************************
void HapticEffect::startEffect()
{
	if (m_IsActive)
	{
		return;	
	}

	// Effekt mit den in der abstrakten Methode renderProperties() spezifizierten 
	// Eigenschaften starten
	renderProperties();
	hlStartEffect(m_EffectType, m_EffectID);
	if (!(HL_NO_ERROR == hlGetError().errorCode))
	{
		// nur zum Debuggen benötigt
		int bla = 1;
	}
	m_IsActive = true;
}
//*******************************************************************************

//*******************************************************************************
void HapticEffect::stopEffect()
{
	if (m_IsActive)
	{
		hlStopEffect(m_EffectID);
		if (HL_INVALID_OPERATION == hlGetError().errorCode)
		{
			// nur zum Debuggen benötigt
			int bla = 1;
		}
		m_IsActive = false;
	}
}
//*******************************************************************************

//*******************************************************************************
void HapticEffect::triggerEffect( double duration )
{
	// Effekt für die Dauer duration (msec) anstoßen
	renderProperties();
	hlEffectd(HL_EFFECT_PROPERTY_DURATION, duration);
	hlTriggerEffect(m_EffectType);
}
//*******************************************************************************
