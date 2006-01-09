#ifndef _IBUSINESSCONVERTER_H_
#define _IBUSINESSCONVERTER_H_


class IBusinessConverter
{
public:
	
	// Parameter sollte "Position" sein, Rückgabetyp muss noch festgelegt werden
	virtual void viewToBusinessCoordinates() = 0;
	
	// Rückgabetyp sollte "Position" sein, Parametertyp muss noch festgelegt werden
	virtual void businessToViewCoordinates() = 0;
	
};

#endif