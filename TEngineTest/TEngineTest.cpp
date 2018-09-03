#include "pch.h"
#pragma comment(lib, "..\\x64\\Debug\\TEngineLib.lib")

using namespace std;
using namespace TEngine;

int main()
{
	IEngine* pEngine = nullptr;

	try
	{
		pEngine = TEngineFactory::GetEngine(640, 480, "Test Engine", RenderSystem::OpenGl);
		pEngine->Run();
	}
	catch (const std::exception&)
	{

	}
	
	TEngineFactory::ReleaseEngine(pEngine);

	_CrtDumpMemoryLeaks();

	//GLFWwindow* window;
	//
	//if (!glfwInit())
	//	return -1;

	//window = glfwCreateWindow(640, 480, "Main Engine Window" , NULL, NULL);
	//if (!window)
	//{
	//	glfwTerminate();
	//	return -1;
	//}

	//glfwMakeContextCurrent(window);

	//GLenum err = glewInit();

	//if (GLEW_OK != err)
	//{
	//	fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	//}
	//fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	//
	//while (!glfwWindowShouldClose(window))
	//{	
	//	/* Render here */
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	/* Swap front and back buffers */
	//	glfwSwapBuffers(window);

	//	/* Poll for and process events */
	//	glfwPollEvents();
	//}

	//glfwTerminate();

	return 0;
}


