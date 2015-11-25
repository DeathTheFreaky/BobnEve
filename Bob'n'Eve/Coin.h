#pragma once
#include "Enemy.h"

class Coin :
	public Enemy
{
public:
	Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId = -1);
	~Coin();

	virtual void Kill() override;
protected:
};

