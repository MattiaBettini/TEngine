#include "stdafx.h"
#include "Logger.h"


Logger::Logger()
{
	thread t1(InternalThreadRoutine, this);
	m_vPrintThread.swap(t1);
	m_bStop = false;
}


Logger::~Logger()
{
	m_bStop = true;
	m_vPrintThread.join();
}

void Logger::Log(const string& message)
{
	m_vMessages.Enqueue(message);
}

void Logger::Stop()
{

}

void Logger::InternalThreadRoutine(Logger* logger)
{
	string tmp = "";
	while (!logger->m_bStop)
	{
		while (logger->m_vMessages.Dequeue(tmp))
		{
			cout << tmp << endl;
		}

		sleep_for(chrono::milliseconds(10));
	}
}
