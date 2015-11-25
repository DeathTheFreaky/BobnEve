#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include <vector>
#include <cinttypes>
#include <assert.h>

class PhysicBodyDynamic;
class PhysicBodyStatic;
struct PhysicBodyDef;
class CollisionResolver;

class PhysicBodyBase
{
	friend class PhysicWorld;
public:
	inline Vector2f GetPosition() const
	{
		return bounds_.center;
	};
	inline Vector2f GetSize() const
	{
		return bounds_.halfSize;
	};
	inline const FloatRect& GetBounds() const
	{
		return bounds_;
	};
	inline const Vector2f& GetVelocity() const
	{
		return velocity_;
	};
	bool IsColliding(const PhysicBodyBase& otherBody) const;
	void AddCollisionIgnoreGroup(int8_t group);
	void RemoveCollisionIgnoreGroup(int8_t group);
	bool IsInGroup(int8_t group) const;

	virtual void CollideWith(PhysicBodyBase& otherBody) = 0;
	virtual void CollideWithStatic(PhysicBodyStatic& otherBody) = 0;
	virtual void CollideWithDynamic(PhysicBodyDynamic& otherBody) = 0;

	virtual void SetVelocity(const Vector2f& velocity) = 0;
	virtual void SetPhysicScale(float scale) = 0;

protected:
	explicit PhysicBodyBase(const PhysicBodyDef& def);
	virtual ~PhysicBodyBase();

	virtual void Move(const Vector2f& gravity, float seconds) = 0;

	bool InSameIgnoreGroup(const PhysicBodyBase& otherBody) const;
	Vector2f velocity_;
	Vector2f realVelocity_;
	FloatRect bounds_;
	float physicScale_;
	std::vector<int8_t> collisionIgnorGroups_;
};

class PhysicBody
{
public:
	enum Type{
		STATIC,
		DYNAMIC
	};
};