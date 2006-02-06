//*******************************************************************************
/// @file	Edge.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		27.01.2006
/// @date	Letzte Änderung	27.01.2006
//*******************************************************************************

// Änderungen:


#include "Edge.h"
#include "GraphScene.h"

//*******************************************************************************
Edge::Edge( Position start, Position end )
{
	m_DisplayList = 0;
	m_StartPosition = start;
	m_EndPosition = end;
}
//*******************************************************************************

//*******************************************************************************
Edge::~Edge()
{
	// Displayliste freigeben
	releaseDisplayList();
}
//*******************************************************************************

//*******************************************************************************
void Edge::setStartPosition( Position value )
{
	// wenn sich an den Vektoren (also Start- oder Endpunkt) etwas ändert, muss 
	// die Displayliste neu kompiliert werden, deshalb vorher freigeben.
	releaseDisplayList();
	m_StartPosition = value;
}
//*******************************************************************************

//*******************************************************************************
void Edge::setEndPosition( Position value )
{
	// wenn sich an den Vektoren (also Start- oder Endpunkt) etwas ändert, muss 
	// die Displayliste neu kompiliert werden, deshalb vorher freigeben.
	releaseDisplayList();
	m_EndPosition = value;
}
//*******************************************************************************

//*******************************************************************************
void Edge::releaseDisplayList()
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
void Edge::renderShape()
{
	if (m_DisplayList != 0)
    {
        glCallList(m_DisplayList);
    }
    else
    {
		float graphPlaneZ = GraphScene::getGraphPlaneZ();

        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);

		glLineWidth(3.0);
		glBegin(GL_LINES);

		// Startpunkt
		glVertex3f( m_StartPosition.x,	m_StartPosition.y,	graphPlaneZ);
		// Endpunkt
		glVertex3f( m_EndPosition.x,	m_EndPosition.y,	graphPlaneZ);

		glEnd();
        glEndList();
    }
}
//*******************************************************************************

//*******************************************************************************
void Edge::renderDefaultGraphicProperties()
{
	glDisable(GL_LIGHTING);
	glColor3f(0.0f, 0.0f, 0.0f);
}
//*******************************************************************************


