//*******************************************************************************
/// @file	HapticObject.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.12.2005
/// @date	Letzte Änderung	08.01.2006
//*******************************************************************************

// Änderungen:
// 27.12.05		- Konstruktor und Destruktor implementiert
// 30.12.05		- Dummy-Implementierungen von render*() und renderDefault*Properties()
//				- setPosition implementiert
// 03.01.06		- Methode getPosition() hinzugefügt und implementiert
// 08.01.06		- setHapticConstraint() implementiert, Konstruktor und Destruktor angepasst
//				  und in renderHaptics() einen Aufruf von m_pHapticConstraint->renderConstraint()
//				  hinzugefügt

// Haptics Library includes
#include <HL/hl.h>

// OpenGL includes
#include <GL/gl.h>

#include "HapticObject.h"
//#include "GraphicalProperty.h"
//#include "HapticProperty.h"


//*******************************************************************************
HapticObject::HapticObject()
: m_HLShapeID(hlGenShapes(1))
{
	m_pHapticConstraint = NULL;
	m_transformMatrix.makeIdentity();
}
//*******************************************************************************

//*******************************************************************************
HapticObject::~HapticObject()
{
	// Shapes für Haptik freigeben
	hlDeleteShapes(m_HLShapeID, 1);
//	hlDeleteShapes(m_constraintSID, 1);

	// evtl. vorhandene Actionhandler freigeben
	vector<IHapticAction*>::iterator iterAct = NULL;
	for (iterAct = m_HapticActions.begin(); iterAct != m_HapticActions.end(); iterAct++)
	{
		if (*iterAct != NULL)
		{
			(*iterAct)->unregisterAction(m_HLShapeID);
			delete (*iterAct);
			(*iterAct) = NULL;
		}
	}

	// Constraint freigeben, wenn eins vorhanden ist
	if (m_pHapticConstraint != NULL)
	{
		delete m_pHapticConstraint;
		m_pHapticConstraint = NULL;
	}
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::setHapticConstraint( HapticConstraint* value )
{
	// falls schon ein Constraint vorhanden ist, erst freigeben
	if (m_pHapticConstraint != NULL)
	{
		delete m_pHapticConstraint;
	}

	m_pHapticConstraint = value;
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::addHapticAction( IHapticAction * act )
{
	m_HapticActions.push_back(act);
	act->registerAction(m_HLShapeID);
}
//*******************************************************************************

//void HapticObject::addGraphicMaterial( IGraphicMaterial * material )
//{
//}

//void HapticObject::addHapticMaterial( IHapticMaterial * material )
//{
//}

//*******************************************************************************
void HapticObject::renderGraphics()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	// Dummy
	renderDefaultGraphicProperties();

	glPushMatrix();
	glMultMatrixd(m_transformMatrix);
    renderShape();
	glPopMatrix();

	glPopAttrib();
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderHaptics()
{
	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, m_HLShapeID);
    hlTouchModel(HL_CONTACT);

	// Dummy
    renderDefaultHapticProperties();

	glPushMatrix();
	glMultMatrixd(m_transformMatrix);
    renderShape();
	glPopMatrix();

    hlEndShape();

	if (m_pHapticConstraint != NULL)
	{
		m_pHapticConstraint->renderConstraint(this);
	}
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderDefaultGraphicProperties()
{
	// Dummy
	glDisable(GL_LIGHTING);
	glColor3f(0.43f, 0.48f, 0.64f);
}
//*******************************************************************************

//*******************************************************************************
void HapticObject::renderDefaultHapticProperties()
{
	// Dummy
	hlMaterialf(HL_FRONT, HL_STIFFNESS, 0.8f);
    hlMaterialf(HL_FRONT, HL_STATIC_FRICTION, 0.0f);
    hlMaterialf(HL_FRONT, HL_DYNAMIC_FRICTION, 0.9f);
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

//*******************************************************************************
Position HapticObject::getPosition()
{
	hduVector3Dd origin;
	hduVector3Dd pos(origin * m_transformMatrix);
	return Position(pos[0], pos[1], pos[2]);
}
//*******************************************************************************
