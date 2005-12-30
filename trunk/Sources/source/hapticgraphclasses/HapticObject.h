//*******************************************************************************
/// @file	HapticObject.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.12.2005
/// @date	Letzte �nderung	27.12.2005
//*******************************************************************************

// �nderungen:
// 27.12.05		Doku zur Klasse angefangen


#ifndef _HAPTICOBJECT_H_
#define _HAPTICOBJECT_H_

// Haptic Library includes
#include <HL/hl.h>
#include <HDU/hduMatrix.h>

// STL includes
#include <vector>

using namespace std;

//class IGraphicMaterial;
//class IHapticMaterial;
class IHapticAction;
//class Position;
//class HapticConstraint;


//...............................................................................
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
		//.......................................................................
		virtual void renderShape() = 0;
		
		//.......................................................................
		//.......................................................................
		virtual void renderDefaultHapticProperties();
		
		//.......................................................................
		//.......................................................................
		virtual void renderDefaultGraphicProperties();
		
//	HapticConstraint* m_hapticConstraint;
//	Position m_position;

		//.......................................................................
		//.......................................................................
		vector<IHapticAction*> m_hapticActions;

//	vector<IHapticProperty> m_hapticProperties;
//	vector<IGraphicProperty> m_graphicProperties;
		
		//.......................................................................
		//.......................................................................
		HLuint m_HLShapeID;

		//.......................................................................
		//.......................................................................
		HLuint m_constraintSID;

		//.......................................................................
		//.......................................................................
		hduMatrix m_transformMatrix;

//	IGraphicMaterial igraphicproperty;

	public:

		//.......................................................................
		//.......................................................................
		HapticObject();

		//.......................................................................
		//.......................................................................
		virtual ~HapticObject();
		
		//.......................................................................
		//.......................................................................
		void setPosition(const double x, const double y, const double z);
		
//	void setHapticConstraint( const HapticConstraint* value );
		
		//.......................................................................
		//.......................................................................
		void renderHaptics();
		
		//.......................................................................
		//.......................................................................
		void renderGraphics();
		
//	void addHapticMaterial( IHapticMaterial * material );
		
		//.......................................................................
		//.......................................................................
		void addHapticAction( IHapticAction * act );
		
//	void addGraphicMaterial( IGraphicMaterial * material );

		//.......................................................................
		//.......................................................................
		virtual void translate(const double x, const double y, const double z);
	
};

#endif // _HAPTICOBJECT_H_