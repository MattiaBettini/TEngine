#include "stdafx.h"
#include "Scene.h"
#include "Entity.h"
#include "Engine.h"


Scene::Scene(Engine* engine)
{
	m_pEngine = engine;
}


Scene::~Scene()
{
}

TEngine::IEntity* Scene::CreateEntity()
{
	Entity* pTmp = new Entity(this);
	m_vToAddEntities.push_back(pTmp);

	return pTmp;
}

void Scene::Destroy(TEngine::IEntity* pEntity)
{
	Entity* pTmp = dynamic_cast<Entity*>(pEntity);
	m_vToRemoveEntities.push_back(pTmp);
}

void Scene::DeferredAddEntities()
{
	for (int i = 0; i < m_vToAddEntities.size(); i++)
	{
		Entity* pTmp = m_vToAddEntities[i];
		m_lEntities.push_back(pTmp);
		pTmp->m_itPosition = m_lEntities.end();
	}

	m_vToAddEntities.clear();
}

void Scene::DeferredRemoveEntities()
{
	for (int i = 0; i < m_vToRemoveEntities.size(); i++)
	{
		Entity* pTmp = m_vToRemoveEntities[i];
		m_lEntities.erase(pTmp->m_itPosition);
		delete pTmp;
	}
	m_vToRemoveEntities.clear();
}

void Scene::PreUpdate()
{

}

void Scene::Update()
{
	//for_each(m_pEntities.begin(), m_pEntities.end(), []() {})
	for (auto it = m_lEntities.begin(); it != m_lEntities.end(); it++)
	{
		(*it)->Update();
	}
}

void Scene::PostUpdate()
{

}

void Scene::ParallelPreUpdate()
{

}

void Scene::ParallelUpdate()
{

}

void Scene::ParallelPostUpdate()
{

}

void Scene::Render()
{
	//glViewport(0, 0, m_pEngine->GetWidth(), m_pEngine->GetHeight());
}
