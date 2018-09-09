#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <unordered_map>
#include <typeinfo>

#include "Entity.h"
#include "Component.h"

namespace ecs
{
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		std::uint32_t generateNewID();
		std::shared_ptr<Entity> createEntity();

		template <typename ComponentType, typename EntityType>
		void addComponent(ComponentType* component, EntityType* entity);



		void RemoveEntity(std::uint32_t eid);


	private:
		std::uint32_t m_lowestUnassignedID = 1;
		std::vector<std::unique_ptr<Entity>> m_entities;

		///////////////////////////////////////////////////////////////////////
		// 
		///////////////////////////////////////////////////////////////////////
		std::unordered_map<std::uint32_t, std::vector<std::unique_ptr<Component>>> m_Entities;
	};
}