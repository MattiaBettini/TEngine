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
	};

	class TEngineFactory
	{
	public:
		static IEngine* GetEngine(int iWidth, int iHeight, const wstring& wTitle, RenderSystem eRenderSubSystem);
		static void ReleaseEngine(IEngine* pEngine);

	};
}
