//*******************************************************************************
/// @file	GraphScene.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	02.01.2006
//*******************************************************************************

// Änderungen:
// 30.12.05		- Alle Methoden bis auf initScene() implementiert
// 02.01.06		- Anstoß für Event-Callbacks hinzugefügt


// Haptics Library includes
#include <HL/hl.h>	

// OpenGL includes
#include <GL/gl.h>
#include <GL/glu.h>

#include "GraphScene.h"
#include "Node.h"
#include "DragObjectHandler.h"
#include "DragNodeOnGridHandler.h"
#include "DragSceneHandler.h"
#include "Grid.h"


//*******************************************************************************
GraphScene::GraphScene()
{
	// keine Objekte in der Scene
	m_SceneElements.clear();
}
//*******************************************************************************

//*******************************************************************************
GraphScene::~GraphScene()
{
	// alle Objekte der Scene freigeben
	vector<HapticObject*>::iterator itObj;
	for (itObj = m_SceneElements.begin(); itObj != m_SceneElements.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			delete *itObj;
			*itObj = NULL;
		}
	}
	m_SceneElements.clear();

//hlBeginFrame();
//eff->stopEffect();
//eff2.stopEffect();
//hlEndFrame();

}
//*******************************************************************************

//*******************************************************************************
void GraphScene::addObject( HapticObject * obj )
{
	if (obj != NULL)
	{
		m_SceneElements.push_back(obj);
	}
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::initScene()
{
	// Hintergrundfarbe festlegen
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Grid erzeugen
	Grid * tmpGrid = new Grid(3, 2);
	tmpGrid->translate(0.2, 0.2, 0.0);
	DragSceneHandler * pdragsc = new DragSceneHandler(this);
	tmpGrid->addHapticAction(pdragsc);
//	tmpGrid->setHapticConstraint(new HapticConstraint(1.2f));
	addObject(tmpGrid);

	// Dummy-Implementierung
	HapticObject * tmpObj = new Node(NULL);
	DragObjectHandler * drag = new DragObjectHandler(tmpObj);
	tmpObj->addHapticAction(drag);
	tmpObj->translate(0.0, 0.1, 0.0);
	tmpObj->setHapticConstraint(new HapticConstraint(4.0f));
	addObject(tmpObj);

	bool test = tmpGrid->isGridPoint(tmpObj->getPosition());

	Node * tmpNode = new Node(NULL);
	DragNodeOnGridHandler * dnh = new DragNodeOnGridHandler(tmpNode, tmpGrid);
	tmpNode->addHapticAction(dnh);
	tmpNode->translate(0.13, 0.2, 0.0);
	addObject(tmpNode);

	Position p = tmpGrid->nearestGridPoint(tmpNode->getPosition());

	Node * tmpN = new Node(NULL);
	tmpN->addHapticAction(new DragSceneHandler(this));
	tmpN->translate(-0.5, 0.0, 0.0);
	addObject(tmpN);

//eff = new FrictionForceEffect(0.5, 0.4);
//double dir[3] = {-1.0, 0.0, 0.0};
//eff = new ConstantForceEffect(dir, 0.5);
//eff = new ViscousForceEffect(2.0, 2.0);
//eff.setGain(0.4);
//eff.setMagnitude(0.5);
//hlBeginFrame();
//eff->startEffect();
//hlEndFrame();
//eff2.startEffect();
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::renderScene( bool bHapticsEnabled )
{
	// Haptik rendern, wenn die Anwendung mit haptischer Unterstützung läuft
	renderSceneHaptics(bHapticsEnabled);

	// Graphik rendern
	renderSceneGraphics();
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::renderSceneGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	// alle Objekte der Scene durchlaufen und sie zum Rendern ihrer graphischen
	// Beschaffenheit auffordern
	vector<HapticObject*>::iterator itObj;
	for (itObj = m_SceneElements.begin(); itObj != m_SceneElements.end(); itObj++)
	{
		if (*itObj != NULL)
		{
			(*itObj)->renderGraphics();
		}
	}
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::renderSceneHaptics( bool bHapticsEnabled )
{
	// Haptik rendern, wenn die Anwendung mit haptischer Unterstützung läuft
	if (bHapticsEnabled)
	{	
		// Haptic Frame starten - haptische Objekte können nur zwischen hlBeginFrame()
		// und hlEndFrame() gerendert werden
		hlBeginFrame();

		// alle Objekte der Scene durchlaufen und sie zum Rendern ihrer haptischen
		// Beschaffenheit auffordern
		vector<HapticObject*>::iterator itObj;
		for (itObj = m_SceneElements.begin(); itObj != m_SceneElements.end(); itObj++)
		{
			if (*itObj != NULL)
			{
				(*itObj)->renderHaptics();
			}
		}

		// Eventcallbacks des Client Thread anstoßen
		hlCheckEvents();

		// Haptic Frame beenden
		hlEndFrame();
	}
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::viewFrom(float x, float y, double nearDistance)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();            
    gluLookAt(x, y, nearDistance + 1.0,
              x, y, 0,
              0, 1, 0);	

}
//*******************************************************************************

//*******************************************************************************
float GraphScene::getGraphPlaneZ()
{
	// Dummy
	return -0.1f;
}
//*******************************************************************************