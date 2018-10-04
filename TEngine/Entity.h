#pragma once
#include "TEngine.h"

class Scene;

class Entity : public TEngine::IEntity
{
	friend class Scene;

public:
	Entity();
	Entity(Scene* scene);
	virtual ~Entity();

	void virtual PreUpdate();
	void virtual Update();
	void virtual PostUpdate();

private:
	Scene* m_pParentScene;
	list<Entity*>::iterator m_itPosition;
};

