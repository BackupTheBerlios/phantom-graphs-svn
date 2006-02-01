//*******************************************************************************
/// @file	Camera.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.01.2006
/// @date	Letzte �nderung	26.01.2006
//*******************************************************************************

// �nderungen:


#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "HapticDevice.h"

// ...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Klasse, die unter Verwendung von OpenGL eine minimale Kameraf�hrung
///			erlaubt.
///
///			Die Sichtrichtung der Kamera ist immer parallel zur z-Achse (Sicht in
///			Richtung der negativen z-Achse), oben ist immer in Richtung der positiven
///			y-Achse.
//...............................................................................
class Camera
{
	protected:
		
		//.......................................................................
		/// @brief	Verh�ltnis der Fensterbreite zur Fensterh�he.
		//.......................................................................
		double m_Ratio;
		
		//.......................................................................
		/// @brief	Abstand zur Kamera, ab dem man Objekte sehen kann.
		//.......................................................................
		double m_NearDistance;
		
		//.......................................................................
		/// @brief	Sehwinkel in y-Richtung.
		//.......................................................................
		double m_FovY;
		
		//.......................................................................
		/// @brief	Abstand zur Kamera, bis zu dem man Objekte sehen kann.
		//.......................................................................
		double m_FarDistance;

		//.......................................................................
		/// @brief	Letzte x-Koordinate der Kamera.
		//.......................................................................
		double m_LastX;

		//.......................................................................
		/// @brief	Letzte y-Koordinate der Kamera.
		//.......................................................................
		double m_LastY;

		//.......................................................................
		/// @brief	HapticDevice, das sich dem Sichtvolumen der Kamera anpassen soll.
		///			Wird nicht von der Camera freigegeben!
		//.......................................................................
		HapticDevice * m_pHapticDevice;

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert die Kamera mit einem Sichtwinkel, 
		///			der danach nicht mehr ver�ndert werden kann, der H�he und Breite
		///			des Fensters und einem HapticDevice, das sich dem Sichtvolumen
		///			der Kamera anpassen soll.
		/// @param	fovY	Sehwinkel in y-Richtung.
		///	@param	viewportWidth	Fensterbreite.
		/// @param	viewportHeight	Fensterh�he.
		///	@param	pHd		Pointer auf das HapticDevice, das sich dem Sichtvolumen
		///					der Kamera anpassen soll.
		//.......................................................................
		Camera( double fovY, int viewportWidth, int viewportHeight, HapticDevice * pHd = NULL );

		//.......................................................................
		/// @brief	Destruktor: Gibt die Resourcen des Objektes frei.
		//.......................................................................
		virtual ~Camera();
		
		//.......................................................................
		/// @brief	Verschiebt die Kamera auf der x-y-Ebene um den Vektor (x, y).
		///	@param	x	x-Komponente des Translationsvektors.
		///	@param	y	y-Komponente des Translationsvektors.
		//.......................................................................
		void translateView( double x, double y );
		
		//.......................................................................
		/// @brief	Berechnet das Sichtvolumen der Kamera anhand der gegebenen
		///			Fensterbreite und -h�he neu.
		///	@param	viewportWidth	Fensterbreite.
		/// @param	viewportHeight	Fensterh�he.	
		//.......................................................................
		void recalculateView( int viewportWidth, int viewportHeight );
		
		//.......................................................................
		/// @brief	Gibt das Verh�ltnis zwischen Fensterbreite und -h�he zur�ck.
		/// @return	Verh�ltnis zwischen Fensterbreite und -h�he.
		//.......................................................................
		double getRatio();
		
};

#endif // _CAMERA_H_