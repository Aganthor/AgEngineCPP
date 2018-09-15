#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include <bitset>
#include <array>

namespace ecs
{
//Some forward declare...
class EntityManager;
class Component;

////////////////////////////////////////////////////////////////////////////////
// Some helper functions for getting unique component id.
////////////////////////////////////////////////////////////////////////////////
using ComponentID = std::size_t;
using GroupID = std::size_t;

namespace Internal
{
inline ComponentID getUniqueComponentID() noexcept
{
  static ComponentID lastID{0u};
  return lastID++;
}
}

template<typename T>
inline ComponentID getComponentTypeID() noexcept
{
  static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

  static ComponentID typeID{Internal::getUniqueComponentID()};
  return typeID;
}

//Here we have a bitset and an array of maxComponents size.
//The bitset is used to indicate whether or not our Entity has a component of not.
constexpr std::size_t maxComponents{32};
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

//Do we want to group entities together? Add them in the group and set the bit set
//accordingly.
//TODO: not sure if I need it or not.
// constexpr std::size_t maxGroups{32};
// using GroupBitset = std::bitset<maxGroups>;

// class Entity
// {
//  public:
//   //Entity(EntityManager& mManager) : m_Manager(mManager) {}

//   template<typename T>
//   bool hasComponent() const
//   {
//     // return m_ComponentBitset[
//     return true;
//   }

//  private:
//   // EntityManager m_Manager;
//   // std::Vector<std::unique_ptr<Component>> m_Components;
//   // ComponentArray m_ComponentArray;
//   // ComponentBitset m_ComponentBitset;

//   //GroupBitset m_GroupBitset;

// };
}
