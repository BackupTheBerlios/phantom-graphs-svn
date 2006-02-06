//*******************************************************************************
/// @file	Utilities.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte Änderung	05.02.2006
//*******************************************************************************

// Änderungen:
// 24.01.06		- Klasse UnitConversionInfo erstellt
// 28.01.06		- UnitConversionInfo: Umrechnungsmethoden xValueToUnit(), yValueToUnit()
//				  unitToXValue(), unitToYValue() hinzugefügt und implementiert.
// 05.02.06		- Doku vervollständigt.


#ifndef _UTILITIES_H_
#define _UTILITIES_H_

//*******************************************************************************
//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Stellt einen Punkt im 3D-Raum dar.
//...............................................................................
struct Position
{
	public:

		//.......................................................................
		/// @brief	x-Koordinate der Position.
		//.......................................................................
		double x;

		//.......................................................................
		/// @brief	y-Koordinate der Position.
		//.......................................................................
		double y;

		//.......................................................................
		/// @brief	z-Koordinate der Position.
		//.......................................................................
		double z;

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert die Position mit ihren x-, y- und 
		///			z-Koordinaten.
		///
		///			Werden beim Erzeugen eines Position-Objektes keine Koordinaten
		///			angegeben, wird es per default mit [0.0, 0.0, 0.0] initialisiert.
		///
		///	@param	x	x-Koordinate der Position.
		///	@param	y	y-Koordinate der Position.
		///	@param	z	z-Koordinate der Position.

 		//.......................................................................
		Position( double x = 0.0, double y = 0.0, double z = 0.0 );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~Position();
		
		//.......................................................................
		/// @brief	Addiert die Koordinaten der gegebenen Position pos zu den 
		///			Koordinaten des aktuellen Objektes und gibt das Ergebnis als
		///			Positon zurück.
		///			Das aktuelle Objekt wird dabei nicht verändert.
		///	@param	pos	Position, die auf die aktuelle Position addiert werden soll.
		/// @return	Position mit den addierten Koordinaten.
		//.......................................................................
		Position operator+(Position pos);

		//.......................................................................
		/// @brief	Addiert einen gegebenen Wert zu den Koordinaten des aktuellen 
		///			Objektes und gibt das Ergebnis als Positon zurück.
		///			Das aktuelle Objekt wird dabei nicht verändert.
		///	@param	value	Wert, der auf die aktuelle Position addiert werden soll.
		/// @return	Position mit den addierten Koordinaten.
		//.......................................................................
		Position operator+(double value);

}; // class Position
//*******************************************************************************

//*******************************************************************************
//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse, die die Umwandlung zwischen View- und Businesskoordinaten übernimmt.
/// @todo	Die Umrechnung erfolgt bisher mit festen Dummy-Werten. Die dynamische 
///			Berechnung der Einheiten aus der einstellbaren Anzahl der Einheiten
///			pro Bildschirm muss noch implementiert werden.
//...............................................................................
class UnitConversionInfo
{
	protected:

		//.......................................................................
		/// @brief	Bildschirmbreite in View-Einheiten.
		//.......................................................................
		static const float ScreenWidthInViewUnits;

		//.......................................................................
		/// @brief	Bildschirmhöhe in View-Einheiten.
		//.......................................................................
		static const float ScreenHeihgtInViewUnits;
	
		//.......................................................................
		/// @brief	Anzahl der Einheiten, die in vertikaler Richtung auf dem 
		///			Bildschirm dargestellt werden sollen.
		//.......................................................................
		const int m_UnitsPerScreenVertical;
		
		//.......................................................................
		/// @brief	Anzahl der Einheiten, die in horizontaler Richtung auf dem 
		///			Bildschirm dargestellt werden sollen.
		//.......................................................................
		const int m_UnitsPerScreenHorizontal;
		
		//.......................................................................
		/// @brief	Breite einer Einheit in View-Einheiten.
		//.......................................................................
		float m_UnitWidth;
		
		//.......................................................................
		/// @brief	Höhe einer Einheit in View-Einheiten.
		//.......................................................................
		float m_UnitHeight;
		
		//.......................................................................
		/// @brief	Horizontaler Abstand zwischen zwei Knoten.
		//.......................................................................
		const float m_HorizontalPadding;

