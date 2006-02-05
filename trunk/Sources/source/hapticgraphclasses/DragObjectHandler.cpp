//*******************************************************************************
/// @file	DragObjectHandler.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		15.12.2005
/// @date	Letzte Änderung	15.12.2005
//*******************************************************************************

// Änderungen:


#include "DragObjectHandler.h"

//*******************************************************************************
void HLCALLBACK DragObjectHandler::OnButtonDown(HLenum event,
												HLuint shapeID,
												HLenum thread,
												HLcache *cache,
												void *pHandlerObject)
{
	hlAddEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragObjectHandler::OnDrag, pHandlerObject);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragObjectHandler::OnButtonUp, NULL);

	DragObjectHandler * pHandler = static_cast<DragObjectHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->initAction(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
void HLCALLBACK DragObjectHandler::OnButtonUp(	HLenum event,
												HLuint shapeID,
												HLenum thread,
												HLcache *cache,
												void *unused)
{
	hlRemoveEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragObjectHandler::OnDrag);
	hlRemoveEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragObjectHandler::OnButtonUp);
}
//*******************************************************************************

//*******************************************************************************		
void HLCALLBACK DragObjectHandler::OnDrag(	HLenum event,
											HLuint shapeID,
											HLenum thread,
											HLcache *cache,
											void *pHandlerObject)
{
	DragObjectHandler * pHandler = static_cast<DragObjectHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->handleDrag(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
DragObjectHandler::DragObjectHandler(HapticObject * pObj)
{
	m_pDragObj = pObj;
	m_LastProxyPos.set(0.0, 0.0, 0.0);
}
//*******************************************************************************

//*******************************************************************************
void DragObjectHandler::initAction(HLcache * pCache)
{
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, m_LastProxyPos);
}
//*******************************************************************************

//*******************************************************************************
void DragObjectHandler::handleDrag(HLcache * pCache)
{
	hduVector3Dd proxyPos;
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, proxyPos);
	hduVector3Dd deltaProxy = proxyPos - m_LastProxyPos;
	m_pDragObj->translate(deltaProxy[0], deltaProxy[1], deltaProxy[2]);
	m_LastProxyPos = proxyPos;
}
//*******************************************************************************
	
//*******************************************************************************
void DragObjectHandler::registerAction( HLuint shapeID )
{
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragObjectHandler::OnButtonDown, this);
}
//*******************************************************************************

//*******************************************************************************
void DragObjectHandler::unregisterAction( HLuint shapeID )
{
	hlRemoveEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragObjectHandler::OnButtonDown);
}
//*******************************************************************************
