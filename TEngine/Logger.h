#pragma once
#include "ConcurrentQueue.h"

class Logger
{
public:
	Logger();
	virtual ~Logger();

	void Log(const string& message);
	void Stop();
private:
	thread m_vPrintThread;
	ConcurrentQueue<string> m_vMessages;
	volatile bool m_bStop;

	static void InternalThreadRoutine(Logger* logger);
};

