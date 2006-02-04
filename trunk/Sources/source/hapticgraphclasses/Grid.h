//*******************************************************************************
/// @file	Grid.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		17.01.2006
/// @date	Letzte �nderung	04.02.2006
//*******************************************************************************

// �nderungen:
// 24.01.06		- Methoden isGridPoint() und nearestGridPoint() hinzugef�gt.
// 28.01.06		- Membervariable m_rUnitInfo zur Einheitenkonvertierung hinzugef�gt,
//				  Konstruktor entsprechend angepasst.
// 04.02.06		- Doku vervollst�ndigt.


#ifndef _GRID_H_
#define _GRID_H_

// wird von gl.h ben�tigt
#include <windows.h>

// OpenGL includes
#include <GL/gl.h>

// eigene includes
#include "HapticObject.h"
#include "Utilities.h"


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse, die Gitterraster darstellt, auf dem die Elemente eines Graphen
///			Angeordnet werden k�nnen.
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

		//.......................................................................
		/// @brief	Referenz auf das Einheitenobjekt auf dessen Basis das Grid
		///			dargestellt werden soll. Wird NICHT vom Grid freigegeben!
		//.......................................................................
		UnitConversionInfo & m_rUnitInfo;

		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Legt die graphischen Eigenschaften f�r Grids fest.
		//.......................................................................
		virtual void renderDefaultGraphicProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Grid mit einer bestimmten 
		///			Anzahl an Zeilen und Spalten.
		/// @param	unitInfo	Referenz auf das Einheitenobjekt auf dessen Basis 
		///						das Grid dargestellt werden soll. Wird NICHT vom Grid freigegeben!
		///	@param	cols		Anzahl der Spalten des Grid. Default: 1
		///	@param	rows		Anzahl der Zeilen des Grid.  Default: 1
		//.......................................................................
		Grid( UnitConversionInfo & unitInfo, int cols = 1, int rows = 1 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~Grid();

		//.......................................................................
		/// @brief	Stellt fest, ob eine gegebene Position mit einem g�ltigen 
		///			Gitterpunkt �berein stimmt (Toleranz 0.01).
		/// @param	pos	Die zu �berpr�fende Position.
		/// @return	true, wenn pos ein g�ltiger Gitterpunkt ist, sonst false.
		//.......................................................................
		bool isGridPoint(Position pos);

		//.......................................................................
		/// @brief	Ermittelt zu einer gegebenen Position den n�chstgelegenen 
		///			g�ltigen Gitterpunkt.
		/// @param	pos	Die zu �berpr�fende Position.
		/// @return	Position des zu pos n�chstgelegenen Gitterpunktes.
		//.......................................................................
		Position nearestGridPoint(Position pos);
		
		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Legt die Geometrie aller Objekte dieser Klasse fest.
		//.......................................................................
		virtual void renderShape();
	
		//=======================================================================
};

#endif