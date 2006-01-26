//*******************************************************************************
/// @file	Utilities.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte �nderung	24.01.2006
//*******************************************************************************

// �nderungen:
// 24.01.06		- Klasse UnitConversionInfo erstellt
//				- Konstruktor von Position implementiert


#include "Utilities.h"

//*******************************************************************************
Position::Position( double x, double y, double z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}
//*******************************************************************************

//*******************************************************************************
Position::~Position()
{
}
//*******************************************************************************



//*******************************************************************************
// Statische Konstanten intitialisierten
const float UnitConversionInfo::ScreenWidthInViewUnits = 3.6f;
//*******************************************************************************

//*******************************************************************************
UnitConversionInfo::UnitConversionInfo( int upsHorz, int upsVert, 
										float paddingHorz, float paddingVert )
: m_UnitsPerScreenHorizontal(upsHorz), m_UnitsPerScreenVertical(upsVert),
  m_HorizontalPadding(paddingHorz), m_VerticalPadding(paddingVert)
{
}
//*******************************************************************************

//*******************************************************************************
UnitConversionInfo::~UnitConversionInfo()
{
}
//*******************************************************************************

//*******************************************************************************
int UnitConversionInfo::getUnitsPerScreenHorizontal()
{
	return m_UnitsPerScreenHorizontal;
}
//*******************************************************************************

//*******************************************************************************
int UnitConversionInfo::getUnitsPerScreenVertical()
{
	return m_UnitsPerScreenVertical;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::getUnitHeight()
{
	return m_UnitHeight;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::getUnitWidth()
{
	return m_UnitWidth;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::getHorizontalPadding()
{
	return m_HorizontalPadding;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::getVerticalPadding()
{
	return m_VerticalPadding;
}
//*******************************************************************************
