#pragma once
#include "TEngine.h"

class Scene : public TEngine::IScene
{
public:
	Scene();
	virtual ~Scene();

	virtual TEngine::IEntity* CreateEntity() override;
	virtual void Destroy(TEngine::IEntity* pEntity) override;

};

