#ifndef _UTILITIES_H_
#define _UTILITIES_H_


class Position
{
public:
	virtual ~Position();
	
	Position( double x = 0.0, double y = 0.0, double z = 0.0 );
	
	
	double z;
	
	double y;
	
	double x;
};

#endif