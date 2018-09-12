#pragma once

class SpinLock
{
public:
	SpinLock() {};
	virtual ~SpinLock() {};

protected:
	void Lock();
	void Unlock();

private:
	std::atomic<bool> latch;

};