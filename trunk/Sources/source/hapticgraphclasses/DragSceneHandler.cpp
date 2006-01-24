//*******************************************************************************
/// @file	DragSceneHandler.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		19.01.2006
/// @date	Letzte Änderung	19.01.2006
//*******************************************************************************

// Änderungen:


#include "DragSceneHandler.h"

//*******************************************************************************
void HLCALLBACK DragSceneHandler::OnButtonDown(	HLenum event,
												HLuint shapeID,
												HLenum thread,
												HLcache *cache,
												void *pHandlerObject)
{
	hlAddEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragSceneHandler::OnDrag, pHandlerObject);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragSceneHandler::OnButtonUp, NULL);

	DragSceneHandler * pHandler = static_cast<DragSceneHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->initAction(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
void HLCALLBACK DragSceneHandler::OnButtonUp(	HLenum event,
												HLuint shapeID,
												HLenum thread,
												HLcache *cache,
												void *userdata)
{
	hlRemoveEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragSceneHandler::OnDrag);
	hlRemoveEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragSceneHandler::OnButtonUp);
}
//*******************************************************************************

//*******************************************************************************		
void HLCALLBACK DragSceneHandler::OnDrag(	HLenum event,
											HLuint shapeID,
											HLenum thread,
											HLcache *cache,
											void *pHandlerObject)
{
	DragSceneHandler * pHandler = static_cast<DragSceneHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->handleDrag(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
DragSceneHandler::DragSceneHandler(GraphScene * pScene)
{
	m_pDragScene = pScene;
	m_LastProxyPos.set(0.0, 0.0, 0.0);
}
//*******************************************************************************

//*******************************************************************************
void DragSceneHandler::initAction(HLcache * pCache)
{
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, m_LastProxyPos);
}
//*******************************************************************************

//*******************************************************************************
void DragSceneHandler::handleDrag(HLcache * pCache)
{
	hduVector3Dd proxyPos;
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, proxyPos);
	hduVector3Dd deltaProxy = proxyPos - m_LastProxyPos;
	m_pDragScene->viewFrom(-deltaProxy[0], -deltaProxy[1], 2.7);
	m_LastProxyPos = proxyPos;
}
//*******************************************************************************
	
//*******************************************************************************
void DragSceneHandler::registerAction( HLuint shapeID )
{
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragSceneHandler::OnButtonDown, this);
}
//*******************************************************************************

//*******************************************************************************
void DragSceneHandler::unregisterAction( HLuint shapeID )
{
	hlRemoveEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragSceneHandler::OnButtonDown);
}
//*******************************************************************************
