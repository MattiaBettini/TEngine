#pragma once
#include "TEngineLib.h"

class Engine : public TEngine::IEngine
{
public:
	Engine(int iWidth, int iHeight, const wstring& wTitle, TEngine::RenderSystem eSystem);
	virtual ~Engine();
private:
	
};


