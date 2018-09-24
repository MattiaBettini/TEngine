#pragma once
#include "SpinLock.h"

template<typename T>
class ConcurrentQueue final : private SpinLock
{
public:
	ConcurrentQueue() {};
	~ConcurrentQueue() {};

	void Enqueue(T item)
	{
		Lock();
		elements.push(item);
		Unlock();
	}

	bool Dequeue(T& out)
	{
		Lock();
		bool res = false;

		if (elements.size() > 0)
		{
			res = true;
			out = elements.front();
			elements.pop();
		}
		Unlock();

		return res;
	}

	const int Size()
	{
		return elements.size();
	}

private:
	std::queue<T> elements;
};