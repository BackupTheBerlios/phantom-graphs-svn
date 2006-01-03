//*******************************************************************************
/// @file	Node.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte Änderung	03.01.2006
//*******************************************************************************

// Änderungen:
// 03.01.06		- Methode translate() hinzugefügt


#include "Node.h"
//#include "Texture.h"
#include "../businesslogic/IBusinessAdapter.h"

//*******************************************************************************
Node::Node( IBusinessAdapter * businessObj )
{
	m_pBusinessObject = businessObj;
	m_DisplayList = 0;
}
//*******************************************************************************

//*******************************************************************************
Node::~Node()
{
	// Displayliste freigeben
	glDeleteLists(m_DisplayList, 1);	
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
        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);
		glBegin(GL_QUADS);
		glVertex3f(-0.5f, -0.5f, -0.6f);
		glVertex3f( 0.5f, -0.5f, -0.6f);
		glVertex3f( 0.5f,  0.5f, -0.6f);
		glVertex3f(-0.5f,  0.5f, -0.6f);
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
{}
//*******************************************************************************

