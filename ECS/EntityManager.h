#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <unordered_map>
#include <typeinfo>
#include <utility>

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
  //std::shared_ptr<Entity> createEntity();

  template<typename T, typename... TArgs>
  T& addComponent(TArgs&&... mArgs)
  {
    T* c(new T(std::forward<TArgs>(mArgs)...));

    return *c;
  }


  void RemoveEntity(std::uint32_t eid);


 private:
  std::uint32_t m_lowestUnassignedID = 1;
  // std::vector<std::unique_ptr<Entity>> m_entities;

  // ///////////////////////////////////////////////////////////////////////
  // //
  // ///////////////////////////////////////////////////////////////////////
  // std::unordered_map<std::uint32_t, std::vector<std::unique_ptr<Component>>> m_Entities;
};
}
