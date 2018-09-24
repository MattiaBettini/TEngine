#pragma once

namespace TEngine
{
	class TEngineAPI Debug
	{
	public:
		Debug();
		virtual ~Debug();
		static void Log(string message);
	private:
		static queue<string> messages;
		static thread printThread;

		static void ThreadInternalRoutine();
	};
}


