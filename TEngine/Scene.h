#pragma once
#include "TEngine.h"

class Entity;
class Engine;

class Scene : public TEngine::IScene
{

public:
	Scene(Engine* engine);
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
	virtual void Init() = 0;

private:
	//creazione distruzione deferred (Deferred Execution)
	std::list<Entity*> m_lEntities;
	std::vector<Entity*> m_vToAddEntities;
	std::vector<Entity*> m_vToRemoveEntities;

protected:
	Engine* m_pEngine;
};

