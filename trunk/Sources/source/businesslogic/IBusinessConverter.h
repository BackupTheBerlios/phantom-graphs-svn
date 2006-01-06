#ifndef _IBUSINESSCONVERTER_H_
#define _IBUSINESSCONVERTER_H_


class IBusinessConverter
{
public:
	virtual static void viewToBusinessCoordinates() = 0;
	
	virtual static void businessToViewCoordinates() = 0;
	
};

#endif