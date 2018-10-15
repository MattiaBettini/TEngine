#pragma once
#include "ConcurrentQueue.h"

template<typename T>
class ConcurrentPool
{
public:
	static T* Get() 
	{
		T* res = nullptr;

		if (m_vQueue.Dequeue(res))
		{
			return res;
		}
		else
		{
			return new T();
		}
	};

	static void Recycle(T item) 
	{
		m_vQueue.Enqueue(item);
	};

protected:
	ConcurrentPool() {};
	virtual ~ConcurrentPool() {};

private:
	static ConcurrentQueue<T*> m_vQueue;
};