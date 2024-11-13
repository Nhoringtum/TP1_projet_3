#include "pch.h"

ShootingState::ShootingState() : mShootProgress(0.f), mShootTime(0.f){}
ShootingState::~ShootingState(){}

void ShootingState::Start()
{
	if (gun.SetState(gun.eState::Shooting))
	{
		mShootProgress = 0.f;
		gun.mAmmo--;
		std::cout << "Bang! Ammo left: " << gun.mAmmo << std::endl;
	}
}
void ShootingState::Update(float deltaTime)
{
	mShootProgress += deltaTime;
	if (mShootProgress >= mShootTime)
	{
		if (gun.mAmmo <= 0)
			gun.SetState(gun.eState::Empty);
		else
			gun.SetState(gun.eState::Idle);
	}
}
