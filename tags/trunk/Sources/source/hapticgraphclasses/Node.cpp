//*******************************************************************************
/// @file	Node.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte Änderung	28.01.2006
//*******************************************************************************

// Änderungen:
// 03.01.06		- Methode translate() hinzugefügt
// 08.01.06		- Methoden getHeight(), getWidth(), setHeight(), setWidth() hinzugefügt
//				  und implementiert
//				- Konstruktor angepasst
// 27.01.06		- Incoming- und Outgoing Edges und dazugehörige Methoden hinzugefügt.
// 28.01.06		- Knoten holt sich Breite und Position jetzt von seinem BusinessObjekt.

// Haptic Library includes
#include <HL/hl.h>

// eigene includes
#include "Node.h"
#include "GraphScene.h"
#include "FrictionForceEffect.h"
#include "SpringForceEffect.h"


//*******************************************************************************
Node::Node( IBusinessAdapter * businessObj, UnitConversionInfo & unitInfo  )
: m_rUnitInfo(unitInfo)
{
	m_DisplayList = 0;
	m_pBusinessObject = businessObj;

	float unitWidth		= m_rUnitInfo.getUnitWidth();
	float unitHeight	= m_rUnitInfo.getUnitHeight();
	float pad			= m_rUnitInfo.getHorizontalPadding();

	// Höhe auf 1 Unit festlegen
	m_Height = m_rUnitInfo.unitToYValue(1);

	// Breite und Position vom BusinessObjekt geben lassen
	if (m_pBusinessObject != NULL)
	{
		m_pBusinessObject->AddObserver(this);
		Update(m_pBusinessObject);
	}
	// wenn kein BusinessObjekt da ist, Breite auf 1 Unit setzen
	else
	{
		m_Width = m_rUnitInfo.unitToXValue(1) - pad;
	}	

	// Effekte standardmäßig belegen
	m_pHardToMoveEffect			= new FrictionForceEffect(1.0, 0.5);
	m_pImpossibleToMoveEffect	= new FrictionForceEffect(100.0, 90.0); 

	m_IncomingEdges.clear();
	m_OutgoingEdges.clear();
}
//*******************************************************************************

//*******************************************************************************
Node::~Node()
{
	// Displayliste freigeben
	releaseDisplayList();

	// Effekte freigeben
	if (m_pHardToMoveEffect != NULL)
	{
		delete m_pHardToMoveEffect;
		m_pHardToMoveEffect = NULL;
	}
	
	if (m_pImpossibleToMoveEffect != NULL)
	{
		delete m_pImpossibleToMoveEffect;
		m_pImpossibleToMoveEffect = NULL;
	}

	// Inhalte der Kantenlisten löschen, die Pointer auf die Kanten müssen extern
	// freigegeben werden.
	m_IncomingEdges.clear();
	m_OutgoingEdges.clear();
}
//*******************************************************************************

//*******************************************************************************
void Node::releaseDisplayList()
{
	if (m_DisplayList != 0)
	{
		// Displayliste freigeben
		glDeleteLists(m_DisplayList, 1);
		m_DisplayList = 0;
	}
}
//*******************************************************************************

//*******************************************************************************
float Node::getHeight()
{
	return m_Height;
}
//*******************************************************************************

//*******************************************************************************
float Node::getWidth()
{
	return m_Width;
}
//*******************************************************************************

//*******************************************************************************
void Node::setHeight( float value )
{
	m_Height = value;

	// Wenn sich was an der Geometrie ändert, muss die Displayliste neu kompiliert
	// werden, also erst mal freigeben.
	releaseDisplayList();
}
//*******************************************************************************

//*******************************************************************************
void Node::setWidth( float value )
{
	m_Width = value;

	// Wenn sich was an der Geometrie ändert, muss die Displayliste neu kompiliert
	// werden, also erst mal freigeben.
	releaseDisplayList();
}
//*******************************************************************************

//*******************************************************************************
void Node::addIncomingEdge( Edge * pEdge )
{
	if (pEdge != NULL)
	{
		updateIncomingEdge(pEdge);
		m_IncomingEdges.push_back(pEdge);
	}
}
//*******************************************************************************

//*******************************************************************************
void Node::addOutgoingEdge( Edge * pEdge )
{
	if (pEdge != NULL)
	{		
		updateOutgoingEdge(pEdge);
		m_OutgoingEdges.push_back(pEdge);
	}
}
//*******************************************************************************

//*******************************************************************************
void Node::updateIncomingEdge(Edge * pEdge)
{
	pEdge->setEndPosition(this->getPosition());
}
//*******************************************************************************

//*******************************************************************************
void Node::updateOutgoingEdge(Edge * pEdge)
{
	Position tmpPos = getPosition();
	tmpPos.x += getWidth();
	pEdge->setStartPosition(tmpPos);
}
//*******************************************************************************

