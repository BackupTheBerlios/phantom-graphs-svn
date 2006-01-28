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


#include "Node.h"
#include "GraphScene.h"
//#include "Texture.h"

//*******************************************************************************
Node::Node( IBusinessAdapter * businessObj, UnitConversionInfo & unitInfo  )
: m_rUnitInfo(unitInfo)
{
	m_DisplayList = 0;
	m_pBusinessObject = businessObj;

	float unitWidth		= m_rUnitInfo.getUnitWidth();
	float unitHeight	= m_rUnitInfo.getUnitHeight();
	float pad			= m_rUnitInfo.getHorizontalPadding();

	// Höhe festlegen
	m_Height = unitHeight;

	// Breite und Position vom BusinessObjekt geben lassen
	if (m_pBusinessObject != NULL)
	{
		m_Width = (float)m_pBusinessObject->getWidth() * unitWidth - pad;

		double x = m_pBusinessObject->getBegin() * unitWidth;
		double y = m_pBusinessObject->getLine() * unitHeight;
		HapticObject::setPosition(x, y, 0.0);
	}
	// wenn kein BusinessObjekt da ist, Breite auf 1 Unit setzen
	else
	{
		m_Width = unitWidth - pad;
	}	

	m_IncomingEdges.clear();
	m_OutgoingEdges.clear();
}
//*******************************************************************************

//*******************************************************************************
Node::~Node()
{
	// Displayliste freigeben
	releaseDisplayList();
	
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
/*void Node::setTexture( const Texture* value )
{
}
*/
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
	}

	HapticObject::translate(x, y, z);
	updateEdges();
}
//*******************************************************************************

//*******************************************************************************
void Node::setPosition(const double x, const double y, const double z)
{
	HapticObject::setPosition(x, y, z);
	updateEdges();
}
//*******************************************************************************

//*******************************************************************************
void Node::Update( Observable * pObservable )
{
	float unitWidth = m_rUnitInfo.getUnitWidth();
	m_Width = (float)m_pBusinessObject->getWidth() * unitWidth;

	double x = m_pBusinessObject->getBegin() * unitWidth;
	double y = m_pBusinessObject->getLine() * m_rUnitInfo.getUnitHeight();
	HapticObject::setPosition(x, y, 0.0);
}
//*******************************************************************************



