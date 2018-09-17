#include "worldmap.h"

#include <noise/noise.h>
#include "../noiseutils/noiseutils.h"

using namespace noise;


namespace map
{

WorldMap::WorldMap()
{
}

WorldMap::~WorldMap()
{
}

void WorldMap::generateMap()
{
  module::Perlin myModule;
  utils::NoiseMap heightMap;
  utils::NoiseMapBuilderPlane heightMapBuilder;

  heightMapBuilder.SetSourceModule(myModule);
  heightMapBuilder.SetDestNoiseMap(heightMap);
  heightMapBuilder.SetDestSize(256, 256);
  heightMapBuilder.SetBounds(2.0, 6.0, 1.0, 5.0);
  heightMapBuilder.Build();

}

bool WorldMap::LoadMap(const std::string& file)
{
  return true;
}

}
