//*******************************************************************************
/// @file	HapticEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte �nderung	03.01.2006
//*******************************************************************************

// �nderungen:


#include "HapticEffect.h"

//*******************************************************************************
HapticEffect::HapticEffect()
: m_EffectID(hlGenEffects(1))
{
	// Member mit Defaultwert belegen
	m_EffectType = HL_EFFECT_CONSTANT;
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
	// Effekt f�r die Dauer duration (msec) ansto�en
	renderProperties();
	hlEffectd(HL_EFFECT_PROPERTY_DURATION, duration);
	hlTriggerEffect(m_EffectType);
}
//*******************************************************************************
