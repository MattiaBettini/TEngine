#pragma once
#include "TEngine.h"

class Entity;

class Scene : public TEngine::IScene
{

public:
	Scene();
	virtual ~Scene();

	virtual TEngine::IEntity* CreateEntity() override;
	virtual void Destroy(TEngine::IEntity* pEntity) override;

	//not exposed from the API
	void DeferredAddEntities();
	void DeferredRemoveEntities();
	void PreUpdate();
	void Update();
	void PostUpdate();
	void ParallelPreUpdate();
	void ParallelUpdate();
	void ParallelPostUpdate();
	void Render();

private:
	//creazione distruzione deferred (Deferred Execution)
	std::list<Entity*> m_lEntities;
	std::vector<Entity*> m_vToAddEntities;
	std::vector<Entity*> m_vToRemoveEntities;
};

