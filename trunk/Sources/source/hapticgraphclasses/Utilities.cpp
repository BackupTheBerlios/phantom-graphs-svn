//*******************************************************************************
/// @file	Utilities.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte Änderung	28.01.2006
//*******************************************************************************

// Änderungen:
// 24.01.06		- Klasse UnitConversionInfo erstellt
//				- Konstruktor von Position implementiert
// 28.01.06		- Konstruktor von UnitConversionInfo dummymäßig implementiert.
//				- UnitConversionInfo: Umrechnungsmethoden xValueToUnit(), yValueToUnit()
//				  unitToXValue(), unitToYValue() hinzugefügt und implementiert.


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
Position Position::operator+(Position pos)
{
	Position result = *this;
	result.x += pos.x;
	result.y += pos.y;
	result.z += pos.z;

	return result;
}
//*******************************************************************************

//*******************************************************************************
Position Position::operator+(double value)
{
	Position result = *this;
	result.x += value;
	result.y += value;
	result.z += value;

	return result;
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
	// Dummy
	m_UnitWidth = 0.1f + m_HorizontalPadding;
	m_UnitHeight = 0.2f + m_VerticalPadding;
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
//	return m_UnitWidth;
	// Dummy
	return 0.12f;
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

//*******************************************************************************
float UnitConversionInfo::xValueToUnit(float xValue)
{
	return xValue / m_UnitWidth;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::yValueToUnit(float yValue)
{
	return yValue / m_UnitHeight;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::unitToXValue(float unit)
{
	return unit * m_UnitWidth;
}
//*******************************************************************************

//*******************************************************************************
float UnitConversionInfo::unitToYValue(float unit)
{
	return unit * m_UnitHeight;
}
//*******************************************************************************
