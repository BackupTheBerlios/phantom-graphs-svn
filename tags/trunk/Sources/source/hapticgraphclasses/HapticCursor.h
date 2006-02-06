//*******************************************************************************
/// @file	HapticCursor.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	05.02.2006
//*******************************************************************************

// �nderungen:
// 27.12.05		- Member m_CursorSizePixels, m_CursorScale und Konstruktor hinzu-
//				  gef�gt
// 05.02.06		- Doku vervollst�ndigt.


#ifndef _HAPTICCURSOR_H_
#define _HAPTICCURSOR_H_

/// @brief	Standardgr��e des HapticCursors
#define DEFAULT_CURSOR_SIZE_PIX 20


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Kapselt ein Zeige-Widget, das den Bewegungen des Phantom-Proxy folgt.
///
///			Codebasis f�r die Klasse ist das von SensAble zu Verf�gung gestellte
///			Constraints-Beispiel.
//...............................................................................
class HapticCursor
{
	protected:
		
		//.......................................................................
		/// @brief	Gr��e des Cursors in Pixeln.
		//.......................................................................
		const int m_SizePixels;

		//.......................................................................
		/// @brief	Skalierungsfaktor, der je nach Projektion berechnet wird.
		//.......................................................................
		double m_Scale;

		//.......................................................................
		/// @brief	ID der OpenGL-Displayliste, mit der der Cursor gezeichnet wird.
		//.......................................................................
		GLuint m_DisplayList;

	public:
		
		//.......................................................................
		/// @brief	Konstuktor: Initialisiert das Cursor-Objekt mit Defaultwerten,
		///			sofern nicht eine Gr��e f�r den Cursor angegeben wird.
		///	@param	sizePix	Gr��e des Cursors in Pixeln (optional).
		//.......................................................................
		HapticCursor(int sizePix = DEFAULT_CURSOR_SIZE_PIX);
		
		//.......................................................................
		///	@brief	Destuktor: L�scht das Cursor-Objekt.
		//.......................................................................
		virtual ~HapticCursor();	

		//.......................................................................
		/// @brief	Skaliert den Cursor je nach der aktuellen Projektion.
		//.......................................................................
		void scale();
		
		//.......................................................................
		/// @brief	Zeichnet den Cursor so dass er mit der Position des haptischen
		///			Ger�tes �bereinstimmt.
		//.......................................................................
		virtual void render();
		
};

#endif // _HAPTICCURSOR_H_