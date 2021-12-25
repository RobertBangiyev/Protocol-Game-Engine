#include "MyGameApp.h"

MyGameApp::MyGameApp(): mHero("Assets/Textures/hero.png", 0, 0, 15), mPoints("Assets/Textures/10.png", 0, 769, 0),  mFrameCounter(0), mDefensePoints(10), mGameOver(false), mHeroLevel(0), mShooting(false), mShot(false), mShotTime(0)
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}

void MyGameApp::OnUpdate()
{
	if (!mGameOver) {
		mHero.UpdatePosition();

		//update existing viruses
		for (auto& virus : mViruses) {
			virus.UpdatePosition();
		}

		for (auto& health : mHealthPowerUp) {
			health.UpdatePosition();
		}
		for (auto& vaccine : mVaccinePowerUp) {
			vaccine.UpdatePosition();
		}
		for (auto& speed : mSpeedPowerUp) {
			speed.UpdatePosition();
		}
		for (auto& projectile : mProjectiles) {
			projectile.UpdatePosition();
		}

		//introduce new projectile every time hero shoots
		if (mShot && mFrameCounter > mShotTime + (1.5 * FRAMES_PER_SECOND) && mProjectiles.size() < 1) {
			int projX{ mHero.GetPosX() + 5 };
			int projY{ mHero.GetPosY() };
			Unit::Direction projDir = Unit::Direction::Right;
			int projSpeed = 10;
			/*if (mHeroLevel >= 3) {
				projSpeed = 20;
			}*/
			mProjectiles.push_back(Unit{ "Assets/Textures/projectile.png", projX, projY, projSpeed });
			mProjectiles.back().SetDirection(projDir);
			mShotTime = mFrameCounter;
			mShot = false;
		}


		//introduce new powerup every 10.5 seconds
		int necessary = FRAMES_PER_SECOND * 10.5;
		if (mFrameCounter % necessary == 0 && mFrameCounter != 0) {
			int anotherX{ 720 };
			int anotherY{ rand() % 700 };
			Unit::Direction anotherDir = Unit::Direction::Left;
			int powerupType{ rand() % 3 };
			if (powerupType == 0) {
				mHealthPowerUp.push_back(Unit{ "Assets/Textures/health.png", anotherX, anotherY, 10 });
				mHealthPowerUp.back().SetDirection(anotherDir);
			}
			else if (powerupType == 1) {
				mVaccinePowerUp.push_back(Unit{ "Assets/Textures/vaccine.png", anotherX, anotherY, 10 });
				mVaccinePowerUp.back().SetDirection(anotherDir);
			}
			else {
				mSpeedPowerUp.push_back(Unit{ "Assets/Textures/speed.png", anotherX, anotherY, 10 });
				mSpeedPowerUp.back().SetDirection(anotherDir);
			}
		}

		//introduce new virus every second
		if (mFrameCounter % FRAMES_PER_SECOND == 0 && mViruses.size() < 15) {

			//int newX{ rand() % 700 };
			int newX{ 730 };
			int newY{ rand() % 700 };
			int newerY{ rand() % 700 };
			Unit::Direction newDir;
			int dirVal = 2;
			//int dirVal{ rand() % 4 };
			if (dirVal == 0) {
				newDir = Unit::Direction::Down;
			}
			else if (dirVal == 1) {
				newDir = Unit::Direction::Up;
			}
			else if (dirVal == 2) {
				newDir = Unit::Direction::Left;
			}
			else {
				newDir = Unit::Direction::Right;
			}
			mViruses.push_back(Unit{ "Assets/Textures/virus.png", newX, newY, 10 });
			mViruses.back().SetDirection(newDir);
			if (mFrameCounter >= FRAMES_PER_SECOND * 35) {
				mViruses.push_back(Unit{ "Assets/Textures/virus.png", newX, newerY, 10 });
				mViruses.back().SetDirection(newDir);
			}
			if (mFrameCounter >= FRAMES_PER_SECOND * 70) {
				mViruses.push_back(Unit{ "Assets/Textures/virus.png", newX, newerY, 10 });
				mViruses.back().SetDirection(newDir);
			}
		}

		

		//check collisions
		auto it = mViruses.begin();
		while (it != mViruses.end()) {
			if (mViruses.size() != 0) {
				if (mHero.CollideWith(*it)) {
					it = mViruses.erase(it);
				}
				else if (mProjectiles.size() == 1 && mProjectiles[0].CollideWith(*it)) {
					it = mViruses.erase(it);
					mProjectiles.pop_back();
				}
				else if (it->GetPosX() <= 0) {
					it = mViruses.erase(it);
					mDefensePoints--;
					if (mDefensePoints < 0) {
						mDefensePoints = 0;
						mGameOver = true;
					}
					mPoints.SetImage("Assets/Textures/" + std::to_string(mDefensePoints) + ".png");
				}
				else {
					it++;
				}
			}
		}


		if (mProjectiles.size() == 1 && mProjectiles[0].GetPosX() >= (790 - mProjectiles[0].GetUnitWidth())) {
			if (mHeroLevel == 3) {
				std::cout << mProjectiles[0].GetPosX() << std::endl;
			}
			mProjectiles.pop_back();
		}

		auto newIt = mHealthPowerUp.begin();
		while (newIt != mHealthPowerUp.end()) {
			if (mHero.CollideWith(*newIt)) {
				newIt = mHealthPowerUp.erase(newIt);
				mDefensePoints += 5;
				if (mDefensePoints > 20) {
					mDefensePoints = 20;
				}
				mPoints.SetImage("Assets/Textures/" + std::to_string(mDefensePoints) + ".png");
			}
			else if (newIt->GetPosX() <= 0) {
				newIt = mHealthPowerUp.erase(newIt);
			}
			else {
				newIt++;
			}
		}

		auto anotherIt = mSpeedPowerUp.begin();
		while (anotherIt != mSpeedPowerUp.end()) {
			if (mHero.CollideWith(*anotherIt)) {
				anotherIt = mSpeedPowerUp.erase(anotherIt);
				mHero.SetSpeed(mHero.GetSpeed() + 5);
			}
			else if (anotherIt->GetPosX() <= 0) {
				anotherIt = mSpeedPowerUp.erase(anotherIt);
			}
			else {
				anotherIt++;
			}
		}

		auto moreIt = mVaccinePowerUp.begin();
		while (moreIt != mVaccinePowerUp.end()) {
			if (mHero.CollideWith(*moreIt)) {
				moreIt = mVaccinePowerUp.erase(moreIt);
				if (mHeroLevel <= 2) {
					mHeroLevel++;
					mHero.SetImage("Assets/Textures/hero" + std::to_string(mHeroLevel) + ".png");
				}
				else {
					mDefensePoints += 3;
					if (mDefensePoints > 20) {
						mDefensePoints = 20;
					}
					mPoints.SetImage("Assets/Textures/" + std::to_string(mDefensePoints) + ".png");
				}
			}
			else if (moreIt->GetPosX() <= 0) {
				moreIt = mVaccinePowerUp.erase(moreIt);
			}
			else {
				moreIt++;
			}
		}

		for (auto& virus : mViruses) {
			virus.Draw(mShader);
		}
		for (auto& health : mHealthPowerUp) {
			health.Draw(mShader);
		}
		for (auto& vaccine : mVaccinePowerUp) {
			vaccine.Draw(mShader);
		}
		for (auto& speed : mSpeedPowerUp) {
			speed.Draw(mShader);
		}
		for (auto& projectile : mProjectiles) {
			projectile.Draw(mShader);
		}

		mHero.Draw(mShader);
		mPoints.Draw(mShader);

		mFrameCounter++;
	}
	else {
		mPoints.SetImage("Assets/Textures/gameover.png");
		mPoints.SetPosX(400 - mPoints.GetUnitWidth()/2);
		mPoints.SetPosY(400 - mPoints.GetUnitHeight()/2);
		mPoints.Draw(mShader);
	}
}

void MyGameApp::OnKeyPressed(Protocol::KeyPressedEvent& event)
{
	switch (event.GetKeyCode()) {
	case PROTOCOL_KEY_LEFT:
		//mHero.SetDirection(Unit::Direction::Left);
		break;
	case PROTOCOL_KEY_RIGHT:
		//mHero.SetDirection(Unit::Direction::Right);
		break;
	case PROTOCOL_KEY_DOWN:
		mHero.SetDirection(Unit::Direction::Down);
		break;
	case PROTOCOL_KEY_UP:
		mHero.SetDirection(Unit::Direction::Up);
		break;
	case PROTOCOL_KEY_SPACE:
		if (mHeroLevel >= 2) {
			mShot = true;
		}
		break;
	}
}
