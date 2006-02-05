//*******************************************************************************
/// @file	ConstantForceEffect.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		05.01.2006
/// @date	Letzte Änderung	05.01.2006
//*******************************************************************************

// Änderungen:


#include "ConstantForceEffect.h"

// Haptic Library includes
#include <HL/hl.h>

//*******************************************************************************
ConstantForceEffect::ConstantForceEffect( const double direction[3], double magnitude )
: HapticEffect(HL_EFFECT_CONSTANT)
{
	m_Direction.set(direction[0], direction[1], direction[2]);
	m_Magnitude = magnitude;
}
//*******************************************************************************

//*******************************************************************************
ConstantForceEffect::ConstantForceEffect()
: HapticEffect(HL_EFFECT_CONSTANT)
{
	m_Direction.set(0.0, 0.0, 0.0);
	m_Magnitude = 0.0;
}
//*******************************************************************************

//*******************************************************************************
ConstantForceEffect::~ConstantForceEffect()
{
}
//*******************************************************************************

//*******************************************************************************
void ConstantForceEffect::setDirection( double x, double y, double z )
{
	m_Direction.set(x, y, z);
}
//*******************************************************************************

//*******************************************************************************
void ConstantForceEffect::setMagnitude( double value )
{
	m_Magnitude = value;
}
//*******************************************************************************

//*******************************************************************************
void ConstantForceEffect::renderProperties()
{
	hlEffectd(HL_EFFECT_PROPERTY_MAGNITUDE, m_Magnitude);
	hlEffectdv(HL_EFFECT_PROPERTY_DIRECTION, m_Direction);
}
//*******************************************************************************