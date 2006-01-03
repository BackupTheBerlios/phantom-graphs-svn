#ifndef _HAPTICEFFECT_H_
#define _HAPTICEFFECT_H_

// Haptic Library includes
#include <HL/hl.h>

class HapticEffect
{
protected:
	virtual void renderProperties() = 0;
	
	
	HLenum m_EffectType;
	
	const HLuint m_EffectID;
public:
	virtual ~HapticEffect();
	
	virtual void triggerEffect( double duration = 100.0 );
	
	virtual void stopEffect();
	
	virtual void startEffect();
	
	HapticEffect();
	
};

#endif