#pragma once
#include <mutex>
#include <condition_variable>
#include <thread>
#include <stdio.h>

class AutoResetEvent
{
public:
	explicit AutoResetEvent(bool initial = false);
	AutoResetEvent& operator=(const AutoResetEvent&) = delete; // non-copyable

	void Set();
	void Reset();

	bool WaitOne();

private:
	AutoResetEvent(const AutoResetEvent&);
	bool flag_;
	std::mutex protect_;
	std::condition_variable signal_;
};

