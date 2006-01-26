//*******************************************************************************
/// @file	HapticConstraint.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		02.01.2006
/// @date	Letzte Änderung	08.01.2006
//*******************************************************************************

// Änderungen:
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
		/// @brief	Der Abstand zwischen der Oberfläche und der Position des Phantom
		///			der überschritten werden muss, um das Phantom von der Constraint-
		///			Oberfläche zu lösen in Millimetern in Workspace-Koordinaten.
		//.......................................................................
		HLfloat m_SnapDistance;
		
		//.......................................................................
		/// @brief	ID, mit der die Constraint-Shape bei HLAPI bekannt ist.
		//.......................................................................
		const HLuint m_HLConstraintID;

		bool m_Enabled;

	public:
		
		//.......................................................................
		///	@brief	Konstruktor: Registriert die Constraint-Shape bei HLAPI und 
		///			initialisiert das Objekt mit den angegebenen Werten.
		///	@param	snapDist	Abstand von der Oberfläche, den das Phantom 
		///			überschreiten muss, um sich von ihr zu lösen. Defaultwert ist
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
		/// @brief	Rendert ein Constraint für das mit pObj bezeichnete Objekt als
		///			eigenständige HLAPI-Shape. Darf nicht innerhalb eines 
		///			hlBeginShape()/hlEndShape-Blockes aufgerufen werden.
		///	@param	pobj	HapticObject, für das ein Constraint gerendert werden
		///			soll.
		//.......................................................................
		void renderConstraint( HapticObject* pObj );

		//.......................................................................
		/// @brief	Sorgt dafür, dass das Constraint bei einem Aufruf von 
		///			renderConstraint() gerendert wird.
		/// @return	Gibt den vorherigen Aktivierungsstatus zurück.
		//.......................................................................
		bool enable();
	
		//.......................................................................
		/// @brief	Verhindert, dass das Constraint bei einem Aufruf von 
		///			renderConstraint() gerendert wird.
		/// @return	Gibt den vorherigen Aktivierungsstatus zurück.
		//.......................................................................
		bool disable();

};

#endif // _HAPTICCONSTRAINT_H_