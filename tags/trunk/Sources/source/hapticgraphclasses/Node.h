//*******************************************************************************
/// @file	Node.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte Änderung	05.02.2006
//*******************************************************************************

// Änderungen:
// 03.01.06		- Methode translate() hinzugefügt
// 08.01.06		- Attribute m_Width und m_Height und entsprechende Getter und Setter
//				  hinzugefügt
// 27.01.06		- Incoming- und Outgoing Edges und dazugehörige Methoden hinzugefügt.
// 28.01.06		- Membervariable m_rUnitInfo zur Einheitenkonvertierung hinzugefügt,
//				  Konstruktor entsprechend angepasst.
// 05.02.06		- Doku vervollständigt.


#ifndef _NODE_H_
#define _NODE_H_

// wird von gl.h benötigt
#include <windows.h>

// OpenGL includes
#include <GL/gl.h>

// STL includes
#include <list>

// eigene includes
#include "HapticObject.h"
#include "Edge.h"
#include "Utilities.h"
#include "HapticEffect.h"
#include "../businesslogic/IObserver.h"
#include "../businesslogic/IBusinessAdapter.h"


using std::list;

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
///	@brief	Haptisches Objekt, das einen Knoten in einem Graphen als Rechteck darstellt.
///
///			Der Node lässt sich mit verschieden starken Restriktionen bewegen, je
///			nach Definition der Businesslogik:
///			- Frei bewegbar
///			- eingeschränkt bewegbar
///			- gar nicht bewegbar
///			In der Rolle des Observers beobachtet der Node sein Businesslogik-Objekt
///			und reagiert auf dessen Änderungen.
/// @todo	Der Effekt für "gar nicht bewegbar" muss noch richtig eingestellt werden.
//...............................................................................
class Node : public HapticObject, public IObserver
{
	protected:	
	
		//.......................................................................
		/// @brief	Breite des Node in View-Koordinaten.
		//.......................................................................
		float m_Width;
		
		//.......................................................................
		/// @brief	Höhe des Node in View-Koordinaten.
		//.......................................................................
		float m_Height;

		//.......................................................................
		/// @brief	Zeiger auf ein Businesslogik-Objekt, das der Node darstellen soll.
		///			Die Eigenschaften und das Verhalten des Node werden von diesem
		///			Objekt abgefragt. Wird NICHT vom Node freigegeben!
		//.......................................................................
		IBusinessAdapter * m_pBusinessObject;

		//.......................................................................
		/// @brief	Referenz auf das Einheitenobjekt auf dessen Basis der Node
		///			dargestellt werden soll. Wird NICHT vom Node freigegeben!
		//.......................................................................
		UnitConversionInfo & m_rUnitInfo;

		//.......................................................................
		/// @brief	Effekt, der aktiviert wird, wenn sich der Node nur eingeschränkt
		///			bewegen lassen soll.
		///			Wird vom Node erzeugt und freigegeben.
		//.......................................................................
		HapticEffect * m_pHardToMoveEffect;

		//.......................................................................
		/// @brief	Effekt, der aktiviert wird, wenn sich der Node gar nicht
		///			bewegen lassen soll.
		///			Wird vom Node erzeugt und freigegeben.
		//.......................................................................
		HapticEffect * m_pImpossibleToMoveEffect;

		//.......................................................................
		/// @brief	Liste von Verbindungen zu Vorgängerknoten.
		//.......................................................................
		list<Edge *> m_IncomingEdges;

		//.......................................................................
		/// @brief	Liste von Verbindungen zu Nachfolgerknoten.
		//.......................................................................
		list<Edge *> m_OutgoingEdges;

		//.......................................................................
		/// @brief	Setzt den Endpunkt einer eingehenden Kante neu.
		/// @param	pEdge	Edge, deren Endpunkt verändert werden soll.
		//.......................................................................
		void updateIncomingEdge(Edge * pEdge);

		//.......................................................................
		/// @brief	Setzt den Anfangspunkt einer ausgehenden Kante neu.
		/// @param	pEdge	Edge, deren Anfangspunkt verändert werden soll.
		//.......................................................................
		void updateOutgoingEdge(Edge * pEdge);

		//.......................................................................
		/// @brief	Aktualisiert die Anfangs- und Endpunkte der Kanten, die mit
		///			dem Knoten verbunden sind.
		//.......................................................................
		void updateEdges();

		//.......................................................................
		/// @brief	ID der OpenGL-Displayliste, mit der der Node gezeichnet wird.
		//.......................................................................
		GLuint m_DisplayList;

