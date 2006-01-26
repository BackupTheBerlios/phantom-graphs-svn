//*******************************************************************************
/// @file	HapticConstraint.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	23.01.2006
//*******************************************************************************

// Änderungen:
// 08.01.06		- Implementierung der Klasse
// 23.01.06		- Der Constraint wird jetzt an der richtigen Stelle gerendert.


#include "HapticConstraint.h"
#include "HapticObject.h"

//*******************************************************************************
HapticConstraint::HapticConstraint( HLfloat snapDist )
: m_HLConstraintID(hlGenShapes(1))
{
	m_SnapDistance = snapDist;
	m_Enabled = true;
}
//*******************************************************************************

//*******************************************************************************
HapticConstraint::~HapticConstraint()
{
	// Shape bei HLAPI deregistrieren
	hlDeleteShapes(m_HLConstraintID, 1);
}
//*******************************************************************************

//*******************************************************************************
void HapticConstraint::renderConstraint( HapticObject * pObj )
{
	// den Constraint nur dann rendern, wenn er aktiviert ist
	if (!m_Enabled)
	{
		return;
	}

	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, m_HLConstraintID);

    hlTouchModel(HL_CONSTRAINT);
    hlTouchModelf(HL_SNAP_DISTANCE, m_SnapDistance);
	
	pObj->renderShapeAtPosition();

	hlEndShape();
}
//*******************************************************************************

//*******************************************************************************
void HapticConstraint::setSnapDistance( HLfloat value )
{
	m_SnapDistance = value;
}
//*******************************************************************************

//*******************************************************************************
bool HapticConstraint::enable()
{
	bool before = m_Enabled;
	m_Enabled = true;
	return before;
}
//*******************************************************************************

//*******************************************************************************
bool HapticConstraint::disable()
{
	bool before = m_Enabled;
	m_Enabled = false;
	return before;
}
//*******************************************************************************
