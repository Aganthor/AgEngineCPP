#include "WorldMapGenerator.hpp"

#include <limits>

#include "../utility/random.hpp"

namespace map
{
	WorldMapGenerator::WorldMapGenerator()
	{
	}
	//
	// Constructor with only the width and height. The callee should ensure
	// that all other variables are set.
	//
	WorldMapGenerator::WorldMapGenerator(int width, int height) : BaseMapGenerator{ width, height }
	{
		Random::init();
		setOffset();
	}

	//
	// All around constructor. Everything is set to generate a map.
	//
	WorldMapGenerator::WorldMapGenerator(int width, int height, int seed, 
		float scale, int octaves,
		float persistance, float lacunarity, sf::Vector2f offset) :
		BaseMapGenerator{ width, height }, 
		m_seed{ seed }, m_scale{ scale }, 
		m_octaves{ octaves }, m_persistance{ persistance }, 
		m_lacunarity{ lacunarity }, m_offset{offset}
	{
		Random::init();
		setOffset();
	}

	//
	// Empty for now...
	//
	WorldMapGenerator::~WorldMapGenerator()
	{

	}

	//
	// Will generate the map. It is the caller's duty to setup the diffent parameters before calling
	// generateMap.
	//
	void WorldMapGenerator::generateMap()
	{
		//Use simplex noise to generate our map.
		m_myNoise.SetNoiseType(FastNoise::Simplex);

		std::vector<sf::Vector2f> octaveOffsets;
		octaveOffsets.resize(m_octaves);

		for (int i = 0; i < m_octaves; ++i)
		{
			float offsetX = Random::floatInRange(-10000, 10000) + m_offset.x;
			float offsetY = Random::floatInRange(-10000, 10000) + m_offset.y;
			octaveOffsets[i].x = offsetX;
			octaveOffsets[i].y = offsetY;
		}

		if (m_scale <= 0)
			m_scale = 0.0001f;

		float maxNoiseHeight = std::numeric_limits<float>::min();
		float minNoiseHeight = std::numeric_limits<float>::max();

		float halfWidth = static_cast<float>(m_mapWidth / 2);
		float halfHeight = static_cast<float>(m_mapHeight / 2);

		for (int y = 0; y < m_mapHeight; ++y)
		{
			for (int x = 0; x < m_mapWidth; ++x)
			{
				float amplitude = 1.0f;
				float frequency = 1.0f;
				float noiseHeight = 0.0f;

				for (int i = 0; i < m_octaves; ++i)
				{
					float sampleX = (x - halfWidth) / m_scale * frequency + octaveOffsets[i].x;
					float sampleY = (y - halfHeight) / m_scale * frequency + octaveOffsets[i].y;

					float simplexValue = m_myNoise.GetNoise(sampleX, sampleY) * 2 - 1;
					noiseHeight += simplexValue * amplitude;

					amplitude *= m_persistance;
					frequency *= m_lacunarity;
				}

				if (noiseHeight > maxNoiseHeight)
				{
					maxNoiseHeight = noiseHeight;
				}
				else if (noiseHeight < minNoiseHeight)
				{
					minNoiseHeight = noiseHeight;
				}
				m_mapData[y * m_mapWidth + x] = noiseHeight;
			}
		}

		for (int y = 0; y < m_mapHeight; ++y)
		{
			for (int x = 0; x < m_mapWidth; ++x)
			{
				m_mapData[y * m_mapWidth + x] = inverseLerp(minNoiseHeight, maxNoiseHeight, m_mapData[y * m_mapWidth + x]);
			}
		}
	}
}//namespace map