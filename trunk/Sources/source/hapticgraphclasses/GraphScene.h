//*******************************************************************************
/// @file	GraphScene.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	04.02.2006
//*******************************************************************************

// Änderungen:
// 30.12.05		- Konstruktor, Destruktor, renderSceneGraphics(), renderSceneHaptics()
//				  hinzugefügt
//				- Doku zu den implementierten Methoden geschrieben.
// 24.01.06		- Methode getGraphPlaneZ() hinzugefügt.
// 26.01.06		- initScene() hat neue Parameter bekommen.
//				- GraphScene hat jetzt eine Camera zur Steuerung der Ansicht.
//				- Dafür Methode getView() hinzugefügt.
// 28.01.06		- Membervariable m_rUnitInfo zur Einheitenkonvertierung hinzugefügt,
//				  Konstruktor entsprechend angepasst.
// 04.02.06		- Doku vervollständigt, Code aufgeräumt.


#ifndef _GRAPHSCENE_H_
#define _GRAPHSCENE_H_

// STL includes
#include <vector>

using namespace std;

// eigene includes
#include "HapticObject.h"
#include "Camera.h"
#include "Node.h"
#include "Grid.h"
#include "Utilities.h"
#include "HapticAction.h"
#include "../businesslogic/IBusinessAdapter.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse, die alle haptischen Objekte der Scene verwaltet.
///
///			Sie ist sowohl für die Erzeugung der Objekte verantwortlich, als auch
///			dafür, dass sie sich zur richtigen Zeit rendern.
//...............................................................................
class GraphScene
{
	protected:

		//.......................................................................
		/// @brief	Liste aller haptischen Objekte der Scene. 
		///			Alle Elemente der Szene werden auch von ihr freigegeben.
		//.......................................................................
		vector<HapticObject*> m_SceneElements;

		//.......................................................................
		/// @brief	Camera-Objekt, von dem aus die Szene beobachtet wird. Wird von
		///			der GraphScene erzeugt und freigegeben.
		//.......................................................................
		Camera * m_pCamera;

		//.......................................................................
		/// @brief	Referenz auf das Einheitenobjekt auf dessen Basis die Szene
		///			dargestellt werden soll. Wird NICHT von der GraphScene freigegeben!
		//.......................................................................
		UnitConversionInfo & m_rUnitInfo;

		//.......................................................................
		/// @brief	Eventhandlerobjekt, dass für das Bewegen der Szene mit dem 
		///			Phantom zuständig ist. Wird von der GraphScene erzeugt und freigegeben.
		//.......................................................................
		IHapticAction * m_pDragSceneHandler;

		//.......................................................................
		/// @brief	Fordert alle Objekte auf, ihre haptische Beschaffenheit zu rendern.
		/// @param	bHapticsEnabled	Gibt an, ob die Haptik gerendert werden kann.
		//.......................................................................
		void renderSceneHaptics(bool bHapticsEnabled);
	
		//.......................................................................
		/// @brief	Fordert alle Objekte auf, ihre graphische Beschaffenheit zu rendern.
		//.......................................................................
		void renderSceneGraphics();	

		//.......................................................................
		/// @brief	Erzeugt aus einem Graphen, der durch IBusinessAdapter-Objekte
		///			beschrieben wird rekursiv die zugehörigen Darstellungsobjekte 
		///			und fügt diese der Liste von Szenenelementen hinzu.
		/// @param	businessObj	Knoten, für den ein Darstellungsobjekt erzeugt 
		///						werden soll. Auch für dessen Nachfolger wird
		///						createObjects aufgerufen. Die Knoten werden mit
		///						Kanten verbunden.
		/// @param	pGrid		Nötiger Parameter um die Darstellungsobjekte mit
		///						dem Grid zu verknüpfen.
		/// @return	Das Darstellungsobjekt, das das businessObj repräsentiert.
		/// @todo	Bisher kann mit dieser Methode nur ein Baum erzeugt werden,
		///			nicht jeder beliebige Graph.
		//.......................................................................
		Node * createObjects( IBusinessAdapter * businessObj, Grid * pGrid );

	public:
		
		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt.
		/// @param	unitInfo	Referenz auf das Einheitenobjekt auf dessen Basis 
		///						die Szene dargestellt werden soll. 
		///						Wird NICHT von der GraphScene freigegeben!
		//.......................................................................
		GraphScene( UnitConversionInfo & unitInfo );

		//.......................................................................
		///	@brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~GraphScene();

		//.......................................................................
		/// @brief	Rendert die Haptik und Graphik der Szene.
		/// @param	bHapticsEnabled	Gibt an, ob die Haptik gerendert werden kann.
		//.......................................................................
		void renderScene( bool bHapticsEnabled );
		
		//.......................................................................
		/// @brief	Initialisiert die graphische/haptische Szene.
		///	@param	viewportWidth	Fensterbreite.
		/// @param	viewportHeight	Fensterhöhe.
		///	@param	pHd		Pointer auf das HapticDevice, das sich dem Sichtvolumen
		///					der Kamera anpassen soll.	
		/// @param	gridColmns	Anzahl der Spalten, die das Grid haben soll, auf dem 
		///						der Graph dargestellt wird.
		/// @param	gridRows	Anzahl der Zeilen, die das Grid haben soll, auf dem 
		///						der Graph dargestellt wird.
		/// @param	rootNode	Wurzelknoten eines Graphen, der durch IBusinessAdapter-Objekte
		///						beschrieben wird.
		//.......................................................................
		virtual void initScene( int viewportWidth, int viewportHeight, HapticDevice * pHd,
								int gridColumns, int gridRows,
								IBusinessAdapter * rootNode );
		
		//.......................................................................
		/// @brief	Fügt der Szene ein neues Objekt hinzu.
		/// @param	obj	Pointer auf das Objekt, das hinzugefügt werden soll.
		//.......................................................................
		void addObject( HapticObject * obj );

		//.......................................................................
		/// @brief	Gibt die z-Koordinate der Ebene parallel zur x-y-Ebene auf 
		///			der der Graph dargestellt wird zurück.
		/// @return	z-Koordinate der Ebene parallel zur x-y-Ebene auf der der 
		///			Graph dargestellt wird.
		//.......................................................................
		static float getGraphPlaneZ();

		//.......................................................................
		/// @brief	Gibt das Camera-Objekt zurück, mit dem die Szene betrachtet wird.
		/// @return	Zeiger auf das Camera-Objekt, mit dem die Szene betrachtet wird.
		//.......................................................................
		Camera * getView();
		
};

#endif // _GRAPHSCENE_H_