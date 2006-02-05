//*******************************************************************************
/// @file	HapticEffect.h
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		03.01.2006
/// @date	Letzte �nderung	05.02.2006
//*******************************************************************************

// �nderungen:
// 30.01.06		- neues Attribut m_IsActive hinzugef�gt.
// 05.02.06		- Doku vervollst�ndigt.


#ifndef _HAPTICEFFECT_H_
#define _HAPTICEFFECT_H_

// Haptic Library includes
#include <HL/hl.h>

//...............................................................................
/// @author	Katharina Greiner, Matr.-Nr. 943471
///
/// @brief	Abstrakte Klasse zur Kapselung von HLAPI Force Effects.
///			
///			Dies ist die Basisklasse f�r alle "ambienten" Force Effects. Sie ist
///			f�r das Registrieren und Deregistrieren des Effektes bei HLAPI zust�ndig
///			und stellt Methoden zum Starten, Stoppen und Triggern des Effektes zur 
///			Verf�gung.
///			Abgeleitete Klassen, die instanziiert werden sollen, m�ssen die abstrakte
///			Methode renderProperties() implementieren.
/// @bug	Manchmal wird zwar startEffect() aufgerufen, der Effekt aber nicht 
///			gerendert. Das gleiche gilt f�r stopEffect(): Manchmal wird der Effekt
///			nicht mehr angehalten. Ursache ist bisher ungek�rt.
//...............................................................................
class HapticEffect
{
	protected:
		
		//.......................................................................
		/// @brief	Effekttyp
		///
		///			Zul�ssige Werte:
		///			- HL_EFFECT_CONSTANT
		///			- HL_EFFECT_SPRING
		///			- HL_EFFECT_VISCOUS
		///			- HL_EFFECT_FRICTION
		///			F�r eine detailiertere Beschreibung der Effekttypen, siehe
		///			3D TOUCH SDK - API REFERENCE
		//.......................................................................
		HLenum m_EffectType;
		
		//.......................................................................
		/// @brief	ID, mit der der Effekt bei HLAPI bekannt ist.
		//.......................................................................
		HLuint m_EffectID;

		//.......................................................................
		/// @brief	Flag, das angibt, ob der Effekt aktiv (gestartet) ist.
		//.......................................................................
		bool m_IsActive;

		//.......................................................................
		/// @brief	Muss von abgeleiteten Klassen implementiert werden, um die 
		///			gew�nschten Eigenschaften des Effektes zu spezifizieren.
		//.......................................................................
		virtual void renderProperties() = 0;

	public:

		//.......................................................................
		///	@brief	Konstruktor: Initialisiert das Objekt mit Defaultwerten und 
		///			macht den Effekt bei HLAPI bekannt.
		//.......................................................................
		HapticEffect(HLenum type = HL_EFFECT_CONSTANT);

		//.......................................................................
		/// @brief	Destuktor: Gibt den Effekt bei HLAPI frei.
		//.......................................................................
		virtual ~HapticEffect();
		
		//.......................................................................
		/// @brief	Startet den Effekt. Der Effekt wird so lange gerendert, bis
		///			stopEffekt() aufgerufen wird. Wurde der Effekt bereits gestartet,
		///			hat der Aufruf von startEffect() keinerlei Auswirkung.
		//.......................................................................
		virtual void startEffect();

		//.......................................................................
		/// @brief	Stoppt einen bereits gestarteten Effekt. Ist der Effekt inaktiv,
		///			hat der Aufruf von stopEffect() keinerlei Auswirkung.
		//.......................................................................
		virtual void stopEffect();

		//.......................................................................
		/// @brief	L�st den Effekt einmalig aus, er dauert dann f�r die mit duration
		///			spezifizierte Zeit an.
		///	@param	duration	Dauer des Effektes in Millisekunden. Default: 100.0 ms
		//.......................................................................
		virtual void triggerEffect( double duration = 100.0 );
	
};

#endif // _HAPTICEFFECT_H_