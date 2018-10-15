#pragma once
#include "ConcurrentPool.h"


class Engine;



class IMessage
{
public:
	virtual ~IMessage() {};
	virtual void Execute() = 0;
};


template<typename T>
class Message :  public IMessage, public ConcurrentPool<T>
{
public:
	Message() 
	{
		m_pEngine = dynamic_cast<Engine*>(TEngine::TEngineFactory::GetEngine());
	};

	virtual ~Message() 
	{
		m_pEngine = nullptr;
	};

protected:
	Engine* m_pEngine;
	
};