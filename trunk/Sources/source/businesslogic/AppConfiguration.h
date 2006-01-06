#ifndef _APPCONFIGURATION_H_
#define _APPCONFIGURATION_H_


class AppConfiguration
{
protected:
	
	int m_ProjectDuration;
public:
	virtual ~AppConfiguration();
	
	void setProjectDuration( int value );
	
	int getProjectDuration();
	
	AppConfiguration();
	
};

#endif