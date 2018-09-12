#include "stdafx.h"
#include "SpinLock.h"

void SpinLock::Lock()
{
	bool unlatched = false;
	while (!latch.compare_exchange_weak(unlatched, true, std::memory_order_acquire)) {
		unlatched = false;
	}
}

void SpinLock::Unlock()
{
	latch.store(false, std::memory_order_release);
}