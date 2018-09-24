#include "stdafx.h"
#include "TEngine.h"
#include "Engine.h"

TEngine::IEngine* TEngine::TEngineFactory::m_pEngineInstance = nullptr;

TEngine::IEngine* TEngine::TEngineFactory::GetEngine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eRenderSubSystem)
{
	if (!m_pEngineInstance)
		m_pEngineInstance = new Engine(iWidth, iHeight, sTitle, eRenderSubSystem);

	return m_pEngineInstance;
}

void TEngine::TEngineFactory::ReleaseEngine()
{
	delete m_pEngineInstance;
	m_pEngineInstance = nullptr;
	//Rendere IEngine un oggetto non allocabile su stack
	//ed implementare la logica di distruzione qui dentro
	/*delete pEngine;*/
}
