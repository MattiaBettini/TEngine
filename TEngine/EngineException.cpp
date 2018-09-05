#include "stdafx.h"
#include "EngineException.h"


glfwCreateWindowException::glfwCreateWindowException()
{
}


glfwCreateWindowException::~glfwCreateWindowException()
{
}

char const* glfwCreateWindowException::what() const
{
	return "GLFW Window not created";
}

//////////////////////////////////////////////////////////////////////////

glfwInitException::glfwInitException()
{

}

glfwInitException::~glfwInitException()
{

}

char const* glfwInitException::what() const
{
	return "GLFW Init fail";
}
