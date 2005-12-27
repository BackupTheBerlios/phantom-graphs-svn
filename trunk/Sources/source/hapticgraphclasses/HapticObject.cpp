//*******************************************************************************
/// @file	HapticObject.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	26.12.2005
//*******************************************************************************


#include "HapticObject.h"
//#include "GraphicalProperty.h"
//#include "HapticProperty.h"
#include "HapticAction.h"
//#include "Utilities.h"
//#include "HapticConstraint.h"

//*******************************************************************************
HapticObject::HapticObject()
{
}
//*******************************************************************************

//void HapticObject::addGraphicMaterial( IGraphicMaterial * material )
//{
//}

//*******************************************************************************
void HapticObject::addHapticAction( IHapticAction * act )
{
}
//*******************************************************************************

//void HapticObject::addHapticMaterial( IHapticMaterial * material )
//{
//}

//*******************************************************************************
void HapticObject::renderGraphics()
{
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderHaptics()
{
}
//*******************************************************************************

//void HapticObject::setHapticConstraint( const HapticConstraint* value )
//{
//}

//void HapticObject::setPosition( const Position & value )
//{
//}

//*******************************************************************************
HapticObject::~HapticObject()
{
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderDefaultGraphicProperties()
{
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderDefaultHapticProperties()
{
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::translate(const double x, const double y, const double z)
{
	m_transformMatrix *= hduMatrix::createTranslation(x, y, z);
}
//*******************************************************************************