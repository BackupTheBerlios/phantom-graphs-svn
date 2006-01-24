//*******************************************************************************
/// @file	Node.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte Änderung	08.01.2006
//*******************************************************************************

// Änderungen:
// 03.01.06		- Methode translate() hinzugefügt
// 08.01.06		- Methoden getHeight(), getWidth(), setHeight(), setWidth() hinzugefügt
//				  und implementiert
//				- Konstruktor angepasst


#include "Node.h"
#include "GraphScene.h"
//#include "Texture.h"

//*******************************************************************************
Node::Node( IBusinessAdapter * businessObj )
{
	m_DisplayList = 0;
	m_pBusinessObject = businessObj;
	if (m_pBusinessObject != NULL)
	{
		// Höhe und Breite vom BusinessObjekt geben lassen
	}
	else
	{
		m_Width = 0.1f;
		m_Height = 0.1f;
	}
}
//*******************************************************************************

//*******************************************************************************
Node::~Node()
{
	// Displayliste freigeben
	releaseDisplayList();	
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

        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);
		glBegin(GL_QUADS);

		float halfHeight = m_Height / 2;

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
		
	}
	HapticObject::translate(x, y, z);
}
//*******************************************************************************

//*******************************************************************************
void Node::Update( Observable * pObservable )
{
}
//*******************************************************************************



