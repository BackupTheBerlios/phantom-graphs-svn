//*******************************************************************************
/// @file	GraphScene.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	24.01.2006
//*******************************************************************************

// Änderungen:
// 30.12.05		- Konstruktor, Destruktor, renderSceneGraphics(), renderSceneHaptics()
//				  hinzugefügt
//				- Doku zu den implementierten Methoden geschrieben.
// 24.01.06		- Methode getGraphPlaneZ() hinzugefügt.


#ifndef _GRAPHSCENE_H_
#define _GRAPHSCENE_H_

#include <vector>

using namespace std;

#include "HapticObject.h"

#include "FrictionForceEffect.h"
#include "ConstantForceEffect.h"
#include "ViscousForceEffect.h"

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
		//.......................................................................
		vector<HapticObject*> m_SceneElements;

		//.......................................................................
		/// @brief	Fordert alle Objekte auf, ihre haptische Beschaffenheit zu rendern.
		/// @param	bHapticsEnabled	Gibt an, ob die Haptik gerendert werden kann.
		//.......................................................................
		void renderSceneHaptics(bool bHapticsEnabled);
	
		//.......................................................................
		/// @brief	Fordert alle Objekte auf, ihre graphische Beschaffenheit zu rendern.
		//.......................................................................
		void renderSceneGraphics();	

//FrictionForceEffect * eff;
//ConstantForceEffect * eff;
//FrictionForceEffect * eff2;
ViscousForceEffect * eff;

	public:
		
		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt.
		//.......................................................................
		GraphScene();

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
		/// @brief	
		//.......................................................................
		virtual void initScene();
		
		//.......................................................................
		/// @brief	Fügt der Szene ein neues Objekt hinzu.
		/// @param	obj	Pointer auf das Objekt, das hinzugefügt werden soll.
		//.......................................................................
		void addObject( HapticObject * obj );

		//.......................................................................
		/// @brief	
		//.......................................................................
		void viewFrom(float x, float y, double nearDistance);

		//.......................................................................
		/// @brief	Gibt die z-Koordinate der Ebene parallel zur x-y-Ebene auf 
		///			der der Graph dargestellt wird zurück.
		/// @return	z-Koordinate der Ebene parallel zur x-y-Ebene auf der der 
		///			Graph dargestellt wird.
		//.......................................................................
		static float getGraphPlaneZ();
		
};

#endif // _GRAPHSCENE_H_