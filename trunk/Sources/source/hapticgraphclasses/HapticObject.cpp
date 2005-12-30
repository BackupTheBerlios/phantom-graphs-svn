//*******************************************************************************
/// @file	HapticObject.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.12.2005
/// @date	Letzte Änderung	30.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		- Konstruktor und Destruktor implementiert
// 30.12.05		- Dummy-Implementierungen von render*() und renderDefault*Properties()
//				- setPosition implementiert

// Haptics Library includes
#include <HL/hl.h>

// OpenGL includes
#include <GL/gl.h>

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
	// Dummy
	renderDefaultGraphicProperties();

	renderShape();
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderHaptics()
{
	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, m_HLShapeID);
    hlTouchModel(HL_CONTACT);

	// Dummy
    renderDefaultHapticProperties();

    renderShape();
    hlEndShape();
}
//*******************************************************************************

//void HapticObject::setHapticConstraint( const HapticConstraint* value )
//{
//}

//*******************************************************************************
void HapticObject::renderDefaultGraphicProperties()
{
	// Dummy
	glColor3f(1.0f, 1.0f, 0.0f);
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderDefaultHapticProperties()
{
	// Dummy
	hlMaterialf(HL_FRONT, HL_STIFFNESS, 0.8);
    hlMaterialf(HL_FRONT, HL_STATIC_FRICTION, 0.0);
    hlMaterialf(HL_FRONT, HL_DYNAMIC_FRICTION, 0.9);
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::translate(const double x, const double y, const double z)
{
	m_transformMatrix *= hduMatrix::createTranslation(x, y, z);
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::setPosition(const double x, const double y, const double z)
{
	m_transformMatrix = hduMatrix::createTranslation(x, y, z);
}
//*******************************************************************************