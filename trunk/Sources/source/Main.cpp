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
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 26.12.05		- Die vorhandenen Shapes und zugehörigen Aufrufe des 
//				  Constraint-Demo-Programms entfernt
//				- Initialisierung des Haptischen Gerätes wird jetzt von der Klasse
//				  HapticDevice durchgeführt
// 27.12.05		- nicht benötigten Code entfernt
//				- Cursor wird jetzt von Cursor-Objekt gezeichnet

#include <math.h>
#include <assert.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>

#include <HL/hl.h>
#include <HDU/hduMatrix.h>
#include <HDU/hduError.h>

#include <HLU/hlu.h>

// eigene Includes
#include "hapticgraphclasses/HapticDevice.h"
#include "hapticgraphclasses/HapticCursor.h"
#include "exceptionclasses/HapticsExceptions.h"

// Objekt zur Verwaltung des haptischen Gerätes
static HapticDevice * pHapticDevice = NULL;

// Cursor-Objekt
static HapticCursor cursor;

/* Function prototypes. */
void glutDisplay(void);
void glutReshape(int width, int height);
void glutIdle(void);    

void exitHandler(void);

void initGL();
void initHL();
void initScene();
void drawSceneHaptics();
void drawSceneGraphics();
void updateWorkspace();

/*******************************************************************************
 Initializes GLUT for displaying a simple haptic scene
*******************************************************************************/
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Constraints Example");

    /* Set glut callback functions. */
    glutDisplayFunc(glutDisplay);
    glutReshapeFunc(glutReshape);
    glutIdleFunc(glutIdle);
    
    /* Provide a cleanup routine for handling application exit. */
    atexit(exitHandler);

    initScene();

    glutMainLoop();

    return 0;
}

/*******************************************************************************
 GLUT callback for redrawing the view 
*******************************************************************************/
void glutDisplay()
{    
    drawSceneHaptics();
    drawSceneGraphics();
    glutSwapBuffers();
}

/*******************************************************************************
 GLUT callback for reshaping the window. This is the main place where the 
 viewing and workspace transforms get initialized.
*******************************************************************************/
void glutReshape(int width, int height)
{
    static const double kPI = 3.1415926535897932384626433832795;
    static const double kFovY = 40;

    double nearDist, farDist, aspect;

    glViewport(0, 0, width, height);

    /* Compute the viewing parameters based on a fixed fov and viewing
     * a canonical box centered at the origin */

    nearDist = 1.0 / tan((kFovY / 2.0) * kPI / 180.0);
    farDist = nearDist + 2.0;
    aspect = (double) width / height;
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(kFovY, aspect, nearDist, farDist);

    /* Place the camera down the Z axis looking at the origin */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();            
    gluLookAt(0, 0, nearDist + 1.0,
              0, 0, 0,
              0, 1, 0);
    
    updateWorkspace();
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
void initScene()
{
    initGL();
    initHL();
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

/*******************************************************************************
 Use the current OpenGL viewing transforms to initialize a transform for the
 haptic device workspace so that it's properly mapped to world coordinates.
*******************************************************************************/
void updateWorkspace()
{
/*    GLdouble modelview[16];
    GLdouble projection[16];
    GLint viewport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
*/

	pHapticDevice->updateWorkspace();

    /* compute cursor scale */
/*    gCursorScale = hluScreenToModelScale(modelview, projection, viewport);
    gCursorScale *= CURSOR_SIZE_PIXELS;
*/
	cursor.scale();

}

void drawString(const char* string)
{
    for (;*string != '\0';++string)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *string);
    }
}

void drawPlane()
{
    static GLuint displayList = 0;

    if (displayList)
    {
        glCallList(displayList);
    }
    else
    {
        displayList = glGenLists(1);
        glNewList(displayList, GL_COMPILE_AND_EXECUTE);
        glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT);
        const GLfloat mat[] = {0, 0, 1};
        glEnable(GL_LIGHTING);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat);
        glPolygonOffset(1,1);
        glEnable(GL_POLYGON_OFFSET_FILL);
        glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(-0.1, -0.15, 0);
        glVertex3f(1.4, -0.15, 0);
        glVertex3f(1.4, 0.35, 0);
        glVertex3f(-0.1, 0.35, 0);
        glEnd();
        glDisable(GL_POLYGON_OFFSET_FILL);
        glPopAttrib();
        glEndList();
    }
}

