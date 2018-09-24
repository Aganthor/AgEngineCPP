#pragma once

#include <vector>
#include <string>
#include <map>

#include <noise/noise.h>

namespace map
{

class WorldMap
{
public:
  WorldMap();
  ~WorldMap();

  void generateMap();
  bool LoadMap(const std::string& file);

  void setBaseFreq(float f)  { m_baseFrequency = f; }
  void setFlatScale(float f)  { m_flatScale = f; }
  void setFlatBias(float f)  { m_flatBias = f; }
  void setPerlinFreq(float f)  { m_perlinFreq = f; }
  void setPerlinPers(float f)  { m_perlinPers = f; }

  float getValueAt(int x, int y) { return m_finalTerrain.GetValue(x, y, 0); }

private:
  float m_baseFrequency;
  float m_flatScale;
  float m_flatBias;
  float m_perlinFreq;
  float m_perlinPers;

  noise::module::RidgedMulti m_mountainTerrain;
  noise::module::Billow m_baseFlatTerrain;
  noise::module::ScaleBias m_flatTerrain;
  noise::module::Perlin m_terrainType;
  noise::module::Select m_terrainSelector;
  noise::module::Turbulence m_finalTerrain;
};

}
