#ifndef _HAPTICEFFECT_H_
#define _HAPTICEFFECT_H_


class HapticEffect
{
protected:
	virtual void renderProperties() = 0;
	
	
	const HLenum m_EffectType;
	
	const HLuint m_EffectID;
public:
	virtual ~HapticEffect();
	
	virtual void triggerEffect( double duration = 100.0 );
	
	virtual void stopEffect();
	
	virtual void startEffect();
	
	HapticEffect();
	
};

#endif