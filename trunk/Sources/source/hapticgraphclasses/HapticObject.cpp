//*******************************************************************************
/// @file	HapticObject.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		- Konstruktor und Destruktor implementiert

#include "HapticObject.h"
//#include "GraphicalProperty.h"
//#include "HapticProperty.h"
#include "HapticAction.h"
//#include "Utilities.h"
//#include "HapticConstraint.h"

//*******************************************************************************
HapticObject::HapticObject()
{
	m_HLShapeID = hlGenShapes(1);
	m_constraintSID = hlGenShapes(1);
	m_transformMatrix.makeIdentity();
}
//*******************************************************************************

//*******************************************************************************
HapticObject::~HapticObject()
{
	// Shapes für Haptik freigeben
	hlDeleteShapes(m_HLShapeID, 1);
	hlDeleteShapes(m_constraintSID, 1);

	// evtl. vorhandene Actionhandler freigeben
	vector<IHapticAction*>::iterator iterAct = NULL;
	for (iterAct = m_hapticActions.begin(); iterAct != m_hapticActions.end(); iterAct++)
	{
		if (*iterAct != NULL)
		{
			(*iterAct)->unregisterAction(m_HLShapeID);
			delete (*iterAct);
			(*iterAct) = NULL;
		}
	}
}
//*******************************************************************************

//void HapticObject::addGraphicMaterial( IGraphicMaterial * material )
//{
//}

//*******************************************************************************
void HapticObject::addHapticAction( IHapticAction * act )
{
	m_hapticActions.push_back(act);
	act->registerAction(m_HLShapeID);
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