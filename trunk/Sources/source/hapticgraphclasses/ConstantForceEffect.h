#ifndef _CONSTANTFORCEEFFECT_H_
#define _CONSTANTFORCEEFFECT_H_

// Haptic Library includes
#include <HDU/hduVector.h>

#include "HapticEffect.h"


class ConstantForceEffect : public HapticEffect
{
protected:
	virtual void renderProperties();
	
	
	double m_Magnitude;
	
	hduVector3Dd m_Direction;
public:
	virtual ~ConstantForceEffect();
	
	virtual void setMagnitude( double value );
	
	virtual void setDirection( double x, double y, double z );
	
	ConstantForceEffect( const double direction[3], double magnitude );
	
};

#endif