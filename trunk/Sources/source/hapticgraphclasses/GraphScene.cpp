//*******************************************************************************
/// @file	GraphScene.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	30.12.2005
//*******************************************************************************

// �nderungen:
// 30.12.05		- Alle Methoden bis auf initScene() implementiert


// Haptics Library includes
#include <HL/hl.h>	

// OpenGL includes
#include <GL/gl.h>

#include "GraphScene.h"
#include "HapticObject.h"

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
}
//*******************************************************************************

//*******************************************************************************
void GraphScene::renderScene( bool bHapticsEnabled )
{
	// Haptik rendern, wenn die Anwendung mit haptischer Unterst�tzung l�uft
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
	// Haptik rendern, wenn die Anwendung mit haptischer Unterst�tzung l�uft
	if (bHapticsEnabled)
	{	
		// Haptic Frame starten - haptische Objekte k�nnen nur zwischen hlBeginFrame()
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

		// Haptic Frame beenden
		hlEndFrame();
	}
}
//*******************************************************************************