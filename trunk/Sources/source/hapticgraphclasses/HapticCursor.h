//*******************************************************************************
/// @file	HapticCursor.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		- Member m_CursorSizePixels, m_CursorScale und Konstruktor hinzu-
//				  gefügt


#ifndef _HAPTICCURSOR_H_
#define _HAPTICCURSOR_H_

#define DEFAULT_CURSOR_SIZE_PIX 20


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