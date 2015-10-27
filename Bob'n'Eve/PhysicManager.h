#pragma once

#include <Box2D/Dynamics/b2World.h>

class Player;

class PhysicManager
{
public:
	PhysicManager(float gravityX, float gravityY);
	virtual ~PhysicManager();

	void RegisterEntity(Player& player, b2BodyDef* bodyDef);
private:
	b2World world_;
};

