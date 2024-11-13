#include "pch.h"


Gun::Gun() : mCapacity(10), mAmmo(10), mStateTab(0)
{
	IdleState* idle = new IdleState();
	ReloadingState* reload = new ReloadingState();
	ShootingState* shooting = new ShootingState();
	EmptyState* empty = new EmptyState();
	
	mStateTab.push_back(idle);
	mStateTab.push_back(reload);
	mStateTab.push_back(shooting);
	mStateTab.push_back(empty);
}

Gun::~Gun(){}

void Gun::Update(float dt)
{
	switch (mState)
	{
	case Gun::Idle:
		mStateTab[0]->Update(dt);
		break;
	case Gun::Shooting:
		mStateTab[2]->Update(dt);
		break;
	case Gun::Empty:
		mStateTab[3]->Update(dt);
		break;
	case Gun::Reloading:
		mStateTab[1]->Update(dt);
		break;
	default:
		break;
	}
}

bool Gun::SetState(eState newState)
{
	if (mTransitions[mState][newState] == 0)
		return (false);

	mState = newState;
	return (true);
}