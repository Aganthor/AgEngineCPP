#pragma once

#include <vector>

namespace map
{
	//
	// Base abstract class for our generator family of classes.
	//
	class BaseMapGenerator
	{
	public:
		BaseMapGenerator() {}
		BaseMapGenerator(int w, int h) : m_mapWidth{ w }, m_mapHeight{ h } 
		{
			m_mapData.resize(m_mapWidth * m_mapHeight);
		}
		virtual ~BaseMapGenerator() {}

		virtual void generateMap() = 0;

		int getMapWidth() const { return m_mapWidth; }
		int getMapHeight() const { return m_mapHeight; }
		void setMapWidth(int w) { m_mapWidth = w; }
		void setMapHeight(int h) { m_mapHeight = h; }

		inline float getValueAt(int x, int y)
		{
			return m_mapData[y * m_mapWidth + x];
		}

	protected:
		std::vector<float> m_mapData;
		int m_mapWidth;
		int m_mapHeight;
	};
}
