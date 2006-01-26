//*******************************************************************************
/// @file	DragNodeOnGridHandle.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		23.01.2006
/// @date	Letzte Änderung	26.01.2006
//*******************************************************************************

// Änderungen:
// 26.01.06		- finishAction() sorgt dafür, dass der Node nach dem Verschieben
//				  immer auf einem gültigen Gitterpunkt abgesetzt wird.


#include "DragNodeOnGridHandler.h"

//*******************************************************************************
void HLCALLBACK DragNodeOnGridHandler::OnButtonDown(HLenum event, 
													HLuint shapeID, 
													HLenum thread, 
													HLcache * cache, 
													void * pHandlerObject )
{
	hlAddEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnDrag, pHandlerObject);
	hlAddEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnButtonUp, pHandlerObject);

	DragNodeOnGridHandler * pHandler = static_cast<DragNodeOnGridHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->initAction(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
void HLCALLBACK DragNodeOnGridHandler::OnButtonUp(HLenum event, 
												  HLuint shapeID, 
												  HLenum thread, 
												  HLcache * cache, 
												  void * pHandlerObject )
{
	DragNodeOnGridHandler * pHandler = static_cast<DragNodeOnGridHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->finishAction();
	}

	hlRemoveEventCallback(HL_EVENT_MOTION, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnDrag);
	hlRemoveEventCallback(HL_EVENT_1BUTTONUP, HL_OBJECT_ANY, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnButtonUp);
}
//*******************************************************************************

//*******************************************************************************
void HLCALLBACK DragNodeOnGridHandler::OnDrag(HLenum event, 
											  HLuint shapeID, 
											  HLenum thread, 
											  HLcache * cache, 
											  void * pHandlerObject )
{
	DragNodeOnGridHandler * pHandler = static_cast<DragNodeOnGridHandler*>(pHandlerObject);
	if (pHandler != NULL)
	{
		pHandler->handleDrag(cache);
	}
}
//*******************************************************************************

//*******************************************************************************
DragNodeOnGridHandler::DragNodeOnGridHandler( Node* pNode, Grid * pGrid )
{
	m_pDragObj = pNode;
	m_pGrid = pGrid;
	m_LastProxyPos.set(0.0, 0.0, 0.0);
}
//*******************************************************************************

//*******************************************************************************
DragNodeOnGridHandler::~DragNodeOnGridHandler()
{
}
//*******************************************************************************

//*******************************************************************************
void DragNodeOnGridHandler::initAction( HLcache * pCache )
{
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, m_LastProxyPos);
	m_OriginalObjPosition = m_pDragObj->getPosition();
}
//*******************************************************************************

//*******************************************************************************
void DragNodeOnGridHandler::handleDrag( HLcache * pCache )
{
	hduVector3Dd proxyPos;
	hlCacheGetDoublev(pCache, HL_PROXY_POSITION, proxyPos);
	hduVector3Dd deltaProxy = proxyPos - m_LastProxyPos;
	m_pDragObj->translate(deltaProxy[0], 0.0, 0.0);
	m_LastProxyPos = proxyPos;
}
//*******************************************************************************

//*******************************************************************************
void DragNodeOnGridHandler::finishAction()
{
	Position newpos = m_pGrid->nearestGridPoint(m_pDragObj->getPosition());
	m_pDragObj->setPosition(newpos.x, newpos.y, newpos.z);
}
//*******************************************************************************

//*******************************************************************************
void DragNodeOnGridHandler::registerAction( HLuint shapeID )
{
	hlAddEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnButtonDown, this);
}
//*******************************************************************************

//*******************************************************************************
void DragNodeOnGridHandler::unregisterAction( HLuint shapeID )
{
	hlRemoveEventCallback(HL_EVENT_1BUTTONDOWN, shapeID, HL_CLIENT_THREAD, DragNodeOnGridHandler::OnButtonDown);
}
//*******************************************************************************

