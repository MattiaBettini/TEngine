#include "stdafx.h"
#include "MessageSetWindowSize.h"
#include "Engine.h"
#include "Scene.h"
#include "TEngine.h"

using namespace TEngine;

MessageSetWindowSize::MessageSetWindowSize()
{
}


MessageSetWindowSize::~MessageSetWindowSize()
{
}

void MessageSetWindowSize::Execute()
{
	TEngine::IEngine* pEngine = dynamic_cast<TEngine::IEngine*>(m_pEngine);
	Scene* pScene = dynamic_cast<Scene*>(pEngine->GetCurrentScene());
	pScene->Init();
}

void MessageSetWindowSize::Set(int w, int h)
{
	m_pEngine->RegisterRenderer(this);
}
