#pragma once

#include <string>
#include <atomic>
#include <queue>

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

	class TEngineAPI IEntity
	{
	public:
		virtual ~IEntity() {};
		//tutti i metodi di controllo

	};

	class TEngineAPI IScene //non allocabile su stack
	{
	public:
		virtual ~IScene() {};
		virtual IEntity* CreateEntity() = 0;
		virtual void Destroy(IEntity* pEntity) = 0;
	};

	class TEngineAPI IEngine
	{
	public:
		virtual ~IEngine() {}
		virtual void Run() = 0;
		virtual void Stop() = 0;
		virtual IScene* CreateScene() = 0;
		virtual void Destroy(IScene* pScene) = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual string GetTitle() = 0;
		virtual double GetDeltaTime() = 0;
		virtual void Log(const string& message) = 0;
	};

	class TEngineAPI TEngineFactory
	{
		//friend class Engine;

	public:
		static IEngine* GetEngine(int iWidth, int iHeight, const string& wTitle, RenderSystem eRenderSubSystem);
		static void ReleaseEngine();

	private:
		static IEngine* m_pEngineInstance;
	};

}