#ifndef _NODE_H_
#define _NODE_H_
#include "HapticObject.h"
#include "IObserver.h"
class Texture;
class IBusinessAdapter;


class Node : public HapticObject, public IObserver
{
protected:
	IBusinessAdapter* m_BusinessObject;
	Texture* m_Texture;
public:
	virtual ~Node();
	
	void setTexture( const Texture* value );
	
	Node( IBusinessAdapter * businessObj );
	
};

#endif