#pragma once

#include "TileType.hpp"

namespace map
{
	//
	// A tile struct to represent information for a particular tile on the map.
	//
	struct TileInfo
	{
		int x, y;
		TileType tileType;
		bool explored;
		bool blockView;
		bool walkable;
		TileInfo(int t_x, int t_y, TileType t_type,
			bool t_explored, bool t_blockview, bool t_walkable) :
			x{ t_x }, y{ t_y }, tileType{ t_type }, explored{ t_explored },
			blockView{ t_blockview }, walkable{ t_walkable }{}
	};
} // end of namespace map
