//*******************************************************************************
/// @file	Utilities.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte Änderung	28.01.2006
//*******************************************************************************

// Änderungen:
// 24.01.06		- Klasse UnitConversionInfo erstellt
// 28.01.06		- UnitConversionInfo: Umrechnungsmethoden xValueToUnit(), yValueToUnit()
//				  unitToXValue(), unitToYValue() hinzugefügt und implementiert.


#ifndef _UTILITIES_H_
#define _UTILITIES_H_

//*******************************************************************************
//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
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
		/// @brief
		//.......................................................................
		UnitConversionInfo( int upsHorz, int upsVert,  
							float paddingHorz, float paddingVert );

		//.......................................................................
		/// @brief
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
		/// @brief	
		//.......................................................................
		float getHorizontalPadding();

		//.......................................................................
		/// @brief
		//.......................................................................
		float getVerticalPadding();

		//.......................................................................
		/// @brief
		//.......................................................................
		float xValueToUnit(float xValue);

		//.......................................................................
		/// @brief
		//.......................................................................
		float yValueToUnit(float yValue);

		//.......................................................................
		/// @brief
		//.......................................................................
		float unitToXValue(float unit);

		//.......................................................................
		/// @brief
		//.......................................................................
		float unitToYValue(float unit);
		
}; // class UnitConversionInfo
//*******************************************************************************

//*******************************************************************************
//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
//...............................................................................
class GlutString
{
	public:

		//.......................................................................
		/// @brief	
		//.......................................................................
		static void write(char * string, Position pos);		
		
}; // class GlutString
//*******************************************************************************

#endif // _UTILITIES_H_