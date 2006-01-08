//*******************************************************************************
/// @file	ViscousForceEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		08.01.2006
/// @date	Letzte Änderung	08.01.2006
//*******************************************************************************

// Änderungen:


#include "ViscousForceEffect.h"

//*******************************************************************************
ViscousForceEffect::ViscousForceEffect( double magnitude, double gain )
: HapticEffect(HL_EFFECT_VISCOUS)
{
	m_Magnitude = magnitude;
	m_Gain = gain;
}
//*******************************************************************************

//*******************************************************************************
ViscousForceEffect::~ViscousForceEffect()
{
}
//*******************************************************************************

//*******************************************************************************
void ViscousForceEffect::setGain( double value )
{
	m_Gain = value;
}
//*******************************************************************************

//*******************************************************************************
void ViscousForceEffect::setMagnitude( double value )
{
	m_Magnitude = value;
}
//*******************************************************************************

//*******************************************************************************
void ViscousForceEffect::renderProperties()
{
	hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, m_Magnitude);
	hlEffectd(HL_EFFECT_PROPERTY_GAIN, m_Gain);
}
//*******************************************************************************