//*******************************************************************************
/// @file	HapticConstraint.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		02.01.2006
/// @date	Letzte �nderung	08.01.2006
//*******************************************************************************

// �nderungen:
// 08.01.06		- renderConstraint() hat neuen Parameter pObj bekommen
//				- Doku geschrieben


#ifndef _HAPTICCONSTRAINT_H_
#define _HAPTICCONSTRAINT_H_

// Haptic Library includes
#include <HL/hl.h>

class HapticObject;

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Klasse, die ein HLAPI-Constraint zu einem HapticObject darstellen kann.
///		
///			Das Objekt wirkt auf das Phantom-Device je nach dem Wert der snapDistance
///			mehr oder weniger magnetisch, wenn ihm ein HapticConstraint zugeordnet
///			ist.
//...............................................................................
class HapticConstraint
{
	protected:
		
		//.......................................................................
		/// @brief	Der Abstand zwischen der Oberfl�che und der Position des Phantom
		///			der �berschritten werden muss, um das Phantom von der Constraint-
		///			Oberfl�che zu l�sen in Millimetern in Workspace-Koordinaten.
		//.......................................................................
		HLfloat m_SnapDistance;
		
		//.......................................................................
		/// @brief	ID, mit der die Constraint-Shape bei HLAPI bekannt ist.
		//.......................................................................
		const HLuint m_HLConstraintID;

	public:
		
		//.......................................................................
		///	@brief	Konstruktor: Registriert die Constraint-Shape bei HLAPI und 
		///			initialisiert das Objekt mit den angegebenen Werten.
		///	@param	snapDist	Abstand von der Oberfl�che, den das Phantom 
		///			�berschreiten muss, um sich von ihr zu l�sen. Defaultwert ist
		///			0.0, was bedeutet, dass kein Constraint wirkt.
		//.......................................................................
		HapticConstraint( HLfloat snapDist = 0.0 );

		//.......................................................................
		/// @brief	Destruktor: Meldet die Constraint-Shape bei HLAPI ab.
		//.......................................................................
		virtual ~HapticConstraint();
		
		//.......................................................................
		/// @brief	Setzt den Wert der m_SnapDistance.
		/// @param	value	Neuer Wert der m_SnapDistance.
		//.......................................................................
		void setSnapDistance( HLfloat value );
		
		//.......................................................................
		/// @brief	Rendert ein Constraint f�r das mit pObj bezeichnete Objekt als
		///			eigenst�ndige HLAPI-Shape. Darf nicht innerhalb eines 
		///			hlBeginShape()/hlEndShape-Blockes aufgerufen werden.
		///	@param	pobj	HapticObject, f�r das ein Constraint gerendert werden
		///			soll.
		//.......................................................................
		void renderConstraint( HapticObject* pObj );

};

#endif // _HAPTICCONSTRAINT_H_