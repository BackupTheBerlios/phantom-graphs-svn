//*******************************************************************************
/// @file	HapticConstraint.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	08.01.2006
//*******************************************************************************

// Änderungen:
// 08.01.06		- Implementierung der Klasse


#include "HapticConstraint.h"
#include "HapticObject.h"

//*******************************************************************************
HapticConstraint::HapticConstraint( HLfloat snapDist )
: m_HLConstraintID(hlGenShapes(1))
{
	m_SnapDistance = snapDist;
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
	hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, m_HLConstraintID);

    hlTouchModel(HL_CONSTRAINT);
    hlTouchModelf(HL_SNAP_DISTANCE, m_SnapDistance);
	
	pObj->renderShape();

	hlEndShape();
}
//*******************************************************************************

//*******************************************************************************
void HapticConstraint::setSnapDistance( HLfloat value )
{
	m_SnapDistance = value;
}
//*******************************************************************************
