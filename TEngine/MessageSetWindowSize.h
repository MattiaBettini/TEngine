#pragma once
#include "Message.h"

class MessageSetWindowSize : public Message<MessageSetWindowSize>
{
public:
	MessageSetWindowSize();
	virtual ~MessageSetWindowSize();

	// Inherited via Message
	virtual void Execute() override;
	
	void Set(int w, int h);

private:
	int m_iWidth;
	int m_iHeight;
};