void drawHapticsString()
{
    static GLuint displayList = 0;

    if (displayList)
    {
        glCallList(displayList);
    }
    else
    {
        displayList = glGenLists(1);
        glNewList(displayList, GL_COMPILE_AND_EXECUTE);
        glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT);
        glDisable(GL_LIGHTING);
        glColor3f(1.0,0,0);
        glLineWidth(4.0);
        glPushMatrix();
        glScalef(0.003,0.003,0.003);
        drawString("Haptics");
        glPopMatrix();
        glPopAttrib();
        glEndList();
    }
}

void drawLine()
{
    static GLuint displayList = 0;

    if (displayList)
    {
        glCallList(displayList);
    }
    else
    {
        displayList = glGenLists(1);
        glNewList(displayList, GL_COMPILE_AND_EXECUTE);
        glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT);
        glDisable(GL_LIGHTING);
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.8, -0.8, -0.8);
        glEnd();
        glPointSize(4);
        glBegin(GL_POINTS);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.4, -0.4, -0.4);
        glVertex3f(-0.8, -0.8, -0.8);
        glEnd();
        glPopAttrib();
        glEndList();
    }
}


void drawSurface()
{
    static GLuint displayList = 0;

    if (displayList)
    {
        glCallList(displayList);
    }
    else
    {
        displayList = glGenLists(1);
        glNewList(displayList, GL_COMPILE_AND_EXECUTE);
        glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT);

        glEnable(GL_LIGHTING);
        glEnable(GL_AUTO_NORMAL);
        glEnable(GL_NORMALIZE);
        GLfloat diffuse[] = { 0.3, 0.3, 0.5, 1 };
        GLfloat specular[] = { 0.7, 0.7, 0.7, 1 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 40.0);

        const int nPointsU = 16;
        const int nPointsV = 4;
        const int order = 4;
        const int nKnotsU = nPointsU + order;
        const int nKnotsV = nPointsV + order;

        // knots
        GLfloat uknots[nKnotsU];
        GLfloat vknots[nKnotsV];

        // allocate uniform knots btween 0 and 1 in u and v with triple knots
        // at start and end of curve
        int i, j;
        for (i = 0; i < 3; ++i)
        {
            uknots[i] = vknots[i] = 0;
            uknots[nKnotsU - i- 1] = vknots[nKnotsV - i- 1] = 1;
        }

        for (i = 3; i < nKnotsU - 3; ++i)
        {
            uknots[i] = float(i-3)/float(nKnotsU - 7);
        }

        for (i = 3; i < nKnotsV - 3; ++i)
        {
            vknots[i] = float(i-3)/float(nKnotsV - 7);
        }


        const float uwidth = 1.2;
        const float vwidth = 0.8;
        const float amplitude = 0.3;

        // control points - uniform grid with z coordinate
        // varying based on sine wave
        typedef GLfloat ControlPoint[3];
        ControlPoint controlPoints[nPointsU][nPointsV];

        for (i = 0; i < nPointsU; ++i)
        {
            for (j = 0; j < nPointsV; ++j)
            {
                controlPoints[i][j][0] = uwidth * i/float(nPointsU);
                controlPoints[i][j][1] = vwidth * j/float(nPointsV);
                controlPoints[i][j][2] = amplitude * sin(2 * 3.14159 * i/nPointsU);
            }
        }

        GLUnurbsObj *surf = gluNewNurbsRenderer();
            gluBeginSurface(surf);
        gluNurbsSurface(surf,nKnotsU, uknots, nKnotsV, vknots,
                        3 * nPointsV, 3, &controlPoints[0][0][0],
                         order, order, GL_MAP2_VERTEX_3);
        gluEndSurface(surf);
        glPopAttrib();
        glEndList();
    }
}

/*******************************************************************************
 The main routine for displaying the scene. Get the latest snapshot of state
 from the haptic thread and use it for displaying a 3D cursor.
*******************************************************************************/
void drawSceneGraphics()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        
    
    // draw 3D cursor at haptic device position
    cursor.render();
}

/*******************************************************************************
 The main routine for rendering scene haptics. 
 Renders the sphere haptically.
*******************************************************************************/
void drawSceneHaptics()
{    
	if (!(pHapticDevice->isActive()))
	{
		return;
	}

    // start haptic frame - must do this before rendering any haptic shapes
    hlBeginFrame();


    // end the haptic frame
    hlEndFrame();

}
