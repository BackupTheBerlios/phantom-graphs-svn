//*******************************************************************************
/// @file	Camera.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.01.2006
/// @date	Letzte Änderung	26.01.2006
//*******************************************************************************

// Änderungen:


#include <math.h>

// wird von gl.h benötigt
#include <windows.h>

// OpenGL includes
#include <GL/gl.h>
#include <GL/glu.h>

// eigene includes
#include "Camera.h"


//*******************************************************************************
Camera::Camera( double fovY, int viewportWidth, int viewportHeight, HapticDevice * pHd )
{
	m_LastX = 0.0;
	m_LastY = 0.0;
	m_FovY = fovY;
	m_pHapticDevice = pHd;
	recalculateView(viewportWidth, viewportHeight);
}
//*******************************************************************************

//*******************************************************************************
Camera::~Camera()
{
}
//*******************************************************************************

//*******************************************************************************
double Camera::getRatio()
{
	return m_Ratio;
}
//*******************************************************************************

//*******************************************************************************
void Camera::recalculateView( int viewportWidth, int viewportHeight )
{
	
    static const double c_PI = 3.1415926535897932384626433832795;

    glViewport(0, 0, viewportWidth, viewportHeight);

    // Compute the viewing parameters based on a fixed fov and viewing
    // a canonical box centered at the origin 
    m_NearDistance = 1.0 / tan((m_FovY / 2.0) * c_PI / 180.0);
    m_FarDistance = m_NearDistance + 2.0;
    m_Ratio = (double) viewportWidth / viewportHeight;
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(m_FovY, m_Ratio, m_NearDistance, m_FarDistance);

    // Place the camera down the Z axis looking at the origin 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();            
    gluLookAt(m_LastX, m_LastY, m_NearDistance + 1.0,
              m_LastX, m_LastY, 0,
              0, 1, 0);

	if (m_pHapticDevice != NULL)
	{
		m_pHapticDevice->updateWorkspace();
	}
}
//*******************************************************************************

//*******************************************************************************
void Camera::translateView( double x, double y )
{
	m_LastX += x;
	m_LastY += y;
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(m_LastX, m_LastY, m_NearDistance + 1.0,
              m_LastX, m_LastY, 0,
              0, 1, 0);

	if (m_pHapticDevice != NULL)
	{
		m_pHapticDevice->updateWorkspace();
	}
}
//*******************************************************************************

