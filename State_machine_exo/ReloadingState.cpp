#include "pch.h"

ReloadingState::ReloadingState() : mReloadProgress(0.f), mReloadTime(2.f) {}
ReloadingState::~ReloadingState(){}

void ReloadingState::Start()
{
	if (gun->SetState(gun->eState::Reloading))
	{
		std::cout << "Reloading..." << std::endl;
		gun->mAmmo = gun->mCapacity;
	}
}
void ReloadingState::Update(float deltaTime)
{
	mReloadProgress += deltaTime;
	if (mReloadProgress >= mReloadTime)
	{
		gun->SetState(gun->eState::Idle);
		mReloadProgress = 0.f;
	}
}
