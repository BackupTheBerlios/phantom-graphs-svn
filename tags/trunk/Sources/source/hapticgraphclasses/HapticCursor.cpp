//*******************************************************************************
/// @file	HapticCursor.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		- Konstruktor hinzugefügt
//				- Konstruktor, render() und scale() implementiert

// Haptics Library includes
#include <HL/hl.h>	
#include <HLU/hlu.h>

// OpenGL includes
#include <GL/gl.h>
#include <GL/glu.h>

#include "HapticCursor.h"

//*******************************************************************************
HapticCursor::HapticCursor(int sizePix)
: m_SizePixels(sizePix)
{
	m_Scale = 1.0;
	m_DisplayList = 0;
}
//*******************************************************************************

//*******************************************************************************
HapticCursor::~HapticCursor()
{
	// Displayliste freigeben
	glDeleteLists(m_DisplayList, 1);
}
//*******************************************************************************

//*******************************************************************************
void HapticCursor::render()
{
	static const double kCursorRadius = 0.5;
    static const double kCursorHeight = 1.5;
    static const int kCursorTess = 15;

    HLdouble proxyxform[16];
    GLUquadricObj *qobj = 0;

    glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT);
    glPushMatrix();

	// Geometrie des Cursors erzeugen
    if (m_DisplayList == 0)
    {
        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE);
        qobj = gluNewQuadric();
               
        gluCylinder(qobj, 0.0, kCursorRadius, kCursorHeight,
                            kCursorTess, kCursorTess);
        glTranslated(0.0, 0.0, kCursorHeight);
        gluCylinder(qobj, kCursorRadius, 0.0, kCursorHeight / 5.0,
                    kCursorTess, kCursorTess);
    
        gluDeleteQuadric(qobj);
        glEndList();
    }
    
    // Get the proxy transform in world coordinates
    hlGetDoublev(HL_PROXY_TRANSFORM, proxyxform);
    glMultMatrixd(proxyxform);

    // Apply the local cursor scale factor.
    glScaled(m_Scale, m_Scale, m_Scale);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.0, 0.5, 1.0);

    glCallList(m_DisplayList);

    glPopMatrix(); 
    glPopAttrib();
}
//*******************************************************************************

//*******************************************************************************
void HapticCursor::scale()
{
	GLdouble modelview[16];
    GLdouble projection[16];
    GLint viewport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    // Skalierung für den Cursor berechnen
    m_Scale = hluScreenToModelScale(modelview, projection, viewport);
    m_Scale *= m_SizePixels;
}
//*******************************************************************************
