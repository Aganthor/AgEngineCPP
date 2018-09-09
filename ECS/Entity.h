#pragma once

#include <cstdint>

namespace ecs
{
	//A generic entity object represented with an unsigned int.
	class Entity
	{
	public:
		Entity() = delete;
		Entity(uint32_t id) : m_ID(id) {};
		~Entity() {};

		const uint32_t getID() const { return m_ID; }

	private:
		uint32_t m_ID;
	};
}
