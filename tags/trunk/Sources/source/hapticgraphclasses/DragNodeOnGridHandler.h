//*******************************************************************************
/// @file	DragNodeOnGridHandler.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		23.01.2006
/// @date	Letzte Änderung	23.01.2006
//*******************************************************************************

// Änderungen:


#ifndef _DRAGNODEONGRIDHANDLER_H_
#define _DRAGNODEONGRIDHANDLER_H_

#include "HapticAction.h"
#include "Node.h"
#include "Grid.h"
#include "Utilities.h"

// ...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Eventhandlerklasse die es ermöglicht, haptische Nodes mit dem 
///			Phantom in x-Richtung auf einem Grid zu bewegen.
///			
///			Der Eventhandler reagiert auf die folgende Events:
///			- der vordere Phantom-Button wird gedrückt, wenn ein Objekt mit dem 
///			  Phantom berührt wird
///			- das Phantom wird mit gedrücktem Button bewegt
///			- der vordere Phantom-Button wird losgelassen
///			Wirkung: Der Node folgt den Bewegungen des Phantom in x-Richtung. Die
///			Bewegung des Phantom in y- und z-Richtung wird von dem Node ignoriert.
///			Beim Loslassen des Buttons rastet der Node an dem nächstgelegenen
///			Gitterpunkt ein.
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

		// .......................................................................
		/// @brief	Position des Proxy beim letzten Aufruf des Draghandlers. Dient
		///			zur Berechnung des Vektors um den das Objekt verschoben werden soll.
		// .......................................................................
		hduVector3Dd m_LastProxyPos;

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Started das Draggen des Objekts.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_1BUTTONDOWN.
		///	@param	shapeID	Die ShapeID des Objekts, das bewegt werden soll.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt 
		///					werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	pHandlerObject	Pointer auf das DragNodeOnGridHandler-Objekt, 
		///					das	das Event verarbeiten soll.
		//.......................................................................
		static void HLCALLBACK OnButtonDown(HLenum event, 
											HLuint shapeID, 
											HLenum thread, 
											HLcache * cache, 
											void * pHandlerObject );
		
		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Beendet das Draggen des Objekts.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_1BUTTONUP.
		///	@param	shapeID	Hier soll HL_OBJECT_ANY angegeben werden.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	pHandlerObject	Pointer auf das DragNodeOnGridHandler-Objekt, 
		///					das	das Event verarbeiten soll.
		//.......................................................................
		static void HLCALLBACK OnButtonUp(	HLenum event, 
											HLuint shapeID, 
											HLenum thread, 
											HLcache * cache, 
											void * pHandlerObject);

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Steuert das Draggen des Objekts.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_MOTION
		///	@param	shapeID	Hier soll HL_OBJECT_ANY angegeben werden.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	pHandlerObject	Pointer auf das DragNodeOnGridHandler-Objekt, 
		///					das	das Event verarbeiten soll.
		//.......................................................................
		static void HLCALLBACK OnDrag(	HLenum event, 
										HLuint shapeID, 
										HLenum thread, 
										HLcache * cache, 
										void * pHandlerObject );
		
	public:

		//.......................................................................
		/// @brief	Konstruktor, initialisiert das Eventhandler-Objekt mit dem 
		///			zugehörigen Node und dem Grid, auf dem dieser bewegt werden soll.
		/// @param	pNode	Pointer auf den Node für den der Eventhandler 
		///					zuständig sein soll.
		/// @param	pGrid	Pointer auf das Grid, auf dem der Node bewegt werden soll.
		//.......................................................................
		DragNodeOnGridHandler( Node* pNode, Grid * pGrid );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~DragNodeOnGridHandler();

		//.......................................................................
		/// @brief	Nimmt die Proxy-Position beim Starten des Drag-Vorgangs auf.
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das 
		///					Event feuert.
		//.......................................................................
		void initAction( HLcache * pCache );
		
		//.......................................................................
		/// @brief	Veranlasst das haptische Objekt, sich mit dem Proxy zu bewegen.
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das 
		///					Event feuert.
		//.......................................................................
		void handleDrag( HLcache * pCache );

		//.......................................................................
		/// @brief	Sorgt dafür, dass der Node am Ende des Dragvorgangs auf den 
		///			nächstgelegenen gültigen Gitterpunkt des Grid gesetzt wird.
		//.......................................................................
		void finishAction();
		
		//=======================================================================
		// Von IHapticAction geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Registriert die Aktion für eine Shape bei HLAPI.
		/// @param	shapeID	ID der Shape, für die die Aktion registriert werden soll.
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID );
		
		//.......................................................................
		/// @brief	Meldet die Aktion für eine Shape bei HLAPI ab.
		/// @param	shapeID	ID der Shape, für die die Aktion registriert wurde.
		//.......................................................................
		virtual void registerAction( HLuint shapeID );

		//=======================================================================
		
};

#endif // _DRAGNODEONGRIDHANDLER_H_