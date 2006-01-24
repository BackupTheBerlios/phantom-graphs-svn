//*******************************************************************************
/// @file	DragNodeOnGridHandler.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		23.01.2006
/// @date	Letzte �nderung	23.01.2006
//*******************************************************************************

// �nderungen:


#ifndef _DRAGNODEONGRIDHANDLER_H_
#define _DRAGNODEONGRIDHANDLER_H_

#include "HapticAction.h"
#include "Node.h"
#include "Grid.h"
#include "Utilities.h"

// ...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Eventhandlerklasse die es erm�glicht, haptische Nodes mit dem 
///			Phantom in x-Richtung auf einem Grid zu bewegen.
///			
///			Der Eventhandler reagiert auf die folgende Events:
///			- der vordere Phantom-Button wird gedr�ckt, wenn ein Objekt mit dem 
///			  Phantom ber�hrt wird
///			- das Phantom wird mit gedr�cktem Button bewegt
///			- der vordere Phantom-Button wird losgelassen
///			Wirkung: Der Node folgt den Bewegungen des Phantom in x-Richtung. Die
///			Bewegung des Phantom in y- und z-Richtung wird von dem Node ignoriert.
/// @todo	Einrasten des Node an den Gitterpunkten implementieren.
//...............................................................................
class DragNodeOnGridHandler : public IHapticAction
{
	protected:

		//.......................................................................
		/// @brief	Der Node, dem der Eventhandler zugeordnet ist.
		//.......................................................................
		Node * m_pDragObj;

		//.......................................................................
		/// @brief	Das Grid, auf dem der Node verschoben werden soll.
		//.......................................................................
		Grid * m_pGrid;

		//.......................................................................
		/// @brief	Position des Objektes vor dem Dragvorgang.
		//.......................................................................
		Position m_OriginalObjPosition;

		// .......................................................................
		/// Position des Proxy beim letzten Aufruf des Draghandlers
		/// Dient zur Berechnung des Vektors um den das Objekt verschoben werden soll
		hduVector3Dd m_LastProxyPos;

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Started das Draggen des Objekts
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_1BUTTONDOWN
		///	@param	shapeID	Die ShapeID des Objekts, das bewegt werden soll
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt 
		///					werden soll, in diesem Fall HL_CLIENT_THREAD
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		/// @param	pHandlerObject	Pointer auf das DragObjectHandler-Objekt, das
		///					das Event verarbeiten soll
		//.......................................................................
		static void HLCALLBACK OnButtonDown(HLenum event, 
											HLuint shapeID, 
											HLenum thread, 
											HLcache * cache, 
											void * pHandlerObject );
		
		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Beendet das Draggen des Objekts
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_1BUTTONUP
		///	@param	shapeID	hier soll HL_OBJECT_ANY angegeben werden
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					 werden soll, in diesem Fall HL_CLIENT_THREAD
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		/// @param	pHandlerObject	Pointer auf das DragObjectHandler-Objekt, das
		///					das Event verarbeiten soll
		//.......................................................................
		static void HLCALLBACK OnButtonUp(	HLenum event, 
											HLuint shapeID, 
											HLenum thread, 
											HLcache * cache, 
											void * pHandlerObject);

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Steuert das Draggen des Objekts
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_MOTION
		///	@param	shapeID	hier soll HL_OBJECT_ANY angegeben werden
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					werden soll, in diesem Fall HL_CLIENT_THREAD
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		/// @param	pHandlerObject	Pointer auf das DragObjectHandler-Objekt, das
		///					 das Event verarbeiten soll
		//.......................................................................
		static void HLCALLBACK OnDrag(	HLenum event, 
										HLuint shapeID, 
										HLenum thread, 
										HLcache * cache, 
										void * pHandlerObject );
		
	public:

		//.......................................................................
		/// @brief	Konstruktor, initialisiert das Eventhandler-Objekt mit dem 
		///			zugeh�rigen haptischen Objekt.
		/// @param	pObj	Pointer auf das haptische Objekt f�r das der 
		///					Eventhandler zust�ndig sein soll
		//.......................................................................
		DragNodeOnGridHandler( Node* pNode, Grid * pGrid );

		virtual ~DragNodeOnGridHandler();

		//.......................................................................
		/// @brief	Nimmt die Proxy-Position beim Starten des Drag-Vorgangs auf
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		//.......................................................................
		void initAction( HLcache * pCache );
		
		//.......................................................................
		/// @brief	Veranlasst das haptische Objekt, sich mit dem Proxy zu bewegen
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		//.......................................................................
		void handleDrag( HLcache * pCache );

		void finishAction();
		
		//=======================================================================
		// Von IHapticAction geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Registriert die Aktion f�r eine Shape bei HLAPI
		/// @param	shapeID	ID der Shape, f�r die die Aktion registriert werden soll
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID );
		
		//.......................................................................
		/// @brief	Meldet die Aktion f�r eine Shape bei HLAPI ab
		/// @param	shapeID	ID der Shape, f�r die die Aktion registriert wurde
		//.......................................................................
		virtual void registerAction( HLuint shapeID );

		//=======================================================================
		
};

#endif // _DRAGNODEONGRIDHANDLER_H_