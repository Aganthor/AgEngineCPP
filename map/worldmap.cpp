#include "worldmap.h"

#include "../noiseutils/noiseutils.h"

using namespace noise;


namespace map
{

WorldMap::WorldMap() : m_baseFrequency{2.0}, m_flatScale{0.125}, m_flatBias{-0.75},
                       m_perlinFreq{0.5}, m_perlinPers{-0.25}
{
}

WorldMap::~WorldMap()
{
}

void WorldMap::generateMap()
{
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;

  m_baseFlatTerrain.SetFrequency(m_baseFrequency);

  m_flatTerrain.SetSourceModule(0, m_baseFlatTerrain);
  m_flatTerrain.SetScale(m_flatScale);
  m_flatTerrain.SetBias(m_flatBias);

  m_terrainType.SetFrequency(m_perlinFreq);
  m_terrainType.SetPersistence(m_perlinPers);
  m_terrainType.SetSeed(6);

  m_terrainSelector.SetSourceModule(0, m_flatTerrain);
  m_terrainSelector.SetSourceModule(1, m_mountainTerrain);
  m_terrainSelector.SetControlModule(m_terrainType);
  m_terrainSelector.SetBounds(0.0, 1000.0);
  m_terrainSelector.SetEdgeFalloff(0.125);

  m_finalTerrain.SetSourceModule(0, m_terrainSelector);
  m_finalTerrain.SetFrequency(4.0);
  m_finalTerrain.SetPower(0.25);

  heightMapBuilder.SetSourceModule(m_finalTerrain);
  heightMapBuilder.SetDestNoiseMap(heightMap);
  heightMapBuilder.SetDestSize(800, 600);
  heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
  heightMapBuilder.Build();

  utils::RendererImage renderer;

  utils::Image image;

  renderer.SetSourceNoiseMap(heightMap);
  renderer.SetDestImage(image);
  renderer.ClearGradient ();
  renderer.AddGradientPoint (-0.6000, utils::Color (  0,   0, 128, 255)); // deeps
  renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 255, 255)); // shallow
  renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255, 255)); // shore
  renderer.AddGradientPoint ( 0.0625, utils::Color (240, 240,  64, 255)); // sand
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
