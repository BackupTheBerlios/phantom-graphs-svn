#ifndef _IBUSINESSCONVERTER_H_
#define _IBUSINESSCONVERTER_H_


class IBusinessConverter
{
public:
	virtual void viewToBusinessCoordinates() = 0;
	
	virtual void businessToViewCoordinates() = 0;
	
};

#endif