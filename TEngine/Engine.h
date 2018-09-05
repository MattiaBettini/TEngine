#pragma once
#include "TEngine.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <GL/GL.h>
#include "EngineException.h"

namespace TEngine 
{
	class Engine final : public IEngine
	{
	public:
		Engine(int iWidth, int iHeight, const string& sTitle, RenderSystem eSystem);

		virtual void Run() override;

	private:
		virtual ~Engine();

		GLFWwindow* m_pWindow;
	};
}