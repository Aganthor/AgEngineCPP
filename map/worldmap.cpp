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
  //  module::Perlin myModule;
  utils::NoiseMap heightMap;
  utils::NoiseMapBuilderPlane heightMapBuilder;

  module::RidgedMulti mountainTerrain;
  module::Billow baseFlatTerrain;
  module::ScaleBias flatTerrain;

  baseFlatTerrain.SetFrequency(2.0);

  flatTerrain.SetSourceModule(0, baseFlatTerrain);
  flatTerrain.SetScale(0.125);
  flatTerrain.SetBias(-0.75);

  module::Perlin terrainType;
  terrainType.SetFrequency(0.5);
  terrainType.SetPersistence(0.25);

  module::Select terrainSelector;

  terrainSelector.SetSourceModule(0, flatTerrain);
  terrainSelector.SetSourceModule(1, mountainTerrain);
  terrainSelector.SetControlModule(terrainType);
  terrainSelector.SetBounds(0.0, 1000.0);
  terrainSelector.SetEdgeFalloff(0.125);

  module::Turbulence finalTerrain;
  finalTerrain.SetSourceModule(0, terrainSelector);
  finalTerrain.SetFrequency(4.0);
  finalTerrain.SetPower(0.125);

  heightMapBuilder.SetSourceModule(terrainSelector);
  heightMapBuilder.SetDestNoiseMap(heightMap);
  heightMapBuilder.SetDestSize(800, 600);
  heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
  heightMapBuilder.Build();

  utils::RendererImage renderer;
  utils::Image image;

  renderer.SetSourceNoiseMap(heightMap);
  renderer.SetDestImage(image);
  renderer.ClearGradient ();
  renderer.AddGradientPoint ( 0.1250, utils::Color ( 32, 160,   0, 255)); // grass
  renderer.AddGradientPoint ( 0.3750, utils::Color (224, 224,   0, 255)); // dirt
  renderer.AddGradientPoint ( 0.7500, utils::Color (128, 128, 128, 255)); // rock
  renderer.AddGradientPoint ( 1.0000, utils::Color (255, 255, 255, 255)); // snow
  renderer.EnableLight();
  renderer.SetLightContrast(3.0);
  renderer.SetLightBrightness(2.0);
  renderer.Render();

  utils::WriterBMP writer;
  writer.SetSourceImage(image);
  writer.SetDestFilename("worldmap.bmp");
  writer.WriteDestFile();
}

bool WorldMap::LoadMap(const std::string& file)
{
  return true;
}

}
