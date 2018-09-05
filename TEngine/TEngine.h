#pragma once

#include <string>

using namespace std;

//compiler switch
#if BUILDING_DLL //c++/preprocessor
	#define TEngineAPI _declspec(dllexport)
#else
	#define TEngineAPI _declspec(dllimport)
#endif

//extern "C" string TEngineAPI GetTestString();

namespace TEngine
{
	enum RenderSystem
	{
		OpenGl = 1,
		Vulkan = 2
	};

	class TEngineAPI IEngine
	{
	public:
		virtual ~IEngine() {}
		virtual void Run() = 0;
	};

	class TEngineAPI TEngineFactory
	{
		friend class Engine;

	public:
		static IEngine* GetEngine(int iWidth, int iHeight, const string& wTitle, RenderSystem eRenderSubSystem);
		static void ReleaseEngine(IEngine* pEngine);
	};
}