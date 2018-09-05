// TEngine.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "TEngine.h"
#include "Engine.h"

TEngine::IEngine* TEngine::TEngineFactory::GetEngine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eRenderSubSystem)
{
	return new Engine(iWidth, iHeight, sTitle, eRenderSubSystem);
}

void TEngine::TEngineFactory::ReleaseEngine(TEngine::IEngine* pEngine)
{
	delete pEngine;
	//Rendere IEngine un oggetto non allocabile su stack
	//ed implementare la logica di distruzione qui dentro
	/*delete pEngine;*/
}

