//*******************************************************************************
/// @file	Grid.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		17.01.2006
/// @date	Letzte Änderung	24.01.2006
//*******************************************************************************

// Änderungen:
// 24.01.06		- Methoden isGridPoint() und nearestGridPoint() hinzugefügt.


#ifndef _GRID_H_
#define _GRID_H_

// wird von gl.h benötigt
#include <windows.h>

// OpenGL includes
#include <GL/gl.h>

#include "HapticObject.h"


//*******************************************************************************
// Konstantendeklarationen
//*******************************************************************************

//...............................................................................
/// @brief	
//...............................................................................
const float c_GridColumnWidth = 0.12f;

//...............................................................................
/// @brief	
//...............................................................................
const float c_GridRowHeight = 0.12f;

//*******************************************************************************


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	
///			Die Position des Grid wird durch die linke untere Ecke festgelegt.
//...............................................................................
class Grid : public HapticObject
{
	protected:
		
		//.......................................................................
		/// @brief	Anzahl der Zeilen des Grid.
		//.......................................................................
		int m_Rows;
		
		//.......................................................................
		/// @brief	Anzahl der Spalten des Grid.
		//.......................................................................
		int m_Columns;

		//.......................................................................
		/// @brief	ID der OpenGL-Displayliste, mit der das Grid gezeichnet wird.
		//.......................................................................
		GLuint m_DisplayList;

		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual void renderDefaultGraphicProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Grid mit einer bestimmten 
		///			Anzahl an Zeilen und Spalten.
		///	@param cols	Anzahl der Spalten des Grid.
		///	@param rows	Anzahl der Zeilen des Grid.
		//.......................................................................
		Grid( int cols = 1, int rows = 1 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~Grid();

		//.......................................................................
		/// @brief	Stellt fest, ob eine gegebene Position mit einem gültigen 
		///			Gitterpunkt überein stimmt (Toleranz 0.01).
		/// @param	pos	Die zu überprüfende Position.
		/// @return	true, wenn pos ein gültiger Gitterpunkt ist, sonst false.
		//.......................................................................
		bool isGridPoint(Position pos);

		//.......................................................................
		/// @brief	Ermittelt zu einer gegebenen Position den nächstgelegenen 
		///			gültigen Gitterpunkt.
		/// @param	pos	Die zu überprüfende Position.
		/// @return	Position des zu pos nächstgelegenen Gitterpunktes.
		//.......................................................................
		Position nearestGridPoint(Position pos);
		
		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual void renderShape();
	
		//=======================================================================
};

#endif