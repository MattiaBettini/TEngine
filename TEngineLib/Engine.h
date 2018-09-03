#pragma once
#include "TEngineLib.h"
#include "GLFW/glfw3.h"

class Engine : public IEngine
{
public:
	Engine(int iWidth, int iHeight, const wstring& wTitle, RenderSystem eSystem);
	virtual ~Engine();
private:
	
};


