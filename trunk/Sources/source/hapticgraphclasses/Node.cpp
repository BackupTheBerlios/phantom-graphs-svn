//*******************************************************************************
/// @file	Node.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte Änderung	30.12.2005
//*******************************************************************************

// Änderungen:


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
void Node::Update( Observable * pObservable )
{}
//*******************************************************************************

