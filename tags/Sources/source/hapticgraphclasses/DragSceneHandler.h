//*******************************************************************************
/// @file	DragSceneHandler.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		19.01.2006
/// @date	Letzte Änderung	19.01.2006
//*******************************************************************************

// Änderungen:


#ifndef _DRAGSCENEHANDLER_H_
#define _DRAGSCENEHANDLER_H_

// Haptic Library includes
#include <HL/hl.h>
#include <HDU/hduMatrix.h>

#include "HapticAction.h"
//#include "HapticObject.h"
#include "GraphScene.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Eventhandlerklasse die es ermöglicht, die gesamte Szene mit dem 
///			Phantom zu bewegen
///			
///			Der Eventhandler reagiert auf die folgende Events:
///			- der hintere Phantom-Button wird gedrückt, wenn das registrierte Objekt
///			  mit dem Phantom berührt wird
///			- das Phantom wird mit gedrücktem Button bewegt
///			- der vordere Phantom-Button wird losgelassen
///			Wirkung: Solange der Button gedrückt gehalten wird, folgt ... der Bewegung des Phantom
//...............................................................................
class DragSceneHandler : public IHapticAction
{
	protected:

		//.......................................................................
		/// Das Objekt, dem der Eventhandler zugeordnet ist
		//.......................................................................
//		HapticObject * m_pDragObj;

		GraphScene * m_pDragScene;

		//.......................................................................
		/// Position des Proxy beim letzten Aufruf des Draghandlers
		/// Dient zur Berechnung des Vektors um den das Objekt verschoben werden soll
		//.......................................................................
		hduVector3Dd m_LastProxyPos;

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Started das Draggen des Objekts
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_2BUTTONDOWN
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
								HLcache *cache,
								void *pHandlerObject);

		//.......................................................................
		/// @brief	(HLAPI-Callbackfunktion) Beendet das Draggen des Objekts
		/// @param	event	Gibt an, auf welches HLAPI-Event hin die Callback-
		///					Funktion aufgerufen werden soll, hier HL_EVENT_2BUTTONUP
		///	@param	shapeID	hier soll HL_OBJECT_ANY angegeben werden
		/// @param	thread	Gibt an, in welchem HLAPI-Thread das Event behandelt
		///					 werden soll, in diesem Fall HL_CLIENT_THREAD
		/// @param	cache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		/// @param	userdata	Wird von dieser Funktion nicht benötigt
		//.......................................................................
		static void HLCALLBACK OnButtonUp(HLenum event,
								HLuint shapeID,
								HLenum thread,
								HLcache *cache,
								void *userdata);
		
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
		static void HLCALLBACK OnDrag(HLenum event,
								HLuint shapeID,
								HLenum thread,
								HLcache *cache,
								void *pHandlerObject);

	public:

		//.......................................................................
		/// @brief	Konstruktor, initialisiert das Eventhandler-Objekt mit dem 
		///			zugehörigen haptischen Objekt
		/// @param	pObj	Pointer auf das haptische Objekt für das der 
		///					Eventhandler zuständig sein soll
		//.......................................................................
		DragSceneHandler(GraphScene * pScene);

		//.......................................................................
		/// @brief	Nimmt die Proxy-Position beim Starten des Drag-Vorgangs auf
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		//.......................................................................
		void initAction(HLcache * pCache);

		//.......................................................................
		/// @brief	Veranlasst das haptische Objekt, sich mit dem Proxy zu bewegen
		/// @param	pCache	HLAPI-State Schnappschuss in dem Moment, in dem das Event feuert
		//.......................................................................
		void handleDrag(HLcache * pCache);
	
		//***********************************************************************
		// Von IHapticAction geerbte Methoden
		//***********************************************************************

		//.......................................................................
		/// @brief	Registriert die Aktion für eine Shape bei HLAPI
		/// @param	shapeID	ID der Shape, für die die Aktion registriert werden soll
		//.......................................................................
		virtual void registerAction( HLuint shapeID );

		//.......................................................................
		/// @brief	Meldet die Aktion für eine Shape bei HLAPI ab
		/// @param	shapeID	ID der Shape, für die die Aktion registriert wurde
		//.......................................................................
		virtual void unregisterAction( HLuint shapeID );

		//***********************************************************************
};

#endif // _DRAGSCENEHANDLER_H_