#pragma once

class glfwCreateWindowException : public std::exception
{
public:
	glfwCreateWindowException();
	virtual ~glfwCreateWindowException();

	virtual char const* what() const override;

};

class glfwInitException : public std::exception
{
public:
	glfwInitException();
	virtual ~glfwInitException();

	virtual char const* what() const override;

};

