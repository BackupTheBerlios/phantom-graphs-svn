// IBusinessAdapter.h: Schnittstelle für die Klasse IBusinessAdapter.
//
//*******************************************************************************
/// @file	IBusinessAdapter.h
/// @author	Carsten Arnold, Matr.-Nr. 232237
/// @date	Erstellt am		15.12.2005
/// @date	Letzte Änderung	09.01.2006
//*******************************************************************************

// Änderungen:
// 09.01.06		- Schnittstellen getWidth(), getHeight() und getPosition() hinzugefügt (Kathrin)


#if !defined(AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_)
#define AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../hapticgraphclasses/Utilities.h"

//...............................................................................
/// @brief	Adapterklasse der eine Referenz zwischen Grafikobjekten der
///			haptischen Szene und den Aufgaben herstellt.
///			
///			Jeder Node enthält eine Referenz auf seine entsprechende
///			Aufgabe um relevante Daten mit Ihr auszutauschen
/// @todo	Definition der abstrakten Adapter Methoden
//...............................................................................
class IBusinessAdapter  
{
public:

	//...............................................................................
	/// @brief	Liefert die Kraft, die notwendig ist, um eine Aufgabe zu verschieben
	///
	///			1 = keine Kraft
	///			2 = lässt sich schwer bewegen
	///			3 = lässt sich gar nicht bewegen
	///			0 = kann nicht berechnet werden
	///			-1= Fehler
	//...............................................................................
	virtual int getForce()=0;

	//.......................................................................
	/// @brief	Ermittelt die Breite des Darstellungsobjektes in View-Einheiten.
	/// @return	Breite des Darstellungsobjektes in View-Einheiten.
	//.......................................................................
	virtual float getWidth() = 0;

	//.......................................................................
	/// @brief	Ermittelt die Höhe des Darstellungsobjektes in View-Einheiten.
	/// @return	Höhe des Darstellungsobjektes in View-Einheiten.
	//.......................................................................
	virtual float getHeight() = 0;
	
	//.......................................................................
	/// @brief	Ermittelt die Position (linke obere Ecke) des Darstellungsobjektes in View-Koordinaten.
	/// @return	Position des Darstellungsobjektes in View-Koordinaten.
	//.......................................................................
	virtual Position getPosition() = 0;

};

#endif // !defined(AFX_IBUSINESSADAPTER_H__6A0D2DAF_7C57_48C6_AAE3_5961D5FD4ABF__INCLUDED_)