		//.......................................................................
		/// @brief	Vertikaler Abstand zwischen zwei Knoten.
		//.......................................................................
		const float m_VerticalPadding;

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt mit den angegebenen
		///			Werten und berechnet daraus die Einheitengröße.
		///	@param	upsHorz	Anzahl der Einheiten, die in horizontaler Richtung auf 
		///			dem Bildschirm dargestellt werden sollen.
		/// @param	upsVert	Anzahl der Einheiten, die in vertikaler Richtung auf 
		///			dem Bildschirm dargestellt werden sollen.
		/// @param	paddingHorz	Horizontaler Abstand zwischen zwei Knoten.
		/// @param	paddingVert	Vertikaler Abstand zwischen zwei Knoten.
		/// @todo	Die dynamische Berechnung der Einheiten aus der Anzahl der
		///			Einheiten pro Bildschirm muss noch implementiert werden.
		//.......................................................................
		UnitConversionInfo( int upsHorz, int upsVert,  
							float paddingHorz, float paddingVert );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objekts frei.
		//.......................................................................
		virtual ~UnitConversionInfo();
		
		//.......................................................................
		/// @brief	Gibt die aktuell gesetzte Anzahl der Einheiten, die in vertikaler
		///			Richtung auf dem Bildschirm dargestellt werden sollen, zurück.
		/// @return	Anzahl der Einheiten, die in vertikaler Richtung auf dem 
		///			Bildschirm dargestellt werden.
		//.......................................................................
		int getUnitsPerScreenVertical();
		
		//.......................................................................
		/// @brief	Gibt die aktuell gesetzte Anzahl der Einheiten, die in horizontaler
		///			Richtung auf dem Bildschirm dargestellt werden sollen, zurück.
		/// @return	Anzahl der Einheiten, die in horizontaler Richtung auf dem 
		///			Bildschirm dargestellt werden.
		//.......................................................................
		int getUnitsPerScreenHorizontal();

		//.......................................................................
		/// @brief	Gibt die Breite einer Einheit in View-Einheiten zurück.
		///	@return	Breite einer Einheit in View-Einheiten.
		//.......................................................................
		float getUnitWidth();
		
		//.......................................................................
		/// @brief	Gibt die Höhe einer Einheit in View-Einheiten zurück.
		///	@return	Höhe einer Einheit in View-Einheiten.
		//.......................................................................
		float getUnitHeight();
		
		//.......................................................................
		/// @brief	Gibt den horizontalen Abstand zwischen zwei Knoten zurück.
		/// @return	Horizontaler Abstand zwischen zwei Knoten.
		//.......................................................................
		float getHorizontalPadding();

		//.......................................................................
		/// @brief	Gibt den vertikalen Abstand zwischen zwei Knoten zurück.
		/// @return	Vertikaler Abstand zwischen zwei Knoten.
		//.......................................................................
		float getVerticalPadding();

		//.......................................................................
		/// @brief	Rechnet eine View-x-Koordinate in Business-Einheiten um.
		//.......................................................................
		float xValueToUnit(float xValue);

		//.......................................................................
		/// @brief	Rechnet eine View-y-Koordinate in Business-Einheiten um.
		//.......................................................................
		float yValueToUnit(float yValue);

		//.......................................................................
		/// @brief	Rechnet einen Business-Einheiten-Wert in View-x-Koordinaten um.
		//.......................................................................
		float unitToXValue(float unit);

		//.......................................................................
		/// @brief	Rechnet einen Business-Einheiten-Wert in View-y-Koordinaten um.
		//.......................................................................
		float unitToYValue(float unit);
		
}; // class UnitConversionInfo
//*******************************************************************************

//*******************************************************************************
//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Einfache Klasse um mit glut einen Text auszugeben.
///	@todo	Textausgabe funktioniert noch nicht.
//...............................................................................
class GlutString
{
	public:

		//.......................................................................
		/// @brief	Gibt den String string an der Position pos aus.
		///	@param	string	Zeiger auf einen C-String der ausgegeben werden soll.
		/// @param	pos		Position, an der der Text ausgegeben werden soll.
		///	@todo	Funktioniert noch nicht.
		//.......................................................................
		static void write(char * string, Position pos);		
		
}; // class GlutString
//*******************************************************************************

#endif // _UTILITIES_H_