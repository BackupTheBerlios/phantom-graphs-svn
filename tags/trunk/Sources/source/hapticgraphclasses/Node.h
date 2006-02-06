//*******************************************************************************
/// @file	Node.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		30.12.2005
/// @date	Letzte �nderung	05.02.2006
//*******************************************************************************

// �nderungen:
// 03.01.06		- Methode translate() hinzugef�gt
// 08.01.06		- Attribute m_Width und m_Height und entsprechende Getter und Setter
//				  hinzugef�gt
// 27.01.06		- Incoming- und Outgoing Edges und dazugeh�rige Methoden hinzugef�gt.
// 28.01.06		- Membervariable m_rUnitInfo zur Einheitenkonvertierung hinzugef�gt,
//				  Konstruktor entsprechend angepasst.
// 05.02.06		- Doku vervollst�ndigt.


#ifndef _NODE_H_
#define _NODE_H_

// wird von gl.h ben�tigt
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
///			Der Node l�sst sich mit verschieden starken Restriktionen bewegen, je
///			nach Definition der Businesslogik:
///			- Frei bewegbar
///			- eingeschr�nkt bewegbar
///			- gar nicht bewegbar
///			In der Rolle des Observers beobachtet der Node sein Businesslogik-Objekt
///			und reagiert auf dessen �nderungen.
/// @todo	Der Effekt f�r "gar nicht bewegbar" muss noch richtig eingestellt werden.
//...............................................................................
class Node : public HapticObject, public IObserver
{
	protected:	
	
		//.......................................................................
		/// @brief	Breite des Node in View-Koordinaten.
		//.......................................................................
		float m_Width;
		
		//.......................................................................
		/// @brief	H�he des Node in View-Koordinaten.
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
		/// @brief	Effekt, der aktiviert wird, wenn sich der Node nur eingeschr�nkt
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
		/// @brief	Liste von Verbindungen zu Vorg�ngerknoten.
		//.......................................................................
		list<Edge *> m_IncomingEdges;

		//.......................................................................
		/// @brief	Liste von Verbindungen zu Nachfolgerknoten.
		//.......................................................................
		list<Edge *> m_OutgoingEdges;

		//.......................................................................
		/// @brief	Setzt den Endpunkt einer eingehenden Kante neu.
		/// @param	pEdge	Edge, deren Endpunkt ver�ndert werden soll.
		//.......................................................................
		void updateIncomingEdge(Edge * pEdge);

		//.......................................................................
		/// @brief	Setzt den Anfangspunkt einer ausgehenden Kante neu.
		/// @param	pEdge	Edge, deren Anfangspunkt ver�ndert werden soll.
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
		/// @brief	Gibt die Displayliste frei und weist ihr einen ung�ltigen Wert zu.
		//.......................................................................
		void releaseDisplayList();

	public:	

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert das Objekt mit dem dazugeh�rigen
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
		/// @brief	�ndert die Breite des Node.
		/// @param	value	Neue Breite des Node.
		//.......................................................................
		void setWidth( float value );
	
		//.......................................................................
		/// @brief	�ndert die H�he des Node.
		/// @param	value	Neue H�he des Node.
		//.......................................................................
		void setHeight( float value );
		
		//.......................................................................
		/// @brief	Gibt die aktuelle Breite des Node zur�ck.
		/// @return	Die aktuelle Breite des Node.
		//.......................................................................
		float getWidth();
		
		//.......................................................................
		/// @brief	Gibt die aktuelle H�he des Node zur�ck.
		/// @return	Die aktuelle H�he des Node.
		//.......................................................................
		float getHeight();

		//.......................................................................
		/// @brief	Weist dem Node einen neuen Effekt f�r das Verhindern von 
		///			Bewegung zu.
		/// @param	value	Zeiger auf den neuen Effekt f�r das Verhindern von 
		///					Bewegung. Wird vom Node freigegeben.
		//.......................................................................
		void setImpossibleToMoveEffect( HapticEffect* value );
	
		//.......................................................................
		/// @brief	Weist dem Node einen neuen Effekt f�r die eigeschr�nkte 
		///			Bewegung zu.
		/// @param	value	Zeiger auf den neuen Effekt f�r die eigeschr�nkte 
		///					Bewegung. Wird vom Node freigegeben.
		//.......................................................................
		void setHardToMoveEffect( HapticEffect* value );

		//.......................................................................
		/// @brief	F�gt dem Knoten eine eingehende Kante hinzu.
		/// @param	pEdge	Kante, die dem Knoten hinzugef�gt werden soll.
		///					Die Kante wird beim L�schen des Knotens nicht freigegeben!
		//.......................................................................
		void addIncomingEdge( Edge * pEdge );

		//.......................................................................
		/// @brief	F�gt dem Knoten eine ausgehende Kante hinzu.
		/// @param	pEdge	Kante, die dem Knoten hinzugef�gt werden soll.
		///					Die Kante wird beim L�schen des Knotens nicht freigegeben!
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
		/// @brief	Veranlasst den Observer, sich die ben�tigten Informationen 
		///			vom Observable zu holen.
		//.......................................................................
		virtual void Update( Observable * pObservable );

		//=======================================================================
		
};

#endif // _NODE_H_