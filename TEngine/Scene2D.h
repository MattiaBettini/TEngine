#pragma once
#include "Scene.h"

class Scene2D : public Scene
{
public:
	Scene2D(Engine* engine);
	virtual ~Scene2D();

	virtual void Init() override;

};

