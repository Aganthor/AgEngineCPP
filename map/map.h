#pragma once

#include <vector>
#include <string>

namespace map
{

class Map
{
public:
  Map();
  ~Map();

  void CreateMap(void);
  bool LoadMap(const std::string& file);

private:

};

}
