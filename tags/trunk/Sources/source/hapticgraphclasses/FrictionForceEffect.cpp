//*******************************************************************************
/// @file	FrictionForceEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		06.01.2006
/// @date	Letzte Änderung	06.01.2006
//*******************************************************************************

// Änderungen:


#include "FrictionForceEffect.h"

//*******************************************************************************
FrictionForceEffect::FrictionForceEffect( double magnitude, double gain )
: HapticEffect(HL_EFFECT_FRICTION)
{
	m_Magnitude = magnitude;
	m_Gain = gain;
}
//*******************************************************************************

//*******************************************************************************
void FrictionForceEffect::setGain( double value )
{
	m_Gain = value;
}
//*******************************************************************************

//*******************************************************************************
void FrictionForceEffect::setMagnitude( double value )
{
	m_Magnitude = value;
}
//*******************************************************************************

//*******************************************************************************
FrictionForceEffect::~FrictionForceEffect()
{
}
//*******************************************************************************

//*******************************************************************************
void FrictionForceEffect::renderProperties()
{
	hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, m_Magnitude);
	hlEffectd(HL_EFFECT_PROPERTY_GAIN, m_Gain);
}
//*******************************************************************************