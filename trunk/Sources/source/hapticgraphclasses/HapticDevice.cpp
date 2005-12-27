//*******************************************************************************
/// @file	HapticDevice.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	26.12.2005
//*******************************************************************************


#include <HLU/hlu.h>
#include <GL/gl.h>

#include "HapticDevice.h"
#include "..\exceptionclasses\HapticsExceptions.h"

//*******************************************************************************
HapticDevice::HapticDevice()
{
	m_hHapticDevice = HD_INVALID_HANDLE;
	m_hHLRenderingContext = NULL;
}
//*******************************************************************************

//*******************************************************************************
HapticDevice::~HapticDevice()
{
	// Den Haptic Rendering Context freigeben
    hlMakeCurrent(NULL);
    if (m_hHLRenderingContext != NULL)
    {
        hlDeleteContext(m_hHLRenderingContext);
		m_hHLRenderingContext = NULL;
    }

    // Das Haptic Device freigeben
    if (m_hHapticDevice != HD_INVALID_HANDLE)
    {
        hdDisableDevice(m_hHapticDevice);
		m_hHapticDevice = HD_INVALID_HANDLE;
    }
}
//*******************************************************************************

//*******************************************************************************
void HapticDevice::initialize()
{
    m_hHapticDevice = hdInitDevice(HD_DEFAULT_DEVICE);
    if (HD_DEVICE_ERROR(hdGetError()))
    {
		throw HDInitialisationFailedException("Unable to initialize Haptic Device!");
    }

    m_hHLRenderingContext = hlCreateContext(m_hHapticDevice);
    hlMakeCurrent(m_hHLRenderingContext);
}
//*******************************************************************************

//*******************************************************************************
bool HapticDevice::isActive()
{
	return (m_hHapticDevice != HD_INVALID_HANDLE);
}
//*******************************************************************************

//*******************************************************************************
void HapticDevice::updateWorkspace()
{
	GLdouble modelview[16];
    GLdouble projection[16];
    GLint viewport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    hlMatrixMode(HL_TOUCHWORKSPACE);
    hlLoadIdentity();
    
    /* fit haptic workspace to view volume */
    hluFitWorkspace(projection);
}
//*******************************************************************************
