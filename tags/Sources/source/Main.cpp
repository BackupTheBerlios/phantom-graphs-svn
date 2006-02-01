/*****************************************************************************

Copyright (c) 2004 SensAble Technologies, Inc. All rights reserved.

OpenHaptics(TM) toolkit. The material embodied in this software and use of
this software is subject to the terms and conditions of the clickthrough
Development License Agreement.

For questions, comments or bug reports, go to forums at: 
    http://dsc.sensable.com

Module Name:

  Constraints.cpp

Description: 

  This example demonstrates haptic rendering of constraints
  (shapes that you stick to) using the HL_CONSTRAINT touch model.

******************************************************************************/

//*******************************************************************************
/// @file	Main.cpp
/// @author	angepasst von Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	28.01.2006 (CA)
//*******************************************************************************

// �nderungen:
// 26.12.05		- Die vorhandenen Shapes und zugeh�rigen Aufrufe des 
//				  Constraint-Demo-Programms entfernt (KG)
//				- Initialisierung des Haptischen Ger�tes wird jetzt von der Klasse
//				  HapticDevice durchgef�hrt (KG)
// 27.12.05		- nicht ben�tigten Code entfernt (KG)
//				- Cursor wird jetzt von Cursor-Objekt gezeichnet (KG)
// 30.12.05		- Fenster etwas vergr��ert (KG)
//				- nicht ben�tigte Funktionen gel�scht (KG)
// 06.01.2006	- Task Erzeugung hinzugef�gt CA
// 09.01.2006	- include der AppConfiguration CA
// 26.01.06		- Berechnung des Sichtvolumens wird von neuer Camera-Klasse �bernommen 
//				  und  �ber GraphScene gesteuert. (KG)
// 28.01.06		- modified: setAppData(), sortiert Aufgaben an den Anfang des Projektzeitraums

#include <math.h>
#include <assert.h>

#ifdef WIN32
#include <windows.h>
#endif

// OpenGL Includes
#include <GL/gl.h>
#include <GL/glut.h>

// Haptics Library Includes
#include <HL/hl.h>
#include <HDU/hduMatrix.h>
#include <HDU/hduError.h>
#include <HLU/hlu.h>

// eigene Includes
#include "hapticgraphclasses/HapticDevice.h"
#include "hapticgraphclasses/GraphScene.h"
#include "hapticgraphclasses/HapticCursor.h"
#include "exceptionclasses/HapticsExceptions.h"

// Includes der Businesslogik
#include "businesslogic/AppConfiguration.h"
#include "businesslogic/BusinessTask.h"


// Objekt zur Verwaltung des haptischen Ger�tes
static HapticDevice * pHapticDevice = NULL;
 
// Objekt zur Verwaltung aller Objekte der Szene
static GraphScene * pScene;

// Cursor-Objekt
static HapticCursor cursor;

// Function prototypes.
void glutDisplay(void);
void glutReshape(int width, int height);
void glutIdle(void);    

void exitHandler(void);

void initGL();
void initHL();
void initScene( int viewportWidth, int viewportHeight );

//...................................................................
/// @author Carsten Arnold
/// @brief Initialisiert Konfigurationsdaten Objekt CA
//...................................................................
void setAppData();

//........................
/// @author Carsten Arnold
/// @brief Objekt mit globale Konfigurations Daten CA
//........................
AppConfiguration appData;

/*******************************************************************************
 Initializes GLUT for displaying a simple haptic scene
*******************************************************************************/
int main(int argc, char *argv[])
{
	//...................................................................
	/// @brief
	//...................................................................
    setAppData();

	glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	int winWidth = 800;
	int winHeight = 600;

    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Phantom Graph Demo");

    // Set glut callback functions.
    glutDisplayFunc(glutDisplay);
    glutReshapeFunc(glutReshape);
    glutIdleFunc(glutIdle);
    
    // Provide a cleanup routine for handling application exit.
    atexit(exitHandler);

    initScene(winWidth, winHeight);

    glutMainLoop();

    return 0;
}

/*******************************************************************************
 GLUT callback for redrawing the view 
*******************************************************************************/
void glutDisplay()
{    
	pScene->renderScene(pHapticDevice->isActive());
	cursor.render();
    glutSwapBuffers();
}

/*******************************************************************************
 GLUT callback for reshaping the window. This is the main place where the 
 viewing and workspace transforms get initialized.
*******************************************************************************/
void glutReshape(int width, int height)
{
	pScene->getView()->recalculateView(width, height);

	cursor.scale();
}

/*******************************************************************************
 GLUT callback for idle state. Use this as an opportunity to request a redraw.
*******************************************************************************/
void glutIdle()
{
    glutPostRedisplay();
}

/*******************************************************************************
 Initialize the scene. Handle initializing both OpenGL and HL
*******************************************************************************/
void initScene( int viewportWidth, int viewportHeight )
{
    initGL();
    initHL();
	static UnitConversionInfo uinf(3.6, 2.7, 0.03, 0.1);
	pScene = new GraphScene(uinf);
	pScene->initScene(viewportWidth, viewportHeight, pHapticDevice,
					appData.getProjectDuration(), appData.getProjectLines(),
					appData.getRootTask());
}

/*******************************************************************************
 Setup general OpenGL rendering properties, like lights, depth buffering, etc.
*******************************************************************************/
void initGL()
{
    static const GLfloat light_model_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    static const GLfloat light0_diffuse[] = {0.9f, 0.9f, 0.9f, 0.9f};   
    static const GLfloat light0_direction[] = {0.0f, -0.4f, 1.0f, 0.0f};    
    
    /* Enable depth buffering for hidden surface removal. */
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    
    /* Cull back faces. */
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    
    /* Other misc features. */
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    
    /* Setup lighting model */
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_model_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
    glEnable(GL_LIGHT0);   
}

/*******************************************************************************
 Initialize the HDAPI. This involves initing a device configuration, enabling
 forces, and scheduling a haptic thread callback for servicing the device.
*******************************************************************************/
void initHL()
{
	try
	{
		pHapticDevice = new HapticDevice();
		pHapticDevice->initialize();
	}
	catch (HDInitialisationFailedException & ex)
	{
		printf(ex.what());
		printf("\nStart application without haptic support!");
	}
	catch (...)
	{
		printf("Unknown Exception occured! Exit application!");
		getchar();
		exit(-1);
	}

    // Enable optimization of the viewing parameters when rendering
    // geometry for OpenHaptics
    hlEnable(HL_HAPTIC_CAMERA_VIEW);
}

/*******************************************************************************
 This handler will get called when the application is exiting.
 Deallocates any state and cleans up.
*******************************************************************************/
void exitHandler()
{
	if (pHapticDevice != NULL)
	{
		delete pHapticDevice;
		pHapticDevice = NULL;
	}
}


//...................................................................
/// @brief Initialisiert alle Aufgabe CA
//...................................................................
void setAppData()
{
	appData.initTasks();

	/// @brief Debuginfo zur Ausgabe aller Tasks
	if(appData.getDebugState())
	{
		cout << "DebugInfo: Aufruf aus Main::setAppData()" << endl;
		//cout << "Name der Startaufgabe: " << m_rootTask->getName() << endl << endl;
	}


}
