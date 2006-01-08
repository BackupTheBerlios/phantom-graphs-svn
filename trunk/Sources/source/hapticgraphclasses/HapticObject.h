//*******************************************************************************
/// @file	HapticObject.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.12.2005
/// @date	Letzte �nderung	08.01.2006
//*******************************************************************************

// �nderungen:
// 27.12.05		- Doku zur Klasse angefangen
// 03.01.06		- Methode getPosition() hinzugef�gt
// 08.01.06		- Attribut m_pHapticConstraint und zugeh�rigen Setter hinzugef�gt
//				- Baustellencode aufger�umt
//				- Doku zu einigen Attributen und Methoden geschrieben


#ifndef _HAPTICOBJECT_H_
#define _HAPTICOBJECT_H_

// Haptic Library includes
#include <HL/hl.h>
#include <HDU/hduMatrix.h>

// STL includes
#include <vector>

using namespace std;

#include "HapticAction.h"
#include "HapticConstraint.h"
#include "Utilities.h"

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Basisklasse aller haptischen Objekte. Stellt grundlegende Funktionalit�t
///			zum F�hlbarmachen und Bewegen von Objekten zur Verf�gung. K�mmert sich
///			Um die Registrierung von Eventhandlern. 
///
///			Da die Klasse HapticObject abstrakt ist, kann sie nicht direkt 
///			instanziiert werden. Abgeleitete Klassen m�ssen die Geometrie f�r das
///			Objekt erzeugen.
//...............................................................................
class HapticObject
{
	protected:

		//.......................................................................
		/// @brief	ID, mit der das Objekt bei HLAPI bekannt ist.
		//.......................................................................
		const HLuint m_HLShapeID;

		//.......................................................................
		/// @brief	Die aktuelle Transform-Matrix des HapticObject.
		//.......................................................................
		hduMatrix m_transformMatrix;

		//.......................................................................
		/// @brief	Sorgt daf�r, dass sich das HapticObject f�r das Phantom
		///			magnetisch anf�hlt.
		//.......................................................................
		HapticConstraint* m_pHapticConstraint;

		//.......................................................................
		/// @brief	Liste der Eventhandler, die das Objekt betreffen.
		//.......................................................................
		vector<IHapticAction*> m_HapticActions;

//	vector<IHapticProperty> m_hapticProperties;

//	vector<IGraphicProperty> m_graphicProperties;
		
		//.......................................................................
		/// @brief	Hier werden die Standard-Haptikeigenschaften eines Objektes
		///			festgelegt.
		///
		///			Die Standardeigenschaften k�nnen f�r abgeleitete Klassen
		///			neu festgelegt werden.
		//.......................................................................
		virtual void renderDefaultHapticProperties();
		
		//.......................................................................
		/// @brief	Hier werden die Standard-Graphikeigenschaften eines Objektes
		///			festgelegt.
		///
		///			Die Standardeigenschaften k�nnen f�r abgeleitete Klassen
		///			neu festgelegt werden.
		//.......................................................................
		virtual void renderDefaultGraphicProperties();

	public:

		//.......................................................................
		//.......................................................................
		HapticObject();

		//.......................................................................
		//.......................................................................
		virtual ~HapticObject();

		//.......................................................................
		/// @brief	Hier wird die Geometrie des Objekts festgelegt.
		///
		///			Am besten wird daf�r eine Displayliste verwendet. Diese Methode 
		///			muss von allen abgeleiteten Klassen implementiert werden.
		//.......................................................................
		virtual void renderShape() = 0;

		//.......................................................................
		//.......................................................................
		void renderHaptics();
		
		//.......................................................................
		//.......................................................................
		void renderGraphics();

		//.......................................................................
		/// @brief	Setzt ein Constraint f�r das HapticObject. Das �bergebene
		///			Constraint-Objekt wird beim Deleten des HapticObjects mit 
		///			freigegeben.
		///	@param	value	Pointer auf ein Constraint-Objekt, das von jetzt an
		///			mit dem HapticObject verbunden ist. Wird von dem HapticObject 
		///			freigegeben.
		//.......................................................................
		void setHapticConstraint( HapticConstraint* value );
		
//	void addHapticMaterial( IHapticMaterial * material );

//	void addGraphicMaterial( IGraphicMaterial * material );
		
		//.......................................................................
		/// @brief	F�gt dem Objekt einen Eventhandler hinzu und sorgt daf�r, dass
		///			die entprechenden Events f�r das Objekt registriert werden.
		///			Das �bergebene Eventhandler-Objekt wird beim Deleten des 
		///			HapticObjects mit freigegeben.
		///	@param	act		Pointer auf den Actionhandler, der dem Objekt zugeordnet
		///			werden soll. Wird von dem HapticObject freigegeben.
		//.......................................................................
		void addHapticAction( IHapticAction * act );

		//.......................................................................
		/// @brief	Verschiebt das Objekt um den Vektor (x, y, z).
		///	@param	x	x-Koordinate des Translationsvektors.
		///	@param	y	y-Koordinate des Translationsvektors.
		///	@param	z	z-Koordinate des Translationsvektors.
		//.......................................................................
		virtual void translate(const double x, const double y, const double z);

		//.......................................................................
		/// @brief	Platziert das Objekt an der Stelle mit dem Ortsvektor (x, y, z).
		///	@param	x	x-Koordinate des Ortsvektors.
		///	@param	y	y-Koordinate des Ortsvektors.
		///	@param	z	z-Koordinate des Ortsvektors.
		//.......................................................................
		virtual void setPosition(const double x, const double y, const double z);

		//.......................................................................
		/// @brief	Ermittelt den Ortsvektor der aktuellen Position des Objekts 
		///			und gibt diesen zur�ck.
		///	@return	Ortsvektor der aktuellen Position des Objekts.
		//.......................................................................
		Position getPosition();
	
};

#endif // _HAPTICOBJECT_H_