		//.......................................................................
		/// @brief	Gibt die Displayliste frei und weist ihr einen ungültigen Wert zu.
		//.......................................................................
		void releaseDisplayList();

	public:	

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt mit dem dazugehörigen
		///			Business-Objekt. Alle Darstellungsinformationen werden vom 
		///			Business-Objekt angefordert.
		/// @param	businessObj	Zeiger auf ein Businesslogik-Objekt, das der Node 
		///						darstellen soll. Wird NICHT vom Node freigegeben!
		/// @param	unitInfo	Referenz auf das Einheitenobjekt auf dessen Basis 
		///						der Node dargestellt werden soll. Wird NICHT vom Node freigegeben!
		//.......................................................................
		Node( IBusinessAdapter * businessObj, UnitConversionInfo & unitInfo );

		//.......................................................................
		/// @brief	Destruktor:	Gibt die Ressourcen des Objektes frei.
		//.......................................................................
		virtual ~Node();

		//.......................................................................
		/// @brief	Ändert die Breite des Node.
		/// @param	value	Neue Breite des Node.
		//.......................................................................
		void setWidth( float value );
	
		//.......................................................................
		/// @brief	Ändert die Höhe des Node.
		/// @param	value	Neue Höhe des Node.
		//.......................................................................
		void setHeight( float value );
		
		//.......................................................................
		/// @brief	Gibt die aktuelle Breite des Node zurück.
		/// @return	Die aktuelle Breite des Node.
		//.......................................................................
		float getWidth();
		
		//.......................................................................
		/// @brief	Gibt die aktuelle Höhe des Node zurück.
		/// @return	Die aktuelle Höhe des Node.
		//.......................................................................
		float getHeight();

		//.......................................................................
		/// @brief	Weist dem Node einen neuen Effekt für das Verhindern von 
		///			Bewegung zu.
		/// @param	value	Zeiger auf den neuen Effekt für das Verhindern von 
		///					Bewegung. Wird vom Node freigegeben.
		//.......................................................................
		void setImpossibleToMoveEffect( HapticEffect* value );
	
		//.......................................................................
		/// @brief	Weist dem Node einen neuen Effekt für die eigeschränkte 
		///			Bewegung zu.
		/// @param	value	Zeiger auf den neuen Effekt für die eigeschränkte 
		///					Bewegung. Wird vom Node freigegeben.
		//.......................................................................
		void setHardToMoveEffect( HapticEffect* value );

		//.......................................................................
		/// @brief	Fügt dem Knoten eine eingehende Kante hinzu.
		/// @param	pEdge	Kante, die dem Knoten hinzugefügt werden soll.
		///					Die Kante wird beim Löschen des Knotens nicht freigegeben!
		//.......................................................................
		void addIncomingEdge( Edge * pEdge );

		//.......................................................................
		/// @brief	Fügt dem Knoten eine ausgehende Kante hinzu.
		/// @param	pEdge	Kante, die dem Knoten hinzugefügt werden soll.
		///					Die Kante wird beim Löschen des Knotens nicht freigegeben!
		//.......................................................................
		void addOutgoingEdge( Edge * pEdge );

		//=======================================================================
		// Von HapticObject geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Legt die Geometrie aller Objekte dieser Klasse fest.
		//.......................................................................
		virtual void renderShape();

		//.......................................................................
		/// @brief	Verschiebt den Node um den Vektor [x, y, z] unter Beachtung
		///			durch die Businesslogik definierten Restriktionen.
		///	@param	x	x-Koordinate des Translationsvektors.
		///	@param	y	y-Koordinate des Translationsvektors.
		///	@param	z	z-Koordinate des Translationsvektors.
		//.......................................................................
		virtual void translate(const double x, const double y, const double z);

		//.......................................................................
		/// @brief	Platziert das Objekt an der Stelle mit dem Ortsvektor [x, y, z],
		///			falls das Business-Objekt es erlaubt. Ansonsten wird der Node
		///			an einer vom Business-Objekt berechneten Position platziert.
		///	@param	x	x-Koordinate des Ortsvektors.
		///	@param	y	y-Koordinate des Ortsvektors.
		///	@param	z	z-Koordinate des Ortsvektors.
		//.......................................................................
		virtual void setPosition(const double x, const double y, const double z);

		//=======================================================================


		//=======================================================================
		// Von IObserver geerbte Methoden
		//=======================================================================

		//.......................................................................
		/// @brief	Veranlasst den Observer, sich die benötigten Informationen 
		///			vom Observable zu holen.
		//.......................................................................
		virtual void Update( Observable * pObservable );

		//=======================================================================
		
};

#endif // _NODE_H_