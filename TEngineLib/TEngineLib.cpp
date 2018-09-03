// TEngineLib.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "TEngineLib.h"
#include "Engine.h"


TEngine::IEngine* TEngine::TEngineFactory::GetEngine(int iWidth, int iHeight, const wstring& wTitle, RenderSystem eRenderSubSystem)
{	
	return new Engine(iWidth, iHeight, wTitle, eRenderSubSystem);
}

void TEngine::TEngineFactory::ReleaseEngine(IEngine* pEngine)
{
	//Rendere IEngine un oggetto non allocabile su stack
	//ed implementare la logica di distruzione qui dentro
	delete pEngine;
}

