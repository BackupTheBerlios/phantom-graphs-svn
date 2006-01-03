//*******************************************************************************
/// @file	HapticDevice.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		26.12.2005
/// @date	Letzte �nderung	27.12.2005
//*******************************************************************************

// �nderungen:
// 27.12.05		Doku zur Klasse geschrieben


#ifndef _HAPTICDEVICE_H_
#define _HAPTICDEVICE_H_

// Haptic Library includes
#include <HL/hl.h>


//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Eine Klasse zur Verwaltung des Haptischen Ger�tes
///
///			�bernimmt die Initialisierung des Haptischen Ger�tes und die Anpassung
///			des Workspaces des Ger�tes an das Sichtvolumen.
//...............................................................................
class HapticDevice
{
	protected:
	
		//.......................................................................
		/// @brief	Handle, mit dem auf das haptische Ger�t zugegriffen werden kann
		//.......................................................................
		HHD m_hHapticDevice;
	
		//.......................................................................
		/// @brief	Handle zum haptischen Rendering Context
		//.......................................................................
		HHLRC m_hHLRenderingContext;

	public:

		//.......................................................................
		/// @brief	Konstruktor: Initialisiert die Membervariablen mit Defaultwerten
		///			Das Ger�t wird erst intialisiert, wenn initialize() aufgerufen
		///			wird.
		//.......................................................................
		HapticDevice();

		//.......................................................................
		/// @brief	Gibt den Rendering Context und das haptische Device frei.
		//.......................................................................
		~HapticDevice();

		//.......................................................................
		/// @brief	Passt den Workspace des Ger�tes an das Sichtvolumen an.
		//.......................................................................
		void updateWorkspace();
	
		//.......................................................................
		/// @brief	Mit dieser Methode kann festgestellt werden, ob das haptische
		///			Ger�t aktiv ist.
		///	@return	true, wenn das Ger�t benutzt werden kann, sonst false.
		//.......................................................................
		bool isActive();
	
		//.......................................................................
		/// @brief	Initialisiert das haptische Ger�t und den haptischen Rendering
		///			Context.
		//.......................................................................
		void initialize();
	
};

#endif // _HAPTICDEVICE_H_