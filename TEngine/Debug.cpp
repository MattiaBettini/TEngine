#include "stdafx.h"
#include "Debug.h"


TEngine::Debug::Debug()
{
	thread t1(&Debug::ThreadInternalRoutine, this);
	printThread.swap(t1);
}


TEngine::Debug::~Debug()
{
}

void TEngine::Debug::Log(string message)
{
	messages.push(message);
}

void TEngine::Debug::ThreadInternalRoutine()
{
	while (true)
	{
		if (!messages.empty())
		{
			string tmp;
			tmp = messages.front();
			messages.pop();
			cout << tmp << endl;
		}
	}
}
