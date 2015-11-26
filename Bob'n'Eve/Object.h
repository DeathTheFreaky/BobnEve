#pragma once
#include <cstdint>
#include "Vector2f.h"
#include "Tile.h"

class Object
{
	friend class MapLoader;

private:
	inline Object() {}
	inline ~Object() {}

	const Tile* tile;
	const TileSet* tileSet;

	size_t id = -1;
	int8_t gravity = 0;
	Vector2f pos, size;
	size_t enemyId = -1;
	const char* type;
	Vector2f speed = Vector2f(0, 0);
};
