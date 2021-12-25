#pragma once

#include "Protocol.h"
#include "Unit.h"
#include <vector>

class MyGameApp : public Protocol::ProtocolApp {
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Protocol::KeyPressedEvent& event) override;

private:
	Unit mHero;
	Unit mPoints;
	std::vector<Unit> mViruses;
	std::vector<Unit> mPowerUps;
	std::vector<Unit> mHealthPowerUp;
	std::vector<Unit> mVaccinePowerUp;
	std::vector<Unit> mSpeedPowerUp;
	std::vector<Unit> mProjectiles;
	int mFrameCounter;
	int mDefensePoints;
	int mHeroLevel;
	bool mGameOver;
	int mShooting;
	bool mShot;
	int mShotTime;
	Protocol::Shader mShader;
};
