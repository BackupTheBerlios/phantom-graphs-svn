//*******************************************************************************
/// @file	Grid.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		17.01.2006
/// @date	Letzte �nderung	17.01.2006
//*******************************************************************************

// �nderungen:


#ifndef _GRID_H_
#define _GRID_H_

// wird von gl.h ben�tigt
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
const float c_GridColumnWidth = 0.11f;

//...............................................................................
/// @brief	
//...............................................................................
const float c_GridRowHeight = 0.11f;

//*******************************************************************************


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	
//...............................................................................
class Grid : public HapticObject
{
	protected:
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		int m_Rows;
		
		//.......................................................................
		/// @brief	
		//.......................................................................
		int m_Columns;

		//.......................................................................
		/// @brief	ID der OpenGL-Displayliste, mit der das Grid gezeichnet wird.
		//.......................................................................
		GLuint m_DisplayList;

		//***********************************************************************
		// Von HapticObject geerbte Methoden
		//***********************************************************************

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual void renderDefaultGraphicProperties();

		//***********************************************************************

	public:

		//.......................................................................
		/// @brief	
		//.......................................................................
		Grid( int cols = 1, int rows = 1 );

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual ~Grid();
		
		//***********************************************************************
		// Von HapticObject geerbte Methoden
		//***********************************************************************

		//.......................................................................
		/// @brief	
		//.......................................................................
		virtual void renderShape();
	
		//***********************************************************************
};

#endif