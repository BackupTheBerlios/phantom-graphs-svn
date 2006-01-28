//*******************************************************************************
/// @file	SpringForceEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		28.01.2006
/// @date	Letzte Änderung	28.01.2006
//*******************************************************************************

// Änderungen:


#include "SpringForceEffect.h"

//*******************************************************************************
SpringForceEffect::SpringForceEffect( double magnitude, double gain, Position anchor )
: HapticEffect(HL_EFFECT_SPRING)
{
	m_Magnitude = magnitude;
	m_Gain = gain;
	m_AnchorPosition[0] = anchor.x;
	m_AnchorPosition[1] = anchor.y;
	m_AnchorPosition[2] = anchor.z;
}
//*******************************************************************************

//*******************************************************************************
SpringForceEffect::~SpringForceEffect()
{
}
//*******************************************************************************

//*******************************************************************************
void SpringForceEffect::setAnchorPosition( double x, double y, double z )
{
	m_AnchorPosition[0] = x;
	m_AnchorPosition[1] = y;
	m_AnchorPosition[2] = z;
}
//*******************************************************************************

//*******************************************************************************
void SpringForceEffect::setGain( double value )
{
	m_Gain = value;
}
//*******************************************************************************

//*******************************************************************************
void SpringForceEffect::setMagnitude( double value )
{
	m_Magnitude = value;
}
//*******************************************************************************

//*******************************************************************************
void SpringForceEffect::renderProperties()
{
	hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, m_Magnitude);
	hlEffectd(HL_EFFECT_PROPERTY_GAIN, m_Gain);
	hlEffectdv(HL_EFFECT_PROPERTY_POSITION, m_AnchorPosition);
}
//*******************************************************************************
