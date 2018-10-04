#include "stdafx.h"
#include "Scene2D.h"
#include "Engine.h"


Scene2D::Scene2D(Engine* engine) : Scene(engine)
{

}


Scene2D::~Scene2D()
{

}

void Scene2D::Init()
{
	// GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    int height;
	int width;

	m_pEngine->GetWindowSize(&width, &height);

    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);
 
    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    if (width >= height) {
      // aspect >= 1, set the height from -1 to 1, with larger width
       glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, -1.0f, 1.0f);
    } else {
       // aspect < 1, set the width to -1 to 1, with larger height
      glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0f, 1.0f);
    }
}

