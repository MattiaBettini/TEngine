#pragma once
namespace TEngine
{
	class TEngineAPI Timer
	{
	public:
		Timer();
		virtual ~Timer();

		
	private:
		float m_fCurrentTime;
		float m_fElapsedTime;
	};
}


