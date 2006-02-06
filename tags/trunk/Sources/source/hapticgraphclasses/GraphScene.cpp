//*******************************************************************************
/// @file	GraphScene.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	04.02.2006
//*******************************************************************************

// Änderungen:
// 30.12.05		- Alle Methoden bis auf initScene() implementiert
// 02.01.06		- Anstoß für Event-Callbacks hinzugefügt.
// 26.01.06		- initScene() hat neue Parameter bekommen.
//				- neue Methode getView() hinzugefügt und implementiert.
// 28.01.06		- createObjects() implementiert.
// 04.02.06		- Code aufgeräumt.



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
#include "Edge.h"


//*******************************************************************************
GraphScene::GraphScene( UnitConversionInfo & unitInfo )
: m_rUnitInfo(unitInfo)
{
	// keine Objekte in der Scene
	m_SceneElements.clear();

	m_pCamera = NULL;

	m_pDragSceneHandler = NULL;

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

	// Kamera freigeben
	if (m_pCamera != NULL)
	{
		delete m_pCamera;
		m_pCamera = NULL;
	}

	// DragSceneHandler freigeben
	if (m_pDragSceneHandler != NULL)
	{
		m_pDragSceneHandler->unregisterAction(HL_OBJECT_ANY);
		delete m_pDragSceneHandler;
		m_pDragSceneHandler = NULL;
	}
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
void GraphScene::initScene( int viewportWidth, int viewportHeight, HapticDevice * pHd,
							int gridColumns, int gridRows,
							IBusinessAdapter * rootNode)
{
	// Kamera initialisieren
	m_pCamera = new Camera(40.0, viewportWidth, viewportHeight, pHd);
	m_pCamera->translateView(1.8, 0.0);

	// Hintergrundfarbe festlegen
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// DragSceneHandler initialisieren
	m_pDragSceneHandler = new DragSceneHandler(this);
	m_pDragSceneHandler->registerAction(HL_OBJECT_ANY);

	// Darstellungsobjekte zum Graphen erzeugen:
	// Grid der entsprechenden Größe mit linker unterer Ecke bei [0.0, 0.0, 0.0] erzeugen
	Grid * pGrid = new Grid(m_rUnitInfo, gridColumns, gridRows);
	pGrid->setPosition(0.0, 0.0, 0.0);
	HapticConstraint * pGridConstraint = new HapticConstraint(1.0f);
	pGridConstraint->disable();
	pGrid->setHapticConstraint(pGridConstraint);
	pGrid->addHapticAction(new DragSceneHandler(this));
	addObject(pGrid);

	// vom rootNode ausgehend Haptische Objekte für Knoten und Kanten erzeugen
	// der rootNode selbst wird nicht dargestellt
	list<IBusinessAdapter*>& lsFollowingNodes = rootNode->getNextTasks();
	list<IBusinessAdapter*>::iterator iterNext;
	for (iterNext = lsFollowingNodes.begin(); iterNext != lsFollowingNodes.end(); iterNext++)
	{
		createObjects(*iterNext, pGrid);
	}
}
//*******************************************************************************

//*******************************************************************************
Node * GraphScene::createObjects(IBusinessAdapter * businessObj, Grid * pGrid )
{
	Node * pNode = new Node(businessObj, m_rUnitInfo);
	addObject(pNode);
	pNode->addHapticAction(new DragNodeOnGridHandler(pNode, pGrid));
	pNode->setHapticConstraint(new HapticConstraint(2.0));

	// rekursiv die Nachfolger erzeugen und mit Kanten verbinden
	Node * pNextNode = NULL;
	Edge * pEdge = NULL;
	list<IBusinessAdapter*>& lsFollowingNodes = businessObj->getNextTasks();
	list<IBusinessAdapter*>::iterator iterNext;
	for (iterNext = lsFollowingNodes.begin(); iterNext != lsFollowingNodes.end(); iterNext++)
	{
		pNextNode = createObjects(*iterNext, pGrid);
		pEdge = new Edge();
		pNode->addOutgoingEdge(pEdge);
		pNextNode->addIncomingEdge(pEdge);
		addObject(pEdge);
	}

	return pNode;
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
float GraphScene::getGraphPlaneZ()
{
	// Dummy
	return -0.1f;
}
//*******************************************************************************

//*******************************************************************************
Camera * GraphScene::getView()
{
	return m_pCamera;
}
//*******************************************************************************
