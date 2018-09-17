#pragma once

#include <vector>
#include <string>
#include <map>

namespace map
{

class WorldMap
{
public:
  WorldMap();
  ~WorldMap();

  void generateMap();
  bool LoadMap(const std::string& file);
};

}
