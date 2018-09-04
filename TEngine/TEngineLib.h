#pragma once
#include <string>

using namespace std;

namespace TEngine
{
	enum RenderSystem
	{
		OpenGl = 1,
		Vulkan = 2
	};

	class IEngine
	{
	public:
		virtual ~IEngine() {}
		virtual void Run() = 0;
	};

	class TEngineFactory
	{
	public:
		static IEngine* GetEngine(int iWidth, int iHeight, const string& wTitle, RenderSystem eRenderSubSystem);
		static void ReleaseEngine(IEngine* pEngine);

	};
}
