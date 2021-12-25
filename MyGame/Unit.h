#pragma once

#include "Protocol.h"
class Unit
{
public:
	Unit() = delete;
	Unit(const std::string& imageFile, int xPos, int yPos, int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	void SetSpeed(int newSpeed);
	void SetImage(const std::string& imageFile);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;

	//returns true if this unit collides with another unit
	bool CollideWith(const Unit& other) const;

	void Draw(Protocol::Shader& shader);
	enum class Direction {
		None,
		Up,
		Down,
		Left,
		Right
	};

	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);

	void UpdatePosition();


private:
	bool IsPositionPossible(int newX, int newY) const;

	Protocol::Sprite mImage;
	int mPosX;
	int mPosY;
	int mSpeed;

	Direction mDirection;
};