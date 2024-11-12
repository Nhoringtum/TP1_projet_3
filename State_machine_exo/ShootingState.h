#ifndef __SHOOTINGSTATE_H__
#define __SHOOTINGSTATE_H__
#include "State.h"

class ShootingState : public State
{
	ShootingState();
	~ShootingState();

	void Start();
	void Update();
};

#endif

