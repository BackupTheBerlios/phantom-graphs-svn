//*******************************************************************************
/// @file	HapticDevice.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte Änderung	27.12.2005
//*******************************************************************************

// Änderungen:
// 27.12.05		Doku zur Klasse geschrieben


#ifndef _HAPTICDEVICE_H_
#define _HAPTICDEVICE_H_

// Haptic Library includes
#include <HL/hl.h>


//...............................................................................
/// @brief	Eine Klasse zur Verwaltung des Haptischen Gerätes
///
///			Übernimmt die Initialisierung des Haptischen Gerätes und die Anpassung
///			des Workspaces des Gerätes an das Sichtvolumen.
//...............................................................................
class HapticDevice
{
	protected:
	
		//.......................................................................
		/// @brief	Handle, mit dem auf das haptische Gerät zugegriffen werden kann
		//.......................................................................
		HHD m_hHapticDevice;
	
		//.......................................................................
		/// @brief	Handle zum haptischen Rendering Context
		//.......................................................................
		HHLRC m_hHLRenderingContext;

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert die Membervariablen mit Defaultwerten
		///			Das Gerät wird erst intialisiert, wenn initialize() aufgerufen
		///			wird.
		//.......................................................................
		HapticDevice();

		//.......................................................................
		/// @brief	Gibt den Rendering Context und das haptische Device frei.
		//.......................................................................
		~HapticDevice();

		//.......................................................................
		/// @brief	Passt den Workspace des Gerätes an das Sichtvolumen an.
		//.......................................................................
		void updateWorkspace();
	
		//.......................................................................
		/// @brief	Mit dieser Methode kann festgestellt werden, ob das haptische
		///			Gerät aktiv ist.
		///	@return	true, wenn das Gerät benutzt werden kann, sonst false.
		//.......................................................................
		bool isActive();
	
		//.......................................................................
		/// @brief	Initialisiert das haptische Gerät und den haptischen Rendering
		///			Context.
		//.......................................................................
		void initialize();
	
};

#endif // _HAPTICDEVICE_H_