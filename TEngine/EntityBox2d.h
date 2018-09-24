#pragma once
#include "Entity.h"

class EntityBox2d : public Entity
{
public:
	EntityBox2d(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);
	virtual ~EntityBox2d();

private:
	GLfloat m_fX0;
	GLfloat m_fX1;
	GLfloat m_fY0;
	GLfloat m_fY1;
	GLfloat m_fRed;
	GLfloat m_fGreen;
	GLfloat m_fBlue;
};

