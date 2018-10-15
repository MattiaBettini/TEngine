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
		virtual void SetCurrentScene(IScene* pScene) = 0;
		virtual TEngine::IScene* GetCurrentScene() = 0;
		virtual void Destroy(IScene* pScene) = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual void GetWindowSize(int* iWidth, int* iHeight) = 0;
		virtual string GetTitle() = 0;
		virtual double GetDeltaTime() = 0;
	};

	class TEngineAPI TEngineFactory
	{
		//friend class Engine;

	public:
		static void CreateEngine(int iWidth, int iHeight, const string& wTitle, RenderSystem eRenderSubSystem);
		static IEngine* GetEngine();
		static void ReleaseEngine();

	private:
		static IEngine* m_pEngineInstance;
	};

}