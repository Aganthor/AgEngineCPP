#pragma once

#include <vector>
#include <string>
#include <map>

namespace map
{

class Map
{
public:
  Map();
  ~Map();

  void generateMap();
  bool LoadMap(const std::string& file);
};

}
