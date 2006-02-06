//*******************************************************************************
/// @file	Edge.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		27.01.2006
/// @date	Letzte �nderung	04.02.2006
//*******************************************************************************

// �nderungen:
// 04.02.06		- Doku vervollst�ndigt.


#ifndef _EDGE_H_
#define _EDGE_H_

// wird von gl.h ben�tigt
#include <windows.h>

// OpenGL includes
#include <GL/gl.h>

// eigene includes
#include "HapticObject.h"
#include "Utilities.h"

// ...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Haptisches Objekt, das eine Kante in einem Graphen darstellt.
//...............................................................................
class Edge : public HapticObject
{
	protected:
		
		//.......................................................................
		/// @brief	Anfangspunkt der Kante.
		//.......................................................................
		Position m_StartPosition;
		
		//.......................................................................
		/// @brief	Endpunkt der Kante.
		//.......................................................................
		Position m_EndPosition;
		
		//.......................................................................
		/// @brief	ID der OpenGL-Displayliste, mit der die Edge gezeichnet wird.
		//.......................................................................
		GLuint m_DisplayList;

		//.......................................................................
		/// @brief	Gibt die Displayliste frei und weist ihr einen ung�ltigen Wert zu.
		//.......................................................................
		void releaseDisplayList();

		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Legt die graphischen Eigenschaften f�r Edges fest.
		//.......................................................................
		virtual void renderDefaultGraphicProperties();

		//=======================================================================

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert die Edge mit Werten f�r
		///			Anfangs- und Endpunkt.
		/// @param	start	Position des Anfangspunktes. Default: [0.0, 0.0, 0.0]
		///	@param	end		Position des Endpunktes.	 Default: [0.0, 0.0, 0.0]
		//.......................................................................
		Edge( Position start = Position(0.0, 0.0, 0.0), Position end = Position(0.0, 0.0, 0.0) );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~Edge();
		
		//.......................................................................
		/// @brief	Setzt den Anfangspunkt der Edge.
		///	@param	value	Neue Position des Anfangspunktes.
		//.......................................................................
		void setStartPosition( Position value );
		
		//.......................................................................
		/// @brief	Setzt den Endpunkt der Edge.
		///	@param	value	Neue Position des Endpunktes.
		//.......................................................................
		void setEndPosition( Position value );
		
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