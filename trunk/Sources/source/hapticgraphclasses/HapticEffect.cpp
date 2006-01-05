//*******************************************************************************
/// @file	HapticEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte Änderung	03.01.2006
//*******************************************************************************

// Änderungen:


#include "HapticEffect.h"

//*******************************************************************************
HapticEffect::HapticEffect(HLenum type)
: m_EffectID(hlGenEffects(1))
{
	// Member mit Defaultwert belegen
	m_EffectType = type;
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
	// Effekt mit den in der abstrakten Methode renderProperties() spezifizierten 
	// Eigenschaften starten
	renderProperties();
	hlStartEffect(m_EffectType, m_EffectID);
}
//*******************************************************************************

//*******************************************************************************
void HapticEffect::stopEffect()
{
	hlStopEffect(m_EffectID);
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
