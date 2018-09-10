#include "stdafx.h"
#include "Scene.h"
#include "Entity.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

TEngine::IEntity* Scene::CreateEntity()
{
	return new Entity();
}

void Scene::Destroy(TEngine::IEntity* pEntity)
{
	delete pEntity;
}
