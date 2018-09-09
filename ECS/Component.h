#pragma once

#include <string>
///////////////////////////////////////////////////////////////////////////////
// Component base class. Entirely empty. Subclasses will specialize.
///////////////////////////////////////////////////////////////////////////////

namespace ecs
{
	class Component
	{
	public:
		Component() {};
		Component(const std::string& name) : m_ComponentName{ name } {};
		~Component() {};

		const std::string& getName(void) const { return m_ComponentName; }

	private:
		std::string m_ComponentName;
	};
}