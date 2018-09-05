// TEngine.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "TEngine.h"

TEngine::IEngine* TEngine::TEngineFactory::GetEngine(int iWidth, int iHeight, const string& wTitle, TEngine::RenderSystem eRenderSubSystem)
{
	return (IEngine*)new int[500];
}

void TEngine::TEngineFactory::ReleaseEngine(TEngine::IEngine* pEngine)
{
	delete[](void*)pEngine;
	//Rendere IEngine un oggetto non allocabile su stack
	//ed implementare la logica di distruzione qui dentro
	/*delete pEngine;*/
}

