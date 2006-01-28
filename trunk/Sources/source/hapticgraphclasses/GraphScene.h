//*******************************************************************************
/// @file	GraphScene.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	28.01.2006
//*******************************************************************************

// �nderungen:
// 30.12.05		- Konstruktor, Destruktor, renderSceneGraphics(), renderSceneHaptics()
//				  hinzugef�gt
//				- Doku zu den implementierten Methoden geschrieben.
// 24.01.06		- Methode getGraphPlaneZ() hinzugef�gt.
// 26.01.06		- initScene() hat neue Parameter bekommen.
//				- GraphScene hat jetzt eine Camera zur Steuerung der Ansicht.
//				- Daf�r Methode getView() hinzugef�gt.
// 28.01.06		- Membervariable m_rUnitInfo zur Einheitenkonvertierung hinzugef�gt,
//				  Konstruktor entsprechend angepasst.


#ifndef _GRAPHSCENE_H_
#define _GRAPHSCENE_H_

#include <vector>

using namespace std;

#include "HapticObject.h"
#include "Camera.h"
#include "Node.h"
#include "Grid.h"
#include "Utilities.h"
#include "HapticAction.h"

#include "FrictionForceEffect.h"
#include "ConstantForceEffect.h"
#include "ViscousForceEffect.h"
#include "../businesslogic/IBusinessAdapter.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse, die alle haptischen Objekte der Scene verwaltet.
///
///			Sie ist sowohl f�r die Erzeugung der Objekte verantwortlich, als auch
///			daf�r, dass sie sich zur richtigen Zeit rendern.
//...............................................................................
class GraphScene
{
	protected:

		//.......................................................................
		/// @brief	Liste aller haptischen Objekte der Scene.
		//.......................................................................
		vector<HapticObject*> m_SceneElements;

		//.......................................................................
		/// @brief	
		//.......................................................................
		Camera * m_pCamera;

		//.......................................................................
		/// @brief	
		//.......................................................................
		UnitConversionInfo & m_rUnitInfo;

		//.......................................................................
		/// @brief	
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
		/// @brief	
		//.......................................................................
		Node * createObjects( IBusinessAdapter * businessObj, Grid * pGrid );

//FrictionForceEffect * eff;
//ConstantForceEffect * eff;
//FrictionForceEffect * eff2;
ViscousForceEffect * eff;

	public:
		
		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt.
		//.......................................................................
		GraphScene( UnitConversionInfo & unitInfo );

		//.......................................................................
		///	@brief	Destruktor: Gibt alle Objekte der Szene frei.
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
		/// @param	viewportHeight	Fensterh�he.
		///	@param	pHd		Pointer auf das HapticDevice, das sich dem Sichtvolumen
		///					der Kamera anpassen soll.	
		//.......................................................................
		virtual void initScene( int viewportWidth, int viewportHeight, HapticDevice * pHd,
								int gridColumns, int gridRows,
								IBusinessAdapter * rootNode );
		
		//.......................................................................
		/// @brief	F�gt der Szene ein neues Objekt hinzu.
		/// @param	obj	Pointer auf das Objekt, das hinzugef�gt werden soll.
		//.......................................................................
		void addObject( HapticObject * obj );

		//.......................................................................
		/// @brief	Gibt die z-Koordinate der Ebene parallel zur x-y-Ebene auf 
		///			der der Graph dargestellt wird zur�ck.
		/// @return	z-Koordinate der Ebene parallel zur x-y-Ebene auf der der 
		///			Graph dargestellt wird.
		//.......................................................................
		static float getGraphPlaneZ();

		//.......................................................................
		/// @brief	
		//.......................................................................
		Camera * getView();
		
};

#endif // _GRAPHSCENE_H_