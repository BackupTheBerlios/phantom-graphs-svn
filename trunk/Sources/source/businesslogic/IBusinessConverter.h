#ifndef _IBUSINESSCONVERTER_H_
#define _IBUSINESSCONVERTER_H_


class IBusinessConverter
{
public:
	
	// Parameter sollte "Position" sein, R�ckgabetyp muss noch festgelegt werden
	virtual void viewToBusinessCoordinates() = 0;
	
	// R�ckgabetyp sollte "Position" sein, Parametertyp muss noch festgelegt werden
	virtual void businessToViewCoordinates() = 0;
	
};

#endif