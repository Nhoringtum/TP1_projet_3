#include "Gun.h"
#include <iostream>

Gun::Gun()
	: mCapacity(10), mAmmo(10), mReloadTime(1.f), mShootTime(5.f), 
	mReloadProgress(0.f), mShootProgress(0.f){}

Gun::~Gun(){}

void Gun::Update(float dt)
{
	switch (mState)
	{
	case Gun::Idle:
		break;
	case Gun::Shooting:
		mShootProgress += dt;
		//std::cout << mShootProgress << std::endl;
		if (mShootProgress >= mShootTime)
		{
			if (mAmmo <= 0)
				SetState(State::Empty);
			else
				SetState(State::Idle);
		}
		break;
	case Gun::Empty:
		break;
	case Gun::Reloading:
		mReloadProgress += dt;
		if (mReloadProgress >= mReloadTime)
			SetState(State::Idle);
		break;
	default:
		break;
	}
}

void Gun::Shoot()
{
	if (SetState(State::Shooting))
	{
		mShootProgress = 0.f;
		mAmmo--;
		std::cout << "Bang! Ammo left: " << mAmmo << std::endl;
	}
}

void Gun::Reload()
{
	if (SetState(State::Reloading))
	{
		std::cout << "Reloading..." << std::endl;
		mReloadProgress = 0.f;
		mAmmo = mCapacity;
	}
}

bool Gun::SetState(State newState)
{
	if (mTransitions[mState][newState] == 0)
		return (false);

	mState = newState;
	return (true);
}