//*******************************************************************************
void Node::updateEdges()
{
	// Den Kanten die neue Position mitteilen:
	// Eingehende Kanten updaten
	list<Edge *>::iterator edgeIter;
	for (edgeIter = m_IncomingEdges.begin(); edgeIter != m_IncomingEdges.end(); edgeIter++)
	{
		if ((*edgeIter) != NULL)
		{
			updateIncomingEdge(*edgeIter);
		}
	}

	// Ausgehende Kanten updaten
	for (edgeIter = m_OutgoingEdges.begin(); edgeIter != m_OutgoingEdges.end(); edgeIter++)
	{
		if ((*edgeIter) != NULL)
		{
			updateOutgoingEdge(*edgeIter);
		}
	}
}
//*******************************************************************************

//*******************************************************************************
void Node::setHardToMoveEffect( HapticEffect * value )
{
}
//*******************************************************************************

//*******************************************************************************
void Node::setImpossibleToMoveEffect( HapticEffect * value )
{
}
//*******************************************************************************

//*******************************************************************************
void Node::renderShape()
{
    if (m_DisplayList != 0)
    {
        glCallList(m_DisplayList);
    }
    else
    {
		float graphPlaneZ = GraphScene::getGraphPlaneZ();
		//float pad = m_rUnitInfo.getHorizontalPadding();
		float halfVPad = m_rUnitInfo.getVerticalPadding() / 2.0f;
		float halfHeight = m_Height / 2.0f - halfVPad;
		

        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);
		glBegin(GL_QUADS);

		// linke untere Ecke
		glVertex3f( 0.0f,		-halfHeight,	graphPlaneZ);
		// rechte untere Ecke
		glVertex3f( m_Width,	-halfHeight,	graphPlaneZ);
		// rechte obere Ecke
		glVertex3f( m_Width,	 halfHeight,	graphPlaneZ);
		// linke obere Ecke
		glVertex3f( 0.0f,		 halfHeight,	graphPlaneZ);

		glEnd();
        glEndList();
    }
}
//*******************************************************************************

//*******************************************************************************
void Node::translate(const double x, const double y, const double z)
{
	if (m_pBusinessObject != NULL)
	{
		// Business-Objekt fragen, ob und wie schwer sich der Knoten bewegen lassen
		// soll.
		float xUnits = m_rUnitInfo.xValueToUnit(x);
		float yUnits = m_rUnitInfo.yValueToUnit(y);
		force f = incredible;
		f = m_pBusinessObject->getForce(xUnits, yUnits);
		switch(f)
		{
			case none:
			{
				// der Node darf sich frei bewegen, keine Aktion nötig.
				// Eventuell aktive Effekte müssen gestoppt werden.
				m_pHardToMoveEffect->stopEffect();
				m_pImpossibleToMoveEffect->stopEffect();
				break;
			}
			case medium:
			{
				// ForceEffect für schweres Bewegen aktivieren und den anderen Effekt
				// falls nötig stoppen.
				m_pImpossibleToMoveEffect->stopEffect();
				m_pHardToMoveEffect->startEffect();
				break;
			}
			case incredible:
			{
				// ForceEffect, der jede Bewegung blockieren soll, aktivieren und 
				// den anderen Effekt falls nötig stoppen.
				m_pHardToMoveEffect->stopEffect();
				m_pImpossibleToMoveEffect->startEffect();
				break;
			}
			default:
			{
				// Eventuell aktive Effekte müssen gestoppt werden.
				m_pHardToMoveEffect->stopEffect();
				m_pImpossibleToMoveEffect->stopEffect();
				break;
			}
		}
	}

	HapticObject::translate(x, y, z);
	updateEdges();
}
//*******************************************************************************

//*******************************************************************************
void Node::setPosition(const double x, const double y, const double z)
{
	if (m_pBusinessObject != NULL)
	{
		float xUnits = m_rUnitInfo.xValueToUnit(x);
		m_pBusinessObject->setBegin(xUnits);
		Update(m_pBusinessObject);

		m_pHardToMoveEffect->stopEffect();
		m_pImpossibleToMoveEffect->stopEffect();
	}
	else
	{
		HapticObject::setPosition(x, y, z);
		updateEdges();
	}
}
//*******************************************************************************

//*******************************************************************************
void Node::Update( Observable * pObservable )
{
	float pad = m_rUnitInfo.getHorizontalPadding();

	// Breite vom BusinessObjekt erfragen
	m_Width = m_rUnitInfo.unitToXValue((float)m_pBusinessObject->getWidth()) - pad;

	// Position erfragen
	double x = m_rUnitInfo.unitToXValue(m_pBusinessObject->getBegin());
	double y = m_rUnitInfo.unitToYValue(m_pBusinessObject->getLine());
	HapticObject::setPosition(x, y, 0.0);

	updateEdges();
}
//*******************************************************************************



