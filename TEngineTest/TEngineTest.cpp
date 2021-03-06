#include "pch.h"
#pragma comment(lib, "..\\x64\\Debug\\TEngine.lib")
//LOAD-TIME LINKING
// diamo per scontato la presenza dell' header
//carica tutta la dll / va bene per le piccole
//#pragma comment(lib, "..\\x64\\Debug\\TEngine.lib")

#include "..\\TEngine\\TEngine.h"
#include <thread>

using namespace std;
using namespace TEngine;

//runtime dynamic linking
//creare la definizione delle funzioni (che dovrebbero essere note)
//typedef string(CALLBACK* GetTestString)();

int main()
{
	
	TEngineFactory::CreateEngine(1280, 720, "Exported Engine Instance", RenderSystem::OpenGl);
	IEngine* pEngine = TEngineFactory::GetEngine();
	pEngine->Run();

	//IScene* pCurrentScene = pEngine->CreateScene();
	//pCurrentScene->CreateEntity();
	//pCurrentScene->CreateEntity();

	system("PAUSE");

	TEngineFactory::ReleaseEngine();


	_CrtDumpMemoryLeaks();	
	
	
	//cout << GetTestString();
	//carica a runtime e su richiesta / va bene per le dll grandi con risorse
	//HINSTANCE hDll = LoadLibraryA("TEngine.dll");

	////indirizzo di memoria dumpbin 
	//GetTestString pGetTestStringPtr = (GetTestString)GetProcAddress(hDll, "GetTestString");
	//string result = pGetTestStringPtr();

	//cout << result << endl;
	/*IEngine* pEngine = nullptr;

	try
	{
		pEngine = TEngineFactory::GetEngine(640, 480, "Test Engine", RenderSystem::OpenGl);
		pEngine->Run();
	}
	catch (const std::exception&)
	{

	}
	
	TEngineFactory::ReleaseEngine(pEngine);

	_CrtDumpMemoryLeaks();*/

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

