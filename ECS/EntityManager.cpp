#include "EntityManager.h"

#include <algorithm>

/*
Voici comment j'aimerais créer mes entités:
Entity e = createEntity();
e->addComponent(RenderComponent::type_id, args ...)
e->addComponent(HealthComponent::type_id, args ...)

for_each entity with RenderComponent
	do render

for_each entity with healthComponent
	do calcul
*/

namespace ecs
{
	EntityManager::EntityManager()
	{
	}

	EntityManager::~EntityManager()
	{

	}

	//////////////////////////////////////////////////////////////////////////////
	// Will generate an entity ID. Can only have UINT32_MAX entity. If we pass
	// that value, we will cycle the already allocated ID.
	//////////////////////////////////////////////////////////////////////////////
	std::uint32_t EntityManager::generateNewID()
	{
		if (m_lowestUnassignedID < UINT32_MAX)
			return m_lowestUnassignedID++;
		else
		{
			for (auto i = 1; i < UINT32_MAX; ++i)
			{
				auto entity = std::find_if(m_entities.begin(), m_entities.end(), [i](const auto &e) -> bool
				{
					return e->getID() == i;
				});
				if (entity != std::end(m_entities))
					return i;
			}
		}

		//Error... to be logged...
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	std::shared_ptr<Entity> EntityManager::createEntity()
	{
		auto id = generateNewID();
		//m_entities.push_back(id);

		return std::make_shared<Entity>(id);
	}

	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	template <typename ComponentType, typename EntityType>
	void EntityManager::addComponent(ComponentType* component, EntityType* entity)
	{

	}
}
