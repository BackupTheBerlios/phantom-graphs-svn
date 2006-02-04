//*******************************************************************************
/// @file	DragSceneHandler.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		19.01.2006
/// @date	Letzte Änderung	04.02.2006
//*******************************************************************************

// Änderungen:
// 04.02.06		- Doku korrigiert.


#ifndef _DRAGSCENEHANDLER_H_
#define _DRAGSCENEHANDLER_H_

// Haptic Library includes
#include <HL/hl.h>
#include <HDU/hduMatrix.h>

// eigene includes
#include "HapticAction.h"
#include "GraphScene.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Eventhandlerklasse die es ermöglicht, die gesamte Szene (Kameraführung)
///			mit dem Phantom zu bewegen.
///			
///			Der Eventhandler reagiert auf die folgende Events:
///			- der hintere Phantom-Button wird gedrückt, wenn das registrierte Objekt
///			  mit dem Phantom berührt wird
///			- das Phantom wird mit gedrücktem Button bewegt
///			- der vordere Phantom-Button wird losgelassen
///			Wirkung: Solange der Button gedrückt gehalten wird, folgt die Szene
///			der Bewegung des Phantom (nur die x-Richtung wird berücksichtigt)
///			(Kameraführung in entgegengesetzter x-Richtung).
//...............................................................................
class DragSceneHandler : public IHapticAction
{
	protected:

		//.......................................................................
		/// @brief	Die Szene, die der Eventhandler bewegen soll. 
		///			Wird NICHT vom EventHandler freigegeben!
		//.......................................................................
		GraphScene * m_pDragScene;

		//.......................................................................
		/// @brief	Position des Proxy beim letzten Aufruf des Draghandlers.
		///			Dient zur Berechnung des Vektors um den die Szene verschoben werden soll.
		//.......................................................................
		hduVector3Dd m_LastProxyPos;

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Started das Draggen der Szene.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_2BUTTONDOWN.
		///	@param	shapeID	Die ShapeID des Objekts, auf dessen Berührung hin die
		///					Szene bewegt werden soll.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt 
		///					werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	pHandlerObject	Pointer auf das DragSceneHandler-Objekt, das
		///					das Event verarbeiten soll.
		//.......................................................................
		static void HLCALLBACK OnButtonDown(HLenum event,
								HLuint shapeID,
								HLenum thread,
								HLcache *cache,
								void *pHandlerObject);

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Beendet das Draggen der Szene.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_2BUTTONUP.
		///	@param	shapeID	Hier soll HL_OBJECT_ANY angegeben werden.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					 werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	unused	Wird von dieser Funktion nicht benötigt.
		//.......................................................................
		static void HLCALLBACK OnButtonUp(HLenum event,
								HLuint shapeID,
								HLenum thread,
								HLcache *cache,
								void *unused);
		
		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Steuert das Draggen der Szene.
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_MOTION.
		///	@param	shapeID	Hier soll HL_OBJECT_ANY angegeben werden.
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					werden soll, in diesem Fall HL_CLIENT_THREAD.
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		/// @param	pHandlerObject	Pointer auf das DragSceneHandler-Objekt, das
		///					 das Event verarbeiten soll.
		//.......................................................................
		static void HLCALLBACK OnDrag(HLenum event,
								HLuint shapeID,
								HLenum thread,
								HLcache *cache,
								void *pHandlerObject);

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Eventhandler-Objekt mit der
		///			Szene, die bewegt werden soll.
		/// @param	pScene	Pointer auf die Szene für die der Eventhandler
		///					zuständig sein soll. Wird NICHT vom EventHandler freigegeben!
		//.......................................................................
		DragSceneHandler(GraphScene * pScene);

		//.......................................................................
		/// @brief	Nimmt die Proxy-Position beim Starten des Drag-Vorgangs auf.
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		//.......................................................................
		void initAction(HLcache * pCache);

		//.......................................................................
		/// @brief	Veranlasst die Szene, sich mit dem Proxy zu bewegen.
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert.
		//.......................................................................
		void handleDrag(HLcache * pCache);
	
		//=======================================================================
		// Von IHapticAction geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Registriert die Aktion für eine Shape bei HLAPI.
		/// @param	shapeID	ID der Shape, für die die Aktion registriert werden soll.
		//.......................................................................
		virtual void registerAction( HLuint shapeID );

		//.......................................................................
		/// @brief	Meldet die Aktion für eine Shape bei HLAPI ab.
		/// @param	shapeID	ID der Shape, für die die Aktion registriert wurde.
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID );

		//=======================================================================
};

#endif // _DRAGSCENEHANDLER_H_