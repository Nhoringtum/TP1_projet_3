#ifndef __SHOOTINGSTATE_H__
#define __SHOOTINGSTATE_H__
#include "pch.h"


class ShootingState : public State
{
public:
	ShootingState();
	~ShootingState();

	void Start();
	void Update(float deltaTime);

private:
	float mShootTime;
	float mShootProgress;
};

#endif

