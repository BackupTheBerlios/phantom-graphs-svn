//*******************************************************************************
/// @file	HapticCursor.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	05.02.2006
//*******************************************************************************

// Änderungen:
// 27.12.05		- Member m_CursorSizePixels, m_CursorScale und Konstruktor hinzu-
//				  gefügt
// 05.02.06		- Doku vervollständigt.


#ifndef _HAPTICCURSOR_H_
#define _HAPTICCURSOR_H_

/// @brief	Standardgröße des HapticCursors
#define DEFAULT_CURSOR_SIZE_PIX 20


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Kapselt ein Zeige-Widget, das den Bewegungen des Phantom-Proxy folgt.
///
///			Codebasis für die Klasse ist das von SensAble zu Verfügung gestellte
///			Constraints-Beispiel.
//...............................................................................
class HapticCursor
{
	protected:
		
		//.......................................................................
		/// @brief	Größe des Cursors in Pixeln.
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
		///			sofern nicht eine Größe für den Cursor angegeben wird.
		///	@param	sizePix	Größe des Cursors in Pixeln (optional).
		//.......................................................................
		HapticCursor(int sizePix = DEFAULT_CURSOR_SIZE_PIX);
		
		//.......................................................................
		///	@brief	Destuktor: Löscht das Cursor-Objekt.
		//.......................................................................
		virtual ~HapticCursor();	

		//.......................................................................
		/// @brief	Skaliert den Cursor je nach der aktuellen Projektion.
		//.......................................................................
		void scale();
		
		//.......................................................................
		/// @brief	Zeichnet den Cursor so dass er mit der Position des haptischen
		///			Gerätes übereinstimmt.
		//.......................................................................
		virtual void render();
		
};

#endif // _HAPTICCURSOR_H_