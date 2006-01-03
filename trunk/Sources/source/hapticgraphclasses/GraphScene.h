//*******************************************************************************
/// @file	GraphScene.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	30.12.2005
//*******************************************************************************

// Änderungen:
// 30.12.05		- Konstruktor, Destruktor, renderSceneGraphics(), renderSceneHaptics()
//				  hinzugefügt
//				- Doku zu den implementierten Methoden geschrieben.


#ifndef _GRAPHSCENE_H_
#define _GRAPHSCENE_H_

#include <vector>

using namespace std;

class HapticObject;

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
		
};

#endif // _GRAPHSCENE